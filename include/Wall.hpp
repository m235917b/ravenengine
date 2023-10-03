/*
 * Wall.hpp
 * Author: marvi
 */

#ifndef WALL_H
#define WALL_H

#include <GL/glew.h>
#include <Solid.hpp>

class Wall: public rpy::Solid {
private:

protected:
	std::vector<GLfloat> getVertexData();
	std::vector<GLfloat> getNormalData();
	std::vector<GLfloat> getTexData();
	std::vector<GLuint> getIndexData();

	void run() override;

public:
	Wall(float posX, float posY, float posZ);

	void move(glm::vec3 dir) override;
};

#endif