/*
 * ComposedObject.cpp
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#include <ComposedObject.h>
#include <algorithm>
#include <glm\gtx\rotate_vector.hpp>

ComposedObject::ComposedObject() :
		WorldObject(0.0f, 0.0f, 0.0f), meshes(), bones(), animations() {
}

ComposedObject::~ComposedObject() {

}

void ComposedObject::render(glm::mat4 &projection, glm::mat4 &view) {
	run();
	auto mod = glm::rotate(glm::translate(model, pos), angle, rot);
	std::for_each(meshes.begin(), meshes.end(),
			[&mod, &projection, &view, this](auto &obj) {
				obj.setModel(mod * obj.getModel());
				obj.render(projection, view);
				obj.setModel(glm::inverse(mod) * obj.getModel());
			});
}

void ComposedObject::run() {
}

