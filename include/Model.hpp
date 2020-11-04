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

class Model {
private:
	std::vector<std::shared_ptr<WorldObject>> objects;

public:
	Player* getPlayer();

	std::vector<std::shared_ptr<WorldObject>>::iterator firstObject();
	std::vector<std::shared_ptr<WorldObject>>::iterator lastObject();

	Model();
	virtual ~Model();
};

#endif /* INCLUDE_MODEL_HPP_ */
