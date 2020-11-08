/*
 * ArrayVector.hpp
 *
 *  Created on: Nov 7, 2020
 *      Author: marvi
 */

#ifndef ARRAYVECTOR_HPP_
#define ARRAYVECTOR_HPP_

#include <vector>

template<typename T>
class ArrayVector {
private:
	std::vector<T> arr;
	unsigned int head_ctr;

public:
	ArrayVector() :
			arr(0), head_ctr(0) {
	}

	ArrayVector(unsigned int size) :
			arr(size), head_ctr(0) {
	}

	virtual ~ArrayVector() {

	}

	T& head() {
		return arr.at(head_ctr - 1);
	}

	T& at(unsigned int i) {
		return arr.at(i);
	}

	unsigned int size() {
		return head_ctr;
	}

	void push_back(T element) {
		arr.at(head_ctr++) = element;
	}

	void clear() {
		head_ctr = 0;
	}
};

#endif /* ARRAYVECTOR_HPP_ */
