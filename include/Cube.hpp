/*
 * Cube.h
 */

#ifndef CUBE_H
#define CUBE_H

#include <WorldObject.hpp>
#include <GL/glew.h>

class CubeWorld: public WorldObject {
private:

protected:
	std::vector<GLfloat> getVertexData();
	std::vector<GLfloat> getNormalData();
	std::vector<GLfloat> getTexData();
	std::vector<GLuint> getIndexData();

	void run() override;

public:
	CubeWorld(float posX, float posY, float posZ);
};

#endif
