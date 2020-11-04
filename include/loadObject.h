/*
 * loadObject.h
 *
 *  Created on: Oct 31, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_LOADOBJECT_H_
#define INCLUDE_LOADOBJECT_H_

#include <vector>
#include <gl/glew.h>

struct objectData {
	std::vector<GLfloat> v;
	std::vector<GLfloat> n;
	std::vector<GLfloat> t;
	std::vector<GLuint> i;
};

typedef objectData objData;

std::vector<GLfloat> getVertices(const char *filename);

std::vector<GLfloat> getNormals(const char *filename);

std::vector<GLuint> getIndices(const char *filename);

std::vector<GLfloat> getTexCoords(const char *filename);

objData getObject(const char *filename);

#endif /* INCLUDE_LOADOBJECT_H_ */
