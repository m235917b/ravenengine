/*
 * NPCSimple.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: marvi
 */

#include <algorithm>
#include <glm/glm.hpp>
#include <loadObject.hpp>
#include <NPCSimple.hpp>

NPCSimple::NPCSimple(float posX, float posY, float posZ) :
		ComposedObject(posX, posY, posZ) {
	rot = glm::vec3(0.0f, 1.0f, 0.0f);
	auto obj = loadObject("obj/ttt.txt");
	std::for_each(obj.meshes.begin(), obj.meshes.end(), [this](auto &m) {
		m.loadTexture("tex/test1.png");
		meshes.push_back(m);
	});
}

void NPCSimple::run() {
	angle += 0.1f;
}

