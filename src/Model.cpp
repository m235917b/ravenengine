/*
 * Model.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#include <AnimTest.hpp>
#include <algorithm>
#include <CubeTest.hpp>
#include <Model.hpp>
#include <NPCSimple.hpp>

Model::Model() :
		objects(std::vector<std::shared_ptr<WorldObject>>()) {
	objects.push_back(std::shared_ptr<WorldObject>(new Player()));

	objects.push_back(std::shared_ptr<WorldObject>(new Cube(10.0f, 0.0f, -20.0f)));
	objects.push_back(std::shared_ptr<WorldObject>(new Cube(-10.0f, 0.0f, -20.0f)));
	objects.push_back(std::shared_ptr<WorldObject>(new Cube(100.0f, 0.0f, -200.0f)));
	objects.push_back(std::shared_ptr<WorldObject>(new Cube(10.0f, 0.0f, -200.0f)));
	objects.push_back(std::shared_ptr<WorldObject>(new Cube(10.0f, 20.0f, -20.0f)));

	objects.push_back(std::shared_ptr<WorldObject>(new NPCSimple(0.0f, 0.0f, -20.0f)));

	objects.push_back(std::shared_ptr<WorldObject>(new AnimTest()));
}

Player* Model::getPlayer() {
	return static_cast<Player*>(objects.front().get());
}

std::vector<std::shared_ptr<WorldObject>>::iterator Model::firstObject() {
	return objects.begin();
}

std::vector<std::shared_ptr<WorldObject>>::iterator Model::lastObject() {
	return objects.end();
}

Model::~Model() {

}

