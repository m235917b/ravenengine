/*
 * ArrayVector2D.hpp
 *
 *  Created on: Nov 8, 2020
 *      Author: marvi
 */

#ifndef ARRAYVECTOR2D_HPP_
#define ARRAYVECTOR2D_HPP_

#include <vector>

template<typename T>
class ArrayVector2D {
private:
	std::vector<T> arr;
	std::vector<unsigned int> indices;
	unsigned int head_ptr;
	unsigned int list_ptr;
	unsigned int active_list;

public:
	ArrayVector2D() :
			arr(0), indices(0), head_ptr(0), list_ptr(0), active_list(0) {

	}

	ArrayVector2D(unsigned int size) :
			arr(size), indices(size), head_ptr(0), list_ptr(1), active_list(0) {
		indices.at(0) = 0;
	}

	virtual ~ArrayVector2D() {

	}

	T& head() {
		return arr.at(head_ptr - 1);
	}

	T& at(unsigned int index) {
		return arr.at(indices.at(active_list) + index);
	}

	unsigned int size() {
		return active_list < list_ptr - 1 ?
				indices.at(active_list + 1) - indices.at(active_list) :
				head_ptr - indices.at(list_ptr - 1);
	}

	bool isEmpty() {
		return head_ptr <= indices.at(active_list);
	}

	unsigned int numLists() {
		return list_ptr;
	}

	void push_back(T element) {
		arr.at(head_ptr++) = element;
	}

	void clear() {
		head_ptr = 0;
		list_ptr = 1;
		indices.at(0) = 0;
		active_list = 0;
	}

	void clearCurrent() {
		head_ptr = indices.at(active_list);
		list_ptr = active_list + 1;
	}

	//finishes current list and appends new one
	void addList() {
		if (indices.at(list_ptr - 1) != head_ptr) {
			active_list = list_ptr;
			indices.at(list_ptr++) = head_ptr;
		}
	}

	void getList(unsigned int index) {
		active_list = index;
	}
};

#endif /* ARRAYVECTOR2D_HPP_ */
