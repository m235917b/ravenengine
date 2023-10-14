/*
 * Floor.cpp
 *      Author: marvi
 */

#include <Floor.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <loadObject.hpp>

#include <iostream>

Floor::Floor(float posX, float posY, float posZ) : Solid(posX, posY, posZ) {
  auto data = loadSolid("obj/floor.txt");
  genBuffers(data.vertices, data.normals, data.texData, data.indices);
  genTexture("tex/cube.png");
  fillTriangles(data.vertices, data.normals, data.indices);
  transformSphere(glm::translate(glm::vec3(posX, posY, posZ)));
  transformBoundingBox(glm::translate(glm::vec3(posX, posY, posZ)));
}

void Floor::run() {}

void Floor::move(glm::vec3 dir) {}

void Floor::bounce(glm::vec3 v) {
  
}
