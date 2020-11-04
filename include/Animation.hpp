/*
 * animation.h
 *
 *  Created on: Nov 2, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_ANIMATION_HPP_
#define INCLUDE_ANIMATION_HPP_

#include <string>
#include <glm/glm.hpp>
#include <map>
#include <vector>
#include <glm/gtx/quaternion.hpp>
#include <Mesh.hpp>

struct keyframe_struct {
	glm::quat rot;
	glm::vec3 trans;
	glm::vec3 scal;
};

typedef keyframe_struct keyframe;

struct bone_struct {
	std::string name;
	int parent = -1;
	glm::mat4 mat;
};

typedef bone_struct bone;

class Animation {
private:
	std::vector<bone> *bones;
	std::vector<Mesh> *meshes;
	std::vector<int> keyframe_ids;
	const glm::mat4 *armature_world;
	std::map<std::string, std::map<int, keyframe>> keyframes;
	float speed;
	bool is_running;
	float frame;
	int lowKeyframe;

	glm::mat4 interpolate(glm::quat rotation_begin, glm::vec3 translation_begin,
			glm::vec3 scale_begin, glm::quat rotation_target,
			glm::vec3 translation_target, glm::vec3 scale_target, int span,
			float frame);

protected:

public:
	Animation(std::vector<bone> &bones, std::vector<Mesh> &meshes,
			const glm::mat4 &armature_world_matrix, const float speed,
			std::string filename);
	~Animation();

	void start();
	void end();
	void stop();
	void play();
	void update();
};

#endif /* INCLUDE_ANIMATION_HPP_ */
