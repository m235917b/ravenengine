/*
 * Model.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#include "Cube.hpp"
#include "CubeTest.hpp"
#include "Floor.hpp"
#include "Solid.hpp"
#include "Wall.hpp"
#include "WorldObject.hpp"
#include <AnimTest.hpp>
#include <CubeTest.hpp>
#include <Model.hpp>
#include <NPCSimple.hpp>
#include <algorithm>
#include <memory>

Model::Model()
    : objects(), solids(), player(std::shared_ptr<Player>(new Player())) {
  solids.push_back(std::dynamic_pointer_cast<rpy::Solid>(player));

  objects.push_back(
      std::shared_ptr<WorldObject>(new NPCSimple(0.0f, 0.0f, -20.0f)));

  objects.push_back(
      std::shared_ptr<WorldObject>(new AnimTest(10.0f, 0.0f, -200.0f)));

  // solids.push_back(std::shared_ptr<rpy::Solid>(new Wall(-50.f, 0.f, 50.f)));

  for (int x = -1; x < 4; ++x) {
    for (int y = 0; y < 4; ++y) {
      solids.push_back(std::shared_ptr<rpy::Solid>(
          new Wall(-50.0f + y * 2.f, x * 2.f, 50.0f + (((x + y) % 2) * 0.5f))));
    }
  }

  solids.push_back(std::shared_ptr<rpy::Solid>(new Floor(0.f, -50.f, 0.f)));

  solids.push_back(
      std::shared_ptr<rpy::Solid>(new CubeTest(0.0f, 0.f, -20.0f)));
  solids.push_back(
      std::shared_ptr<rpy::Solid>(new CubeTest(0.0f, 10.f, -20.0f)));
  /*solids.push_back(std::shared_ptr<rpy::Solid>(new Cube(-10.1f, 0.0f,
  -20.0f))); solids.push_back( std::shared_ptr<rpy::Solid>(new
  Cube(100.0f, 1.0f, -200.0f)));
  solids.push_back(std::shared_ptr<rpy::Solid>(new Cube(10.0f, 1.0f, -23.5f)));
  solids.push_back(std::shared_ptr<rpy::Solid>(new Cube(-20.0f, 0.0f, -20.0f)));
  solids.push_back(
      std::shared_ptr<rpy::Solid>(new Cube(-10.0f, 10.0f, -20.0f)));
  solids.push_back(std::shared_ptr<rpy::Solid>(new Cube(50.0f, 0.0f, -200.0f)));
  solids.push_back(std::shared_ptr<rpy::Solid>(new Cube(30.0f, 0.0f, -30.0f)));
  solids.push_back(std::shared_ptr<rpy::Solid>(new Cube(0.0f, 0.0f, -30.0f)));*/

  /*for (int x = -1; x < 4; ++x) {
    for (int y = 0; y < 4; ++y) {
      solids.push_back(std::shared_ptr<rpy::Solid>(
          new CubeTest(100.0f + y * 2.f, x * 2.f, 0.0f)));
    }
  }*/
}

Player *Model::getPlayer() { return player.get(); }

std::vector<std::shared_ptr<WorldObject>>::iterator Model::firstObject() {
  return objects.begin();
}

std::vector<std::shared_ptr<WorldObject>>::iterator Model::lastObject() {
  return objects.end();
}

std::vector<std::shared_ptr<rpy::Solid>>::iterator Model::firstSolid() {
  return solids.begin();
}

std::vector<std::shared_ptr<rpy::Solid>>::iterator Model::lastSolid() {
  return solids.end();
}

std::vector<std::shared_ptr<rpy::Solid>> &Model::getSolids() { return solids; }

Model::~Model() {}
