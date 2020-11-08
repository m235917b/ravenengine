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

namespace rpy {

typedef struct triangle_struct {
	glm::vec3 a;
	glm::vec3 b;
	glm::vec3 c;
	glm::vec3 n;
} triangle;

typedef struct sphere_struct {
	float rad;
	glm::vec3 pos;
} sphere;

class Solid : public WorldObject {
private:
	std::vector<triangle> polygon;
	sphere bs;

	inline void setSphere();

public:
	Solid(float posX, float posY, float posZ);
	~Solid();

	void fillTriangles(std::vector<GLfloat> &vertices,
			std::vector<GLfloat> &normals, std::vector<GLuint> &indices);

	sphere getSphere();

	void transformSphere(glm::mat4 m);

	void moveSphere(glm::vec3 v);

	void setSpherePos(glm::vec3 v);
};

}

#endif /* SOLID_HPP_ */
