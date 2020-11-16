/*
 * Solid.hpp
 *
 *  Created on: Nov 5, 2020
 *      Author: marvi
 */

#ifndef SOLID_HPP_
#define SOLID_HPP_

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <WorldObject.hpp>
#include <ArrayVector2D.hpp>

namespace rpy {

typedef struct vertex_struct {
	glm::vec4 pos;
	glm::vec3 normal;
} vertex;

typedef struct triangle_struct {
	vertex *a;
	vertex *b;
	vertex *c;
	glm::vec3 n;
} triangle;

typedef struct sphere_struct {
	float rad;
	glm::vec4 pos;
} sphere;

class Solid : public WorldObject {
private:
	std::vector<vertex> vertices;
	std::vector<vertex> verticesLocal;
	std::vector<triangle> polygon;
	ArrayVector2D<int> solidsortx;
	ArrayVector2D<int> solidsorty;
	ArrayVector2D<int> solidsortz;
	ArrayVector2D<int> solidsort;
	std::vector<int> aux;
	sphere bs;

	inline void setSphere();

public:
	Solid(float posX, float posY, float posZ);
	~Solid();

	void fillTriangles(std::vector<GLfloat> &vertices,
			std::vector<GLfloat> &normals, std::vector<GLuint> &indices);

	sphere getSphere();

	void transformSphere(glm::mat4 m);

	void moveSphere(glm::vec4 v);

	void setSpherePos(glm::vec4 v);

	std::vector<triangle>& getPolygon();

	ArrayVector2D<int>& getSolidSortX();

	ArrayVector2D<int>& getSolidSortY();

	ArrayVector2D<int>& getSolidSortZ();

	ArrayVector2D<int>& getSolidSort();

	std::vector<int>& getAux();

	void updateVertices();
};

}

#endif /* SOLID_HPP_ */
