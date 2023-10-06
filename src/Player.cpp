/*
 * Player.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: marvi
 */

#include "Solid.hpp"
#include <Player.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <loadObject.hpp>

// constructor
Player::Player() : rpy::Solid(0.0f, 0.0f, 0.0f) {
  lookAt = glm::vec3(0.0f, 0.0f, -1.0f);
  std::vector<GLfloat> v = getVertexData();
  std::vector<GLfloat> n = getNormalData();
  std::vector<GLfloat> t = getTexData();
  std::vector<GLuint> i = getIndexData();
  auto data = loadSolid("obj/player.txt");
  genBuffers(data.vertices, data.normals, data.texData, data.indices);
  genTexture("tex/test.png");
  fillTriangles(data.vertices, data.normals, data.indices);
}

Player::~Player() {}

Player::Player(const Player &that) : rpy::Solid(0.0f, 0.0f, 0.0f) {
  if (this != &that) {
    this->programID = that.programID;
    this->model = that.model;
    this->pos = that.pos;
    this->rot = that.rot;
    this->angle = that.angle;
    this->matrixID = that.matrixID;
    this->vertexarray = that.vertexarray;
    this->vertexbuffer = that.vertexbuffer;
    this->lookAt = that.lookAt;
    std::vector<GLfloat> v = getVertexData();
    std::vector<GLfloat> n = getNormalData();
    std::vector<GLfloat> t = getTexData();
    std::vector<GLuint> i = getIndexData();
    auto data = loadSolid("obj/player.txt");
    genBuffers(data.vertices, data.normals, data.texData, data.indices);
  }
}

Player &Player::operator=(const Player &that) {
  if (this != &that) {
    this->programID = that.programID;
    this->model = that.model;
    this->pos = that.pos;
    this->rot = that.rot;
    this->angle = that.angle;
    this->matrixID = that.matrixID;
    this->vertexarray = that.vertexarray;
    this->vertexbuffer = that.vertexbuffer;
    this->lookAt = that.lookAt;
    std::vector<GLfloat> v = getVertexData();
    std::vector<GLfloat> n = getNormalData();
    std::vector<GLfloat> t = getTexData();
    std::vector<GLuint> i = getIndexData();
    auto data = loadSolid("obj/player.txt");
    genBuffers(data.vertices, data.normals, data.texData, data.indices);
  }

  return *this;
}

std::vector<GLfloat> Player::getVertexData() {
  std::vector<GLfloat> v = {-1.0f, -1.0f, 1.0f,  1.0f,  -1.0f, 1.0f,
                            1.0f,  1.0f,  1.0f,  -1.0f, 1.0f,  1.0f,
                            -1.0f, -1.0f, -1.0f, 1.0f,  -1.0f, -1.0f,
                            1.0f,  1.0f,  -1.0f, -1.0f, 1.0f,  -1.0f};
  return v;
}

std::vector<GLfloat> Player::getNormalData() {
  std::vector<GLfloat> c = {0.583f, 0.771f, 0.014f, 0.609f, 0.115f, 0.436f,
                            0.327f, 0.483f, 0.844f, 0.822f, 0.569f, 0.201f,
                            0.435f, 0.602f, 0.223f, 0.310f, 0.747f, 0.185f,
                            0.597f, 0.770f, 0.761f, 0.559f, 0.436f, 0.730f};
  return c;
}

std::vector<GLfloat> Player::getTexData() {
  std::vector<GLfloat> c = {0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
                            0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f};
  return c;
}

std::vector<GLuint> Player::getIndexData() {
  std::vector<GLuint> i = {0, 1, 2, 0, 2, 3, 4, 0, 3, 4, 3, 7,
                           5, 4, 7, 5, 7, 6, 1, 5, 6, 1, 6, 2,
                           4, 5, 1, 4, 1, 0, 3, 2, 6, 3, 6, 7};

  return i;
}

glm::vec3 Player::getPos() { return pos; }

glm::vec3 Player::getLook() { return lookAt; }

glm::vec3 Player::getUp() { return rot; }

void Player::move(glm::vec3 dir) {
  pos += dir;
  setSpherePos(glm::vec4(pos, 1.0f));
}

template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }

void Player::moveForeward(float amount) {
  pos += amount * glm::vec3(lookAt.x, 0.0f, lookAt.z);
  setSpherePos(glm::vec4(pos, 1.0f));
  /*this->objectspaceTrans =
      glm::rotate(this->objectspaceTrans, sgn(amount) * -0.2f,
                  glm::vec3(1.f, 0.f, 0.f));*/
}

void Player::moveLeft(float amount) {
  pos += amount * glm::cross(glm::vec3(lookAt.x, 0.0f, lookAt.z), rot);
  setSpherePos(glm::vec4(pos, 1.0f));
  /*this->objectspaceTrans =
      glm::rotate(this->objectspaceTrans, sgn(amount) * -0.2f,
                  glm::vec3(0.f, 0.f, 1.f));*/
}

void Player::rotateX(float angle) {
  this->angle += angle;
  lookAt = glm::rotate(lookAt, angle, rot);
}

void Player::rotateY(float angle) {
  lookAt = glm::rotate(lookAt, angle, glm::cross(lookAt, rot));
}
