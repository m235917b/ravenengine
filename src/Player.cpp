/*
 * Player.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: marvi
 */

#include <glm\gtx\rotate_vector.hpp>
#include <Player.hpp>

//constructor
Player::Player() :
		WorldObject(0.0f, 0.0f, 0.0f) {
	lookAt = glm::vec3(0.0f, 0.0f, -1.0f);
	std::vector<GLfloat> v = getVertexData();
	std::vector<GLfloat> n = getNormalData();
	std::vector<GLfloat> t = getTexData();
	std::vector<GLuint> i = getIndexData();
	genBuffers(v, n, t, i);
	genTexture("tex/test.png");
}

Player::~Player() {

}

Player::Player(const Player &that) :
		WorldObject(0.0f, 0.0f, 0.0f) {
	if (this != &that) {
		this->programID = that.programID;
		this->model = that.model;
		this->pos = that.pos;
		this->rot = that.rot;
		this->angle = that.angle;
		this->matrixID = that.matrixID;
		this->vertexarray = that.vertexarray;
		this->vertexbuffer = that.vertexbuffer;
		this->lookAt = that.lookAt;
		std::vector<GLfloat> v = getVertexData();
		std::vector<GLfloat> n = getNormalData();
		std::vector<GLfloat> t = getTexData();
		std::vector<GLuint> i = getIndexData();
		genBuffers(v, n, t, i);
	}
}

Player& Player::operator=(const Player &that) {
	if (this != &that) {
		this->programID = that.programID;
		this->model = that.model;
		this->pos = that.pos;
		this->rot = that.rot;
		this->angle = that.angle;
		this->matrixID = that.matrixID;
		this->vertexarray = that.vertexarray;
		this->vertexbuffer = that.vertexbuffer;
		this->lookAt = that.lookAt;
		std::vector<GLfloat> v = getVertexData();
		std::vector<GLfloat> n = getNormalData();
		std::vector<GLfloat> t = getTexData();
		std::vector<GLuint> i = getIndexData();
		genBuffers(v, n, t, i);
	}

	return *this;
}

std::vector<GLfloat> Player::getVertexData() {
	std::vector<GLfloat> v = { -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f,
			-1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f };
	return v;
}

std::vector<GLfloat> Player::getNormalData() {
	std::vector<GLfloat> c = { 0.583f, 0.771f, 0.014f, 0.609f, 0.115f, 0.436f,
			0.327f, 0.483f, 0.844f, 0.822f, 0.569f, 0.201f, 0.435f, 0.602f,
			0.223f, 0.310f, 0.747f, 0.185f, 0.597f, 0.770f, 0.761f, 0.559f,
			0.436f, 0.730f, 0.359f, 0.583f, 0.152f, 0.483f, 0.596f, 0.789f,
			0.559f, 0.861f, 0.639f, 0.195f, 0.548f, 0.859f, 0.014f, 0.184f,
			0.576f, 0.771f, 0.328f, 0.970f, 0.406f, 0.615f, 0.116f, 0.676f,
			0.977f, 0.133f, 0.971f, 0.572f, 0.833f, 0.140f, 0.616f, 0.489f,
			0.997f, 0.513f, 0.064f, 0.945f, 0.719f, 0.592f, 0.543f, 0.021f,
			0.978f, 0.279f, 0.317f, 0.505f, 0.167f, 0.620f, 0.077f, 0.347f,
			0.857f, 0.137f, 0.055f, 0.953f, 0.042f, 0.714f, 0.505f, 0.345f,
			0.783f, 0.290f, 0.734f, 0.722f, 0.645f, 0.174f, 0.302f, 0.455f,
			0.848f, 0.225f, 0.587f, 0.040f, 0.517f, 0.713f, 0.338f, 0.053f,
			0.959f, 0.120f, 0.393f, 0.621f, 0.362f, 0.673f, 0.211f, 0.457f,
			0.820f, 0.883f, 0.371f, 0.982f, 0.099f, 0.879f };
	return c;
}

std::vector<GLfloat> Player::getTexData() {
	std::vector<GLfloat> c = { 0.583f, 0.771f, 0.609f, 0.115f, 0.327f, 0.483f,
			0.822f, 0.569f, 0.435f, 0.602f, 0.310f, 0.747f, 0.185f, 0.770f,
			0.761f, 0.559f, 0.436f, 0.730f, 0.359f, 0.583f, 0.152f, 0.483f,
			0.596f, 0.789f, 0.559f, 0.861f, 0.639f, 0.195f, 0.548f, 0.859f,
			0.014f, 0.184f, 0.576f, 0.771f, 0.328f, 0.970f, 0.406f, 0.615f,
			0.116f, 0.676f, 0.977f, 0.133f, 0.971f, 0.572f, 0.833f, 0.140f,
			0.616f, 0.489f, 0.997f, 0.513f, 0.064f, 0.945f, 0.719f, 0.592f,
			0.543f, 0.021f, 0.978f, 0.279f, 0.317f, 0.505f, 0.167f, 0.620f,
			0.077f, 0.347f, 0.857f, 0.137f, 0.055f, 0.953f, 0.042f, 0.714f,
			0.505f, 0.345f };
	return c;
}

std::vector<GLuint> Player::getIndexData() {
	std::vector<GLuint> i = { 0, 1, 2, 0, 2, 3, 4, 0, 3, 4, 3, 7, 5, 4, 7, 5, 7,
			6, 1, 5, 6, 1, 6, 2, 4, 5, 1, 4, 1, 0, 3, 2, 6, 3, 6, 7 };

	return i;
}

glm::vec3 Player::getPos() {
	return pos;
}

glm::vec3 Player::getLook() {
	return lookAt;
}

glm::vec3 Player::getUp() {
	return rot;
}

void Player::move(glm::vec3 dir) {
	pos += dir;
}

void Player::moveForeward(float amount) {
	pos += amount * glm::vec3(lookAt.x, 0.0f, lookAt.z);
}

void Player::moveLeft(float amount) {
	pos += amount * glm::cross(glm::vec3(lookAt.x, 0.0f, lookAt.z), rot);
}

void Player::rotateX(float angle) {
	this->angle += angle;
	lookAt = glm::rotate(lookAt, angle, rot);
}

void Player::rotateY(float angle) {
	lookAt = glm::rotate(lookAt, angle, glm::cross(lookAt, rot));
}

