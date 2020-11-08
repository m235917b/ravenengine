/*
 * rpy.hpp
 *
 *  Created on: Nov 5, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_RPY_HPP_
#define INCLUDE_RPY_HPP_

#include <vector>
#include <functional>
#include <memory>
#include <Solid.hpp>

namespace rpy {

enum Axis {x, y, z};

void initSolids(unsigned int count);

void handleCollisions(std::vector<std::shared_ptr<Solid>> &objects);

}

#endif /* INCLUDE_RPY_HPP_ */
