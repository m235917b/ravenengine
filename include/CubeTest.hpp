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

class CubeTest: public rpy::Solid {
private:

protected:
	std::vector<GLfloat> getVertexData();
	std::vector<GLfloat> getNormalData();
	std::vector<GLfloat> getTexData();
	std::vector<GLuint> getIndexData();

public:
	CubeTest(float posX, float posY, float posZ);

	void move(glm::vec3 dir) override;
	void run() override;
};

#endif
