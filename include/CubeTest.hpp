/*
 * CubeTest.h
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#include <GL/glew.h>
#include <WorldObject.hpp>

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
