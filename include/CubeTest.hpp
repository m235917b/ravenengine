/*
 * CubeTest.h
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#ifndef TESTCUBE_H
#define TESTCUBE_H

#include <GL/glew.h>
#include <Solid.hpp>

class Cube: public rpy::Solid {
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
