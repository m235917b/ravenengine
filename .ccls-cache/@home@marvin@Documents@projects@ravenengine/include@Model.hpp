/*
 * Model.h
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_MODEL_HPP_
#define INCLUDE_MODEL_HPP_

#include <memory>
#include <Player.hpp>
#include <Solid.hpp>

class Model {
private:
	std::vector<std::shared_ptr<WorldObject>> objects;
	std::vector<std::shared_ptr<rpy::Solid>> solids;
	std::shared_ptr<Player> player;

public:
	Player* getPlayer();

	std::vector<std::shared_ptr<WorldObject>>::iterator firstObject();
	std::vector<std::shared_ptr<WorldObject>>::iterator lastObject();
	std::vector<std::shared_ptr<rpy::Solid>>::iterator firstSolid();
	std::vector<std::shared_ptr<rpy::Solid>>::iterator lastSolid();
	std::vector<std::shared_ptr<rpy::Solid>>& getSolids();

	Model();
	virtual ~Model();
};

#endif /* INCLUDE_MODEL_HPP_ */
