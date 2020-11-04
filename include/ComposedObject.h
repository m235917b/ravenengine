/*
 * ComposedObject.h
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#ifndef COMPOSEDOBJECT_H_
#define COMPOSEDOBJECT_H_

#include <Animation.h>
#include <Mesh.h>

struct cObj {
	std::vector<Mesh> meshes;
	std::vector<bone> bones;
	glm::mat4 arm_mat;
};

typedef cObj compObj;

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
	virtual ~ComposedObject();
	void render(glm::mat4 &projection, glm::mat4 &view);
};

#endif /* COMPOSEDOBJECT_H_ */
