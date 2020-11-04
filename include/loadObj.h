/*
 * loadObj.h
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_LOADOBJ_H_
#define INCLUDE_LOADOBJ_H_

#include <functional>
#include <ComposedObject.h>

template<typename T>
int findElem(std::vector<T> &v, std::function<bool(T)> f);

compObj loadObject(const std::string filename);

#endif /* INCLUDE_LOADOBJ_H_ */
