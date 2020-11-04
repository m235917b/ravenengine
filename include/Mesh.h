/*
 * Mesh.h
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#ifndef MESH_H_
#define MESH_H_

#include <WorldObject.h>
#include <string>

class Mesh: public WorldObject {
private:
	std::string name;
	std::vector<int> bones;
	glm::mat4 rest_model;

public:
	Mesh(std::vector<GLfloat> &vertexData, std::vector<GLfloat> &normalData,
			std::vector<GLfloat> &texData, std::vector<GLuint> &indexData,
			std::string tex, std::string name);
	~Mesh();

	std::vector<int>& getBones();
	void addBone(int bone_id);
	glm::mat4 getModel();
	void setModel(glm::mat4 mat);
	void setRestModel(glm::mat4 mat);
	std::string getName() const;
	void resetModel();
};

#endif /* MESH_H_ */
