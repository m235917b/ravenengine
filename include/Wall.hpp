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

public:
	Wall(float posX, float posY, float posZ);

	void move(glm::vec3 dir) override;
	void run() override;
	void clean() override;
};

#endif