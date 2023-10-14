/*
 * WorldObject.h
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_WORLDOBJECT_HPP_
#define INCLUDE_WORLDOBJECT_HPP_

#include <GL/glew.h>
#include <glm/detail/qualifier.hpp>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <string>
#include <vector>

class WorldObject {
private:
protected:
  GLuint programID;
  GLuint matrixID;
  GLuint textureID;
  GLuint vertexbuffer;
  GLuint normalbuffer;
  GLuint texbuffer;
  GLuint indexbuffer;
  GLuint vertexarray;
  int vertexCount;

  glm::vec3 pos;
  glm::vec3 pos_old;
  glm::vec3 rot;
  glm::vec3 scal;
  glm::mat4 model;
  glm::mat4 objectspaceTrans;
  float angle;

  glm::vec3 force;
  glm::vec3 speed;

  void genBuffers(std::vector<GLfloat> &vertexData,
                  std::vector<GLfloat> &normalData,
                  std::vector<GLfloat> &texData,
                  std::vector<GLuint> &indexData);

  void genTexture(std::string filename);

public:
  WorldObject(float posX, float posY, float posZ);
  virtual ~WorldObject();

  void move(glm::vec3 dist);

  virtual void run();

  virtual void render(glm::mat4 &projection, glm::mat4 &view);

  virtual void clean();

  glm::vec3 getPos();
  glm::vec3 getRot();
  glm::vec3 getScal();
  glm::mat4 getModel();
  float getAngle();
  virtual bool isMoving();
};

#endif /* INCLUDE_WORLDOBJECT_HPP_ */
