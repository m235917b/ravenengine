/*
 * Player.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: marvi
 */

#include "Solid.hpp"
#include <Player.hpp>
#include <glm/fwd.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <loadObject.hpp>

// constructor
Player::Player() : rpy::Solid(0.0f, 0.0f, 0.0f) {
  lookAt = glm::vec3(0.0f, 0.0f, -1.0f);
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
    // this->scal = that.scal;
    this->angle = that.angle;
    this->matrixID = that.matrixID;
    this->vertexarray = that.vertexarray;
    this->vertexbuffer = that.vertexbuffer;
    this->lookAt = that.lookAt;
    this->force = that.force;
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
    // this->scal = that.scal;
    this->angle = that.angle;
    this->matrixID = that.matrixID;
    this->vertexarray = that.vertexarray;
    this->vertexbuffer = that.vertexbuffer;
    this->lookAt = that.lookAt;
    this->force = that.force;
    auto data = loadSolid("obj/player.txt");
    genBuffers(data.vertices, data.normals, data.texData, data.indices);
  }

  return *this;
}

glm::vec3 Player::getPos() { return pos; }

glm::vec3 Player::getLook() { return lookAt; }

glm::vec3 Player::getUp() { return rot; }

void Player::move(glm::vec3 dir) {
  pos += dir;
  setSpherePos(glm::vec4(pos, 1.0f));
  setBoundingBoxPos(glm::vec4(pos, 1.0f));
}

template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }

void Player::moveForeward(float amount) {
  /*pos += amount * glm::vec3(lookAt.x, 0.0f, lookAt.z);
  setSpherePos(glm::vec4(pos, 1.0f));
  setBoundingBoxPos(glm::vec4(pos, 1.0f));*/
  speed += amount * glm::vec3(lookAt.x, 0.0f, lookAt.z);
}

void Player::moveLeft(float amount) {
  /*pos += amount * glm::cross(glm::vec3(lookAt.x, 0.0f, lookAt.z), rot);
  setSpherePos(glm::vec4(pos, 1.0f));
  setBoundingBoxPos(glm::vec4(pos, 1.0f));*/
  speed += amount * glm::cross(glm::vec3(lookAt.x, 0.0f, lookAt.z), rot);
}

void Player::rotateX(float angle) {
  this->angle += angle;
  lookAt = glm::rotate(lookAt, angle, rot);
}

void Player::rotateY(float angle) {
  lookAt = glm::rotate(lookAt, angle, glm::cross(lookAt, rot));
}

void Player::run() {
  // force += glm::vec3(0.f, -.2f, 0.f);
  pos += speed;
  setSpherePos(glm::vec4(pos, 1.0f));
  setBoundingBoxPos(glm::vec4(pos, 1.0f));
  // force = glm::vec3(0.f);
  // speed += force;
}

void Player::clean() {
  force = glm::vec3(0.f);
  // speed = glm::vec3(0.f);
}
