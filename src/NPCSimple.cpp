/*
 * NPCSimple.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: marvi
 */

#include <NPCSimple.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <loadObject.h>

NPCSimple::NPCSimple(float posX, float posY, float posZ) :
		WorldObject(posX, posY, posZ) {
	rot = glm::vec3(0.0f, 1.0f, 0.0f);
	objData data = getObject("obj/ttt.obj");
	genBuffers(data.v, data.n, data.t, data.i);
	genTexture("tex/test.png");
}

std::vector<GLfloat> NPCSimple::getVertexData() {
	return getVertices("obj/untitled.obj");
}

std::vector<GLfloat> NPCSimple::getNormalData() {
	return getNormals("obj/untitled.obj");
}

std::vector<GLfloat> NPCSimple::getTexData() {
	return getTexCoords("obj/untitled.obj");
}

std::vector<GLuint> NPCSimple::getIndexData() {
	return getIndices("obj/untitled.obj");
}

void NPCSimple::run() {
	angle += 0.1f;
}

