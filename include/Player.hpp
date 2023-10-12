/*
 * Player.hpp
 *
 *  Created on: Oct 26, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_PLAYER_HPP_
#define INCLUDE_PLAYER_HPP_

#include <glm/glm.hpp>
#include <Solid.hpp>

class Player : public rpy::Solid {
private:
	glm::vec3 lookAt;

protected:
	std::vector<GLfloat> getVertexData();
	std::vector<GLfloat> getNormalData();
	std::vector<GLfloat> getTexData();
	std::vector<GLuint> getIndexData();

public:

	Player();
	~Player();
	Player(const Player &that);
	Player& operator=(const Player &that);

	glm::vec3 getPos();
	glm::vec3 getLook();
	glm::vec3 getUp();

	void move(glm::vec3 dir) override;
	void moveForeward(float amount);
	void moveLeft(float amount);
	void rotateY(float angle);
	void rotateX(float angle);
	void run() override;
};

#endif /* INCLUDE_PLAYER_HPP_ */
