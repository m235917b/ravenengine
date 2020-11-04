/*
 * AnimTest.cpp
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#include <AnimTest.hpp>
#include <algorithm>
#include <loadObject.hpp>

AnimTest::AnimTest() :
		ComposedObject() {
	auto obj = loadObject("obj/object.txt");

	armature_world = obj.arm_mat;

	std::for_each(obj.bones.begin(), obj.bones.end(), [this](auto &b) {
		bones.push_back(b);
	});

	std::for_each(obj.meshes.begin(), obj.meshes.end(), [this](auto &m) {
		meshes.push_back(m);
	});

	animations.push_back(
			Animation(bones, meshes, armature_world, 0.1f, "anim/anim.txt"));

	/*auto scale = glm::mat4(0.0f);
	 scale[0][0] = 1.0f;
	 scale[1][1] = 1.0f;
	 scale[2][2] = -1.0f;
	 scale[3][3] = 1.0f;

	 std::for_each(meshes.begin(), meshes.end(),
	 [](auto &m) {
	 m.setModel(
	 m.getModel()
	 * glm::scale(glm::mat4(1.0f),
	 glm::vec3(2.0f, 2.0f, 2.0f)));
	 m.setRestModel(m.getModel());
	 });

	 std::for_each(bones.begin(), bones.end(), [](auto &b) {
	 b->mat = glm::scale(b->mat, glm::vec3(2.0f, 2.0f, 2.0f));
	 });*/

	rot = glm::vec3(1.0f, 0.0f, 0.0f);

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

