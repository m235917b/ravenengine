/*
 * Solid.cpp
 *
 *  Created on: Nov 5, 2020
 *      Author: marvi
 */

#include <Solid.hpp>
#include <algorithm>
#include <glm/gtx/rotate_vector.hpp>
#include <memory>

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

void Solid::fillTriangles(std::vector<GLfloat> &vertices,
                          std::vector<GLfloat> &normals,
                          std::vector<GLuint> &indices) {
  for (unsigned int i = 0; i < vertices.size(); i += 3) {
    auto v = vertex();

    v.pos.x = vertices.at(i);
    v.pos.y = vertices.at(i + 1);
    v.pos.z = vertices.at(i + 2);
    v.pos.w = 1.0f;

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

    auto n1 = this->vertices.at(indices.at(i)).normal;
    auto n2 = this->vertices.at(indices.at(i + 1)).normal;
    auto n3 = this->vertices.at(indices.at(i + 2)).normal;

    t.n = (n1 + n2 + n3) / 3.0f;

    polygon.emplace_back(t);
  }

  setSphere();

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
      objectspaceTrans *
      glm::rotate(glm::scale(glm::translate(model, pos), scal), angle, rot);

  for (unsigned int i = 0; i < verticesLocal.size(); ++i) {
    vertices.at(i).pos = mat * verticesLocal.at(i).pos;
  }
}
