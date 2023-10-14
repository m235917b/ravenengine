/*
 * Floor.hpp
 * Author: marvi
 */

#ifndef FLOOR_H
#define FLOOR_H

#include <GL/glew.h>
#include <Solid.hpp>

class Floor: public rpy::Solid {
private:

protected:
	std::vector<GLfloat> getVertexData();
	std::vector<GLfloat> getNormalData();
	std::vector<GLfloat> getTexData();
	std::vector<GLuint> getIndexData();

public:
	Floor(float posX, float posY, float posZ);

	void move(glm::vec3 dir) override;
	void run() override;
	void bounce(glm::vec3 v) override;
};

#endif