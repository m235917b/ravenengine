/*
 * CubeTest.cpp
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#include "Solid.hpp"
#include <CubeTest.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

CubeTest::CubeTest(float posX, float posY, float posZ)
    : Solid(posX, posY, posZ) {
  std::vector<GLfloat> v = getVertexData();
  std::vector<GLfloat> n = getNormalData();
  std::vector<GLfloat> t = getTexData();
  std::vector<GLuint> i = getIndexData();
  genBuffers(v, n, t, i);
  genTexture("tex/cube.png");
  fillTriangles(v, n, i);
  transformSphere(glm::translate(glm::vec3(posX, posY, posZ)));
  transformBoundingBox(glm::translate(glm::vec3(posX, posY, posZ)));
}

std::vector<GLfloat> CubeTest::getVertexData() {
  std::vector<GLfloat> v = {-1.0f, -1.0f, 1.0f,  1.0f,  -1.0f, 1.0f,
                            1.0f,  1.0f,  1.0f,  -1.0f, 1.0f,  1.0f,
                            -1.0f, -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f,
                            1.0f,  1.0f,  -1.0f, -1.0f, 1.0f,  -1.0f};
  return v;
}

std::vector<GLfloat> CubeTest::getNormalData() {
  std::vector<GLfloat> c = {0.583f, 0.771f, 0.014f, 0.609f, 0.115f, 0.436f,
                            0.327f, 0.483f, 0.844f, 0.822f, 0.569f, 0.201f,
                            0.435f, 0.602f, 0.223f, 0.310f, 0.747f, 0.185f,
                            0.597f, 0.770f, 0.761f, 0.559f, 0.436f, 0.730f};
  return c;
}

std::vector<GLfloat> CubeTest::getTexData() {
  std::vector<GLfloat> c = {0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
                            0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f};
  return c;
}

std::vector<GLuint> CubeTest::getIndexData() {
  std::vector<GLuint> i = {0, 1, 2, 0, 2, 3, 4, 0, 3, 4, 3, 7,
                           5, 4, 7, 5, 7, 6, 1, 5, 6, 1, 6, 2,
                           4, 5, 1, 4, 1, 0, 3, 2, 6, 3, 6, 7};

  return i;
}

void CubeTest::run() {
  pos += speed;
  setSpherePos(glm::vec4(pos, 1.0f));
  setBoundingBoxPos(glm::vec4(pos, 1.0f));
  speed += force;
}

void CubeTest::move(glm::vec3 dir) {
  if (glm::dot(dir, speed) < 0)
    speed += glm::dot(dir, -speed) * dir;
  // setSpherePos(glm::vec4(pos, 1.0f));
  // setBoundingBoxPos(glm::vec4(pos, 1.0f));
}

void CubeTest::clean() {
  speed *= .98f;
  force = glm::vec3(0.f, -.0f, .0f);
}

/*void CubeTest::run() {
  speed += force;
  pos += speed + glm::vec3(0.f, -.2f, 0.f);
  setSpherePos(glm::vec4(pos, 1.0f));
  setBoundingBoxPos(glm::vec4(pos, 1.0f));
}

void CubeTest::move(glm::vec3 dir) {
  speed += dir;//glm::dot(dir, -speed) * dir * 1.8f;
  // setSpherePos(glm::vec4(pos, 1.0f));
  // setBoundingBoxPos(glm::vec4(pos, 1.0f));
}

void CubeTest::clean() {
  speed *= .98f;
  force = glm::vec3(0.f);
}*/

void CubeTest::bounce(glm::vec3 v) {
  
}
