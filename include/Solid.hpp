/*
 * Solid.hpp
 *
 *  Created on: Nov 5, 2020
 *      Author: marvi
 */

#ifndef SOLID_HPP_
#define SOLID_HPP_

#include <ArrayVector2D.hpp>
#include <GL/glew.h>
#include <WorldObject.hpp>
#include <glm/glm.hpp>
#include <memory>
#include <vector>

namespace rpy {

typedef struct solidDataStruct {
  std::vector<GLfloat> vertices;
  std::vector<GLfloat> normals;
  std::vector<GLuint> indices;
  std::vector<GLfloat> texData;
} solidData;

typedef struct vertex_struct {
  glm::vec4 pos_loc;
  glm::vec4 pos;
  glm::vec3 normal;
} vertex;

typedef struct triangle_struct {
  unsigned int index;
  vertex *a;
  vertex *b;
  vertex *c;
  glm::vec3 n;
} triangle;

typedef struct sphere_struct {
  float rad;
  glm::vec4 pos;
} sphere;

typedef struct aabb_struct {
  glm::vec4 diagonal;
  glm::vec4 pos;
} aabb;

class Solid : public WorldObject {
private:
  std::vector<vertex> vertices;
  std::vector<vertex> verticesLocal;
  std::vector<triangle> polygon;
  ArrayVector2D<std::shared_ptr<triangle>> solidsorta;
  ArrayVector2D<std::shared_ptr<triangle>> solidsortb;
  ArrayVector2D<std::shared_ptr<triangle>> solidsortc;
  std::vector<std::shared_ptr<triangle>> aux;
  sphere bs;
  aabb bounding_box;

  inline void setSphere();

  inline void setBoundingBox();

public:
  Solid(float posX, float posY, float posZ);
  ~Solid();

  void fillTriangles(std::vector<GLfloat> &vertices,
                     std::vector<GLfloat> &normals,
                     std::vector<GLuint> &indices);

  sphere &getSphere();

  void transformSphere(glm::mat4 m);

  void moveSphere(glm::vec4 v);

  void setSpherePos(glm::vec4 v);

  aabb &getBoundingBox();

  void transformBoundingBox(glm::mat4 m);

  void moveBoundingBox(glm::vec4 v);

  void setBoundingBoxPos(glm::vec4 v);

  std::vector<triangle> &getPolygon();

  ArrayVector2D<std::shared_ptr<triangle>> &getSolidSortA();

  ArrayVector2D<std::shared_ptr<triangle>> &getSolidSortB();

  ArrayVector2D<std::shared_ptr<triangle>> &getSolidSortC();

  std::vector<std::shared_ptr<triangle>> &getAux();

  void updateVertices();

  void updateTriangle(std::shared_ptr<triangle> t);

  virtual void move(glm::vec3 dir);

  virtual void bounce(glm::vec3 v);

  void bounce2(glm::vec3 v);

  std::vector<vertex> &getVertices();
};

} // namespace rpy

#endif /* SOLID_HPP_ */
