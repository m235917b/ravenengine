/*
 * CubeTest.cpp
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#include <Wall.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <loadObject.hpp>

#include <iostream>

Wall::Wall(float posX, float posY, float posZ) : Solid(posX, posY, posZ) {
  std::vector<GLfloat> v = getVertexData();
  std::vector<GLfloat> n = getNormalData();
  std::vector<GLfloat> t = getTexData();
  std::vector<GLuint> i = getIndexData();
  auto data = loadSolid("obj/wall.txt");
  genBuffers(data.vertices, data.normals, data.texData, data.indices);
  // genBuffers(v, n, t, i);
  genTexture("tex/cube.png");
  fillTriangles(data.vertices, data.normals, data.indices);
  // fillTriangles(v, n, i);
  transformSphere(glm::translate(glm::vec3(posX, posY, posZ)));
  transformBoundingBox(glm::translate(glm::vec3(posX, posY, posZ)));
}

std::vector<GLfloat> Wall::getVertexData() {
  std::vector<GLfloat> v = {-1.0f, -1.0f, 1.0f,  1.0f,  -1.0f, 1.0f,
                            1.0f,  1.0f,  1.0f,  -1.0f, 1.0f,  1.0f,
                            -1.0f, -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f,
                            1.0f,  1.0f,  -1.0f, -1.0f, 1.0f,  -1.0f};
  return v;
}

std::vector<GLfloat> Wall::getNormalData() {
  std::vector<GLfloat> c = {0.583f, 0.771f, 0.014f, 0.609f, 0.115f, 0.436f,
                            0.327f, 0.483f, 0.844f, 0.822f, 0.569f, 0.201f,
                            0.435f, 0.602f, 0.223f, 0.310f, 0.747f, 0.185f,
                            0.597f, 0.770f, 0.761f, 0.559f, 0.436f, 0.730f};
  return c;
}

std::vector<GLfloat> Wall::getTexData() {
  std::vector<GLfloat> c = {0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
                            0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f};
  return c;
}

std::vector<GLuint> Wall::getIndexData() {
  std::vector<GLuint> i = {0, 1, 2, 0, 2, 3, 4, 0, 3, 4, 3, 7,
                           5, 4, 7, 5, 7, 6, 1, 5, 6, 1, 6, 2,
                           4, 5, 1, 4, 1, 0, 3, 2, 6, 3, 6, 7};

  return i;
}

void Wall::run() {}

void Wall::move(glm::vec3 dir) {
  // exit(0);
}
