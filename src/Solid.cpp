/*
 * Solid.cpp
 *
 *  Created on: Nov 5, 2020
 *      Author: marvi
 */

#include <Solid.hpp>
#include <algorithm>
#include <glm/geometric.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <memory>

#include <iostream>

using namespace rpy;

Solid::Solid(float posX, float posY, float posZ)
    : WorldObject(posX, posY, posZ) {}

Solid::~Solid() {}

inline void Solid::setSphere() {
  // approximate the polygon radius
  auto dist = 0.0f;
  auto dist_old = 0.0f;
  auto point1 = polygon.front().a->pos;
  auto point2 = polygon.front().a->pos;

  do {
    dist = 0.0f;
    dist_old = glm::distance(point1, point2);
    point1 = point2;
    for (auto i = polygon.size() - 1; i > 0; --i) {
      auto point = polygon.at(i).a->pos;
      if (glm::distance(point1, point) > dist) {
        dist = glm::distance(point1, point);
        point2 = point;
      }
      point = polygon.at(i).b->pos;
      if (glm::distance(point1, point) > dist) {
        dist = glm::distance(point1, point);
        point2 = point;
      }
      point = polygon.at(i).c->pos;
      if (glm::distance(point1, point) > dist) {
        dist = glm::distance(point1, point);
        point2 = point;
      }
    }
  } while (dist_old < dist);

  bs.rad = glm::distance(point1, point2) / 2.0f;
  bs.pos = point1 + (point2 - point1) / 2.0f;
  bs.pos.w = 1.0f;
}

inline void Solid::setBoundingBox() {
  // calculate aabb
  auto point = polygon.front().a->pos;
  auto min_x = point.x;
  auto max_x = point.x;
  auto min_y = point.y;
  auto max_y = point.y;
  auto min_z = point.z;
  auto max_z = point.z;

  for (unsigned int i = 0; i < polygon.size(); ++i) {
    point = polygon.at(i).a->pos;

    if (point.x < min_x) {
      min_x = point.x;
    } else if (point.x > max_x) {
      max_x = point.x;
    }

    if (point.y < min_y) {
      min_y = point.y;
    } else if (point.y > max_y) {
      max_y = point.y;
    }

    if (point.z < min_z) {
      min_z = point.z;
    } else if (point.z > max_z) {
      max_z = point.z;
    }

    point = polygon.at(i).b->pos;

    if (point.x < min_x) {
      min_x = point.x;
    } else if (point.x > max_x) {
      max_x = point.x;
    }

    if (point.y < min_y) {
      min_y = point.y;
    } else if (point.y > max_y) {
      max_y = point.y;
    }

    if (point.z < min_z) {
      min_z = point.z;
    } else if (point.z > max_z) {
      max_z = point.z;
    }

    point = polygon.at(i).c->pos;

    if (point.x < min_x) {
      min_x = point.x;
    } else if (point.x > max_x) {
      max_x = point.x;
    }

    if (point.y < min_y) {
      min_y = point.y;
    } else if (point.y > max_y) {
      max_y = point.y;
    }

    if (point.z < min_z) {
      min_z = point.z;
    } else if (point.z > max_z) {
      max_z = point.z;
    }
  }

  bounding_box.pos =
      glm::vec4(min_x + (max_x - min_x) / 2.f, min_y + (max_y - min_y) / 2.f,
                min_z + (max_z - min_z) / 2.f, 1.f);
  bounding_box.diagonal = glm::vec4(
      (max_x - min_x) / 2.f, (max_y - min_y) / 2.f, (max_z - min_z) / 2.f, 0.f);
}

void Solid::fillTriangles(std::vector<GLfloat> &vertices,
                          std::vector<GLfloat> &normals,
                          std::vector<GLuint> &indices) {
  for (unsigned int i = 0; i < vertices.size(); i += 3) {
    auto v = vertex();

    v.pos.x = vertices.at(i);
    v.pos.y = vertices.at(i + 1);
    v.pos.z = vertices.at(i + 2);
    v.pos.w = 1.0f;

    v.pos_loc.x = vertices.at(i);
    v.pos_loc.y = vertices.at(i + 1);
    v.pos_loc.z = vertices.at(i + 2);
    v.pos_loc.w = 1.0f;

    v.normal.x = normals.at(i);
    v.normal.y = normals.at(i + 1);
    v.normal.z = normals.at(i + 1);

    this->vertices.emplace_back(v);
    this->verticesLocal.emplace_back(v);
  }

  for (unsigned int i = 0; i < indices.size(); i += 3) {
    auto t = triangle();

    t.a = &this->vertices.at(indices.at(i));
    t.b = &this->vertices.at(indices.at(i + 1));
    t.c = &this->vertices.at(indices.at(i + 2));

    /*auto n1 = this->vertices.at(indices.at(i)).normal;
    auto n2 = this->vertices.at(indices.at(i + 1)).normal;
    auto n3 = this->vertices.at(indices.at(i + 2)).normal;
    t.n = glm::normalize(n1 + n2 + n3);*/

    t.n = glm::normalize(glm::cross(glm::vec3(t.b->pos - t.a->pos),
                                    glm::vec3(t.c->pos - t.a->pos)));

    polygon.emplace_back(t);
  }

  setSphere();
  setBoundingBox();

  solidsorta = ArrayVector2D<std::shared_ptr<triangle>>(polygon.size());
  solidsortb = ArrayVector2D<std::shared_ptr<triangle>>(polygon.size());
  solidsortc = ArrayVector2D<std::shared_ptr<triangle>>(polygon.size());
  aux = std::vector<std::shared_ptr<triangle>>(polygon.size());

  for (triangle &t : polygon) {
    solidsorta.push_back(std::make_shared<triangle>(t));
  }
}

sphere &Solid::getSphere() { return bs; }

void Solid::transformSphere(glm::mat4 m) { bs.pos = m * bs.pos; }

void Solid::moveSphere(glm::vec4 v) { bs.pos += v; }

void Solid::setSpherePos(glm::vec4 v) { bs.pos = v; }

aabb &Solid::getBoundingBox() { return bounding_box; }

void Solid::transformBoundingBox(glm::mat4 m) {
  bounding_box.pos = m * bounding_box.pos;
}

void Solid::moveBoundingBox(glm::vec4 v) { bounding_box.pos += v; }

void Solid::setBoundingBoxPos(glm::vec4 v) { bounding_box.pos = v; }

std::vector<triangle> &Solid::getPolygon() { return polygon; }

ArrayVector2D<std::shared_ptr<triangle>> &Solid::getSolidSortA() {
  return solidsorta;
}

ArrayVector2D<std::shared_ptr<triangle>> &Solid::getSolidSortB() {
  return solidsortb;
}

ArrayVector2D<std::shared_ptr<triangle>> &Solid::getSolidSortC() {
  return solidsortc;
}

std::vector<std::shared_ptr<triangle>> &Solid::getAux() { return aux; }

void Solid::updateVertices() {
  auto mat =
      glm::rotate(glm::scale(glm::translate(model, pos), scal), angle, rot) *
      objectspaceTrans;

  for (unsigned int i = 0; i < vertices.size(); ++i) {
    vertices.at(i).pos = mat * vertices.at(i).pos_loc;
  }
}

void Solid::updateTriangle(std::shared_ptr<triangle> t) {
  auto mat =
      glm::rotate(glm::scale(glm::translate(model, pos), scal), angle, rot) *
      objectspaceTrans;

  t->a->pos = mat * t->a->pos_loc;
  t->b->pos = mat * t->b->pos_loc;
  t->c->pos = mat * t->c->pos_loc;

  /*v->pos = mat *

  for (unsigned int i = 0; i < verticesLocal.size(); ++i) {
    vertices.at(i).pos = mat * verticesLocal.at(i).pos;
  }*/
}

void Solid::move(glm::vec3 dir) {
  // pos += dir;
  // setSpherePos(glm::vec4(pos, 1.0f));
}

void Solid::bounce(glm::vec3 dir) {
  if (force.x == 0.f && force.y == 0.f && force.z == 0.f)
    return;
  pos -= glm::dot(dir, force) * dir;
  setSpherePos(glm::vec4(pos, 1.0f));
  setBoundingBoxPos(glm::vec4(pos, 1.0f));
  // if (dir.x != 0.f || dir.y != 0.f || dir.z != 0.f)
  // exit(0);
  // force += dir;
}

void Solid::bounce2(glm::vec3 v) {
  if (force.x == 0.f && force.y == 0.f && force.z == 0.f)
    return;
  pos -= glm::dot(v, force) * v;
  setSpherePos(glm::vec4(pos, 1.0f));
  setBoundingBoxPos(glm::vec4(pos, 1.0f));
  // if (dir.x != 0.f || dir.y != 0.f || dir.z != 0.f)
  // exit(0);
  // force += dir;
}

std::vector<vertex> &Solid::getVertices() { return vertices; }
