/*
 * Model.h
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_MODEL_H_
#define INCLUDE_MODEL_H_

#include <memory>
#include <glm/glm.hpp>
#include <WorldObject.h>
#include <Player.hpp>

class Model {
private:
	std::vector<std::shared_ptr<WorldObject>> objects;

public:
	std::shared_ptr<Player> getPlayer();

	std::vector<std::shared_ptr<WorldObject>>::iterator firstObject();
	std::vector<std::shared_ptr<WorldObject>>::iterator lastObject();

	Model();
	virtual ~Model();
};

#endif /* INCLUDE_MODEL_H_ */
