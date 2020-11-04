#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include <WorldObject.h>

#ifndef TESTCUBE_H
#define TESTCUBE_H

class Cube: public WorldObject {
private:

protected:
	std::vector<GLfloat> getVertexData();
	std::vector<GLfloat> getNormalData();
	std::vector<GLfloat> getTexData();
	std::vector<GLuint> getIndexData();

	void run();

public:
	Cube(float posX, float posY, float posZ);
};

#endif
