/*
 * ComposedObject.h
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#ifndef COMPOSEDOBJECT_H_
#define COMPOSEDOBJECT_H_

#include "WorldObject.hpp"
#include <Animation.hpp>
#include <Mesh.hpp>

struct compObj_struct {
	std::vector<Mesh> meshes;
	std::vector<bone> bones;
	glm::mat4 arm_mat;
};

typedef compObj_struct compObj;

class ComposedObject : public WorldObject {
private:

protected:
	std::vector<Mesh> meshes;
	std::vector<bone> bones;
	glm::mat4 armature_world;
	std::vector<Animation> animations;

	virtual void run();

public:
	ComposedObject();
	ComposedObject(float posX, float posY, float posZ);
	virtual ~ComposedObject();
	void render(glm::mat4 &projection, glm::mat4 &view);
};

#endif /* COMPOSEDOBJECT_H_ */
