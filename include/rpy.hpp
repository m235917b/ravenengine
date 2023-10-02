/*
 * rpy.hpp
 *
 *  Created on: Nov 5, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_RPY_HPP_
#define INCLUDE_RPY_HPP_

#include <Solid.hpp>
#include <functional>
#include <memory>
#include <vector>

namespace rpy {

enum Axis { x, y, z };

void initSolids(std::vector<std::shared_ptr<rpy::Solid>> &);

void handleCollisions();

} // namespace rpy

#endif /* INCLUDE_RPY_HPP_ */
