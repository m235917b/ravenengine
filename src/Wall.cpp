/*
 * CubeTest.cpp
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#include <Wall.hpp>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <loadObject.hpp>

#include <iostream>

Wall::Wall(float posX, float posY, float posZ) : Solid(posX, posY, posZ) {
  auto data = loadSolid("obj/wall.txt");
  genBuffers(data.vertices, data.normals, data.texData, data.indices);
  genTexture("tex/cube.png");
  fillTriangles(data.vertices, data.normals, data.indices);
  transformSphere(glm::translate(glm::vec3(posX, posY, posZ)));
  transformBoundingBox(glm::translate(glm::vec3(posX, posY, posZ)));
}

void Wall::run() {
  pos += force + glm::vec3(0.f, -.5f, 0.f);
  setSpherePos(glm::vec4(pos, 1.0f));
  setBoundingBoxPos(glm::vec4(pos, 1.0f));
}

void Wall::move(glm::vec3 dir) {
  force += dir;
}

void Wall::clean() {
	force -= force * .02f;
  pos_old = pos;
}

/*void Wall::run() {
  speed += force + glm::vec3(0.f, -.3f, .0f);
  if (pos.y + speed.y < 0.f) {
    pos.y = 0.f;
    speed += glm::vec3(0.f, 10.f, 0.f);
  }
  pos += speed; // + glm::vec3(0.f, -.2f, 0.f);
  setSpherePos(glm::vec4(pos, 1.0f));
  setBoundingBoxPos(glm::vec4(pos, 1.0f));
}

void Wall::move(glm::vec3 dir) {
  speed += dir;//glm::dot(dir, -speed) * dir * 1.8f;
  // setSpherePos(glm::vec4(pos, 1.0f));
  // setBoundingBoxPos(glm::vec4(pos, 1.0f));
}

void Wall::clean() {
  speed *= .98f;
  force = glm::vec3(0.f);
}*/
