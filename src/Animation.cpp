/*
 * animation.cpp
 *
 *  Created on: Nov 3, 2020
 *      Author: marvi
 */

#include <algorithm>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <loadObj.h>
#include <Animation.h>

Animation::Animation(std::vector<bone> &bones, std::vector<Mesh> &meshes,
		const glm::mat4 &armature_world_matrix, const float speed,
		std::string filename) :
		bones(&bones), meshes(&meshes), keyframe_ids(), armature_world(
				&armature_world_matrix), speed(speed), is_running(false), frame(
				0), lowKeyframe(0) {

	std::ifstream file(filename);
	std::string str;

	while (std::getline(file, str)) {
		if (str.find("b ", 0) == 0) {
			auto boneId = findElem<bone>(bones, [&str](const bone &b) {
				return b.name == str.substr(2, str.length());
			});

			auto mat = glm::mat4();
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					std::getline(file, str);
					mat[i][j] = std::stof(str);
				}
			}
			auto r = glm::quat();
			auto t = glm::vec3();
			auto s = glm::vec3();
			auto sk = glm::vec3();
			auto p = glm::vec4();
			glm::decompose(mat, s, r, t, sk, p);
			auto keyf = keyframe();
			keyf.rot = r;
			keyf.trans = t;
			keyf.scal = s;
			keyframes.insert(
					std::pair<std::string, std::map<int, keyframe>>(
							bones.at(boneId).name, std::map<int, keyframe>()));
			keyframes[bones.at(boneId).name].insert(
					std::pair<int, keyframe>(frame, keyf));
		} else if (str.find("f", 0) == 0) {
			frame = std::stoi(str.substr(1, str.length()));
			keyframe_ids.push_back((int) frame);
		}
	}
}

Animation::~Animation() {

}

glm::mat4 Animation::interpolate(glm::quat rotation_begin,
		glm::vec3 translation_begin, glm::vec3 scale_begin,
		glm::quat rotation_target, glm::vec3 translation_target,
		glm::vec3 scale_target, int span, float frame) {
	frame -= keyframe_ids.at(lowKeyframe);
	auto r = rotation_begin
			+ (rotation_target - rotation_begin) * (float) frame / (float) span;
	auto t = translation_begin
			+ (translation_target - translation_begin) * (float) frame
					/ (float) span;
	auto s = scale_begin
			+ (scale_target - scale_begin) * (float) frame / (float) span;

	return glm::toMat4(r) * glm::translate(glm::scale(glm::mat4(1.0f), s), t);
}

void Animation::start() {
	frame = keyframe_ids.at(0);
	lowKeyframe = 0;
	is_running = true;
}

void Animation::end() {
	frame = keyframe_ids.at(0);
	lowKeyframe = 0;
	is_running = false;
}

void Animation::stop() {
	is_running = false;
}

void Animation::play() {
	is_running = true;
}

void Animation::update() {
	if (is_running) {
		std::for_each(meshes->begin(), meshes->end(), [this](auto &m) {
			m.resetModel();

			m.setModel(glm::inverse(*armature_world) * m.getModel());
			const auto list = m.getBones();
			std::for_each(list.begin(), list.end(), [this, &m](const auto b) {
				auto parent = b;
				do {
					m.setModel(glm::inverse(bones->at(parent).mat) * m.getModel());
					m.setModel(interpolate(keyframes[bones->at(parent).name][keyframe_ids.at(lowKeyframe)].rot,
							keyframes[bones->at(parent).name][keyframe_ids.at(lowKeyframe)].trans,
							keyframes[bones->at(parent).name][keyframe_ids.at(lowKeyframe)].scal,
							keyframes[bones->at(parent).name][keyframe_ids.at(lowKeyframe + 1)].rot,
							keyframes[bones->at(parent).name][keyframe_ids.at(lowKeyframe + 1)].trans,
							keyframes[bones->at(parent).name][keyframe_ids.at(lowKeyframe + 1)].scal,
							keyframe_ids.at(lowKeyframe + 1)
							- keyframe_ids.at(lowKeyframe), frame)
							* m.getModel());
					m.setModel(bones->at(parent).mat * m.getModel());
					parent = bones->at(parent).parent;
				} while (parent >= 0);
			});

			m.setModel(*armature_world * m.getModel());
		});

		frame += speed;

		if (frame > keyframe_ids.at(lowKeyframe + 1)) {
			if ((int) keyframe_ids.size() > lowKeyframe + 2) {
				++lowKeyframe;
			} else {
				end();
			}
		}
	}
}

