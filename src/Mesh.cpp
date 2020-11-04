/*
 * Mesh.cpp
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#include <Mesh.hpp>

Mesh::Mesh() : WorldObject(0.0f, 0.0f, 0.0f), name(), bones(), rest_model() {

}

Mesh::Mesh(std::vector<GLfloat> &vertexData, std::vector<GLfloat> &normalData,
		std::vector<GLfloat> &texData, std::vector<GLuint> &indexData,
		std::string tex, std::string name) :
		WorldObject(0.0f, 0.0f, 0.0f), name(name), bones(), rest_model(model) {
	genTexture("tex/test.png");
	genBuffers(vertexData, normalData, texData, indexData);
}

Mesh::~Mesh() {

}

std::vector<int>& Mesh::getBones() {
	return bones;
}

void Mesh::addBone(int bone_id) {
	bones.push_back(bone_id);
}

glm::mat4 Mesh::getModel() {
	return model;
}

void Mesh::setModel(glm::mat4 mat) {
	model = mat;
}

void Mesh::setRestModel(glm::mat4 mat) {
	rest_model = mat;
}

std::string Mesh::getName() const {
	return name;
}

void Mesh::resetModel() {
	model = rest_model;
}

void Mesh::transform(glm::mat4 mat) {
	model = model * mat;
}

void Mesh::loadTexture(std::string filename) {
	genTexture(filename);
}

