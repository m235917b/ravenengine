/*
 * AnimTest.cpp
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#include <AnimTest.hpp>
#include <algorithm>
#include <loadObject.hpp>
#include <math.h>

AnimTest::AnimTest(float posX, float posY, float posZ) :
		ComposedObject(posX, posY, posZ) {
	auto obj = loadObject("obj/object1.txt");

	armature_world = obj.arm_mat;

	std::for_each(obj.bones.begin(), obj.bones.end(), [this](auto &b) {
		bones.push_back(b);
	});

	std::for_each(obj.meshes.begin(), obj.meshes.end(), [this](auto &m) {
		meshes.push_back(m);
	});

	animations.push_back(
			Animation(bones, meshes, armature_world, 0.1f, "anim/anim1.txt"));

	rot = glm::vec3(1.0f, 0.0f, 0.0f);
	scal = glm::vec3(30.0f, 30.0f, 30.0f);
	angle = -1.6f;

	animations.front().start();
}

AnimTest::~AnimTest() {

}

void AnimTest::run() {
	std::for_each(animations.begin(), animations.end(), [](auto &a) {
		a.update();
	});
}

