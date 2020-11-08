/*
 * rpy.cpp
 *
 *  Created on: Nov 5, 2020
 *      Author: marvi
 */

#include <rpy.hpp>
#include <glm/glm.hpp>
#include <ArrayVector2D.hpp>

#include <stdlib.h>
#include <iostream>

static ArrayVector2D<int> solidsortx;
static ArrayVector2D<int> solidsorty;
static ArrayVector2D<int> solidsortz;
static ArrayVector2D<int> solidsort;
static std::vector<int> aux;
static unsigned int sort_ctr;

namespace rpy {

void initSolids(unsigned int count) {
	solidsortx = ArrayVector2D<int>(count);
	solidsorty = ArrayVector2D<int>(count);
	solidsortz = ArrayVector2D<int>(count);
	solidsort = ArrayVector2D<int>(count);
	aux = std::vector<int>(count);

	for (unsigned int i = 0; i < count; ++i) {
		solidsortx.push_back(i);
	}
}

inline unsigned int min(unsigned int x, unsigned int y) {
	return (x < y) ? x : y;
}

void merge(unsigned int lo, unsigned int mid, unsigned int hi,
		std::vector<std::shared_ptr<Solid>> &v, Axis a) {
	unsigned int i = mid + 1;
	sort_ctr = lo;

	switch (a) {
	case x:
		for (unsigned int k = lo; k <= hi; ++k) {
			aux.at(k) = solidsortx.at(k);
		}
		while (lo <= mid && i <= hi) {
			if (v.at(aux.at(lo))->getSphere().pos.x
					- v.at(aux.at(lo))->getSphere().rad
					<= v.at(aux.at(i))->getSphere().pos.x
							- v.at(aux.at(i))->getSphere().rad) {
				solidsortx.at(sort_ctr++) = aux.at(lo++);
			} else {
				solidsortx.at(sort_ctr++) = aux.at(i++);
			}

		}
		while (lo <= mid) {
			solidsortx.at(sort_ctr++) = aux.at(lo++);
		}

		while (i <= hi) {
			solidsortx.at(sort_ctr++) = aux.at(i++);
		}
		break;
	case y:
		for (unsigned int k = lo; k <= hi; ++k) {
			aux.at(k) = solidsorty.at(k);
		}
		while (lo <= mid && i <= hi) {
			if (v.at(aux.at(lo))->getSphere().pos.y
					- v.at(aux.at(lo))->getSphere().rad
					<= v.at(aux.at(i))->getSphere().pos.y
							- v.at(aux.at(i))->getSphere().rad) {
				solidsorty.at(sort_ctr++) = aux.at(lo++);
			} else {
				solidsorty.at(sort_ctr++) = aux.at(i++);
			}

		}
		while (lo <= mid) {
			solidsorty.at(sort_ctr++) = aux.at(lo++);
		}

		while (i <= hi) {
			solidsorty.at(sort_ctr++) = aux.at(i++);
		}
		break;
	case z:
		for (unsigned int k = lo; k <= hi; ++k) {
			aux.at(k) = solidsortz.at(k);
		}
		while (lo <= mid && i <= hi) {
			if (v.at(aux.at(lo))->getSphere().pos.z
					- v.at(aux.at(lo))->getSphere().rad
					<= v.at(aux.at(i))->getSphere().pos.z
							- v.at(aux.at(i))->getSphere().rad) {
				solidsortz.at(sort_ctr++) = aux.at(lo++);
			} else {
				solidsortz.at(sort_ctr++) = aux.at(i++);
			}

		}
		while (lo <= mid) {
			solidsortz.at(sort_ctr++) = aux.at(lo++);
		}

		while (i <= hi) {
			solidsortz.at(sort_ctr++) = aux.at(i++);
		}
		break;
	}
}

void mergesort(std::vector<std::shared_ptr<Solid>> &v, Axis a) {
	sort_ctr = 0;
	unsigned int size = 0;

	switch (a) {
	case x:
		size = solidsortx.size() - 1;
		break;
	case y:
		size = solidsorty.size() - 1;
		break;
	case z:
		size = solidsortz.size() - 1;
		break;
	}

	if (a == z) {
		for (unsigned int k = 0; k < solidsortz.numLists(); ++k) {
			solidsortz.getList(k);
			size = solidsortz.size() > 1 ? solidsortz.size() - 1 : 0;
			for (unsigned int curr_size = 1; curr_size <= size;
					curr_size = 2 * curr_size) {
				for (unsigned int left_start = 0; left_start < size;
						left_start += 2 * curr_size) {
					auto mid = min(left_start + curr_size - 1, size);
					auto right_end = min(left_start + 2 * curr_size - 1, size);
					merge(left_start, mid, right_end, v, a);
				}
			}
		}
		return;
	}

	for (unsigned int curr_size = 1; curr_size <= size;
			curr_size = 2 * curr_size) {
		for (unsigned int left_start = 0; left_start < size;
				left_start += 2 * curr_size) {
			auto mid = min(left_start + curr_size - 1, size);
			auto right_end = min(left_start + 2 * curr_size - 1, size);
			merge(left_start, mid, right_end, v, a);
		}
	}
}

inline float abs(float x) {
	return x < 0 ? -x : x;
}

inline void sweep(std::vector<std::shared_ptr<Solid>> &objects, Axis a) {
	unsigned int size;
	bool noCollisionBefore;

	switch (a) {
	case x:
		for (unsigned int k = 0; k < solidsortx.numLists(); ++k) {
			noCollisionBefore = true;
			solidsortx.getList(0);
			size = solidsortx.size() > 1 ? solidsortx.size() - 1 : 0;
			for (unsigned int i = 0; i < size; ++i) {
				sphere s1 = objects.at(solidsortx.at(i))->getSphere();
				sphere s2 = objects.at(solidsortx.at(i + 1))->getSphere();
				if (abs(s2.pos.x - s1.pos.x) <= s1.rad + s2.rad) {
					if (noCollisionBefore) {
						noCollisionBefore = false;
						solidsortz.addList();
					}
					if (solidsortz.size() == 0
							|| solidsortz.head() != solidsortx.at(i)) {
						solidsortz.push_back(solidsortx.at(i));
					}
					solidsortz.push_back(solidsortx.at(i + 1));
				} else {
					noCollisionBefore = true;
				}
			}
		}
		break;
	case y:
		for (unsigned int k = 0; k < solidsorty.numLists(); ++k) {
			noCollisionBefore = true;
			solidsorty.getList(k);
			size = solidsorty.size() > 1 ? solidsorty.size() - 1 : 0;
			for (unsigned int i = 0; i < size; ++i) {
				sphere s1 = objects.at(solidsorty.at(i))->getSphere();
				sphere s2 = objects.at(solidsorty.at(i + 1))->getSphere();
				if (abs(s2.pos.y - s1.pos.y) <= s1.rad + s2.rad) {
					if (noCollisionBefore) {
						noCollisionBefore = false;
						solidsort.addList();
					}
					if (solidsort.size() == 0
							|| solidsort.head() != solidsorty.at(i)) {
						solidsort.push_back(solidsorty.at(i));
					}
					solidsort.push_back(solidsorty.at(i + 1));
				} else {
					noCollisionBefore = true;
				}
			}
		}
		break;
	case z:
		for (unsigned int k = 0; k < solidsortz.numLists(); ++k) {
			noCollisionBefore = true;
			solidsortz.getList(k);
			size = solidsortz.size() > 1 ? solidsortz.size() - 1 : 0;
			for (unsigned int i = 0; i < size; ++i) {
				sphere s1 = objects.at(solidsortz.at(i))->getSphere();
				sphere s2 = objects.at(solidsortz.at(i + 1))->getSphere();
				if (abs(s2.pos.z - s1.pos.z) <= s1.rad + s2.rad) {
					if (noCollisionBefore) {
						noCollisionBefore = false;
						solidsorty.addList();
					}
					if (solidsorty.size() == 0
							|| solidsorty.head() != solidsortz.at(i)) {
						solidsorty.push_back(solidsortz.at(i));
					}
					solidsorty.push_back(solidsortz.at(i + 1));
				} else {
					noCollisionBefore = true;
				}
			}
		}
		break;
	}
}

void handleCollisions(std::vector<std::shared_ptr<Solid>> &objects) {
	solidsorty.clear();
	solidsortz.clear();

	//sort for possible collisions in x-direction
	mergesort(objects, x);
	sweep(objects, x);

	for (unsigned int l = 0; l < solidsortx.numLists(); ++l) {
		solidsortx.getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < solidsortx.size(); ++i) {
			std::cout << " " << solidsortx.at(i) << " ";
		}
	}
	std::cout << "|\n";

	mergesort(objects, z);
	sweep(objects, z);

	for (unsigned int l = 0; l < solidsortz.numLists(); ++l) {
		solidsortz.getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < solidsortz.size(); ++i) {
			std::cout << " " << solidsortz.at(i) << " ";
		}
	}
	std::cout << "|\n";

	mergesort(objects, y);
	sweep(objects, y);

	for (unsigned int l = 0; l < solidsorty.numLists(); ++l) {
		solidsorty.getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < solidsorty.size(); ++i) {
			std::cout << " " << solidsorty.at(i) << " ";
		}
	}
	std::cout << "|\n";

	for (unsigned int l = 0; l < solidsort.numLists(); ++l) {
		solidsort.getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < solidsort.size(); ++i) {
			std::cout << " " << solidsort.at(i) << " ";
		}
	}
	std::cout << "|\n";

	if (solidsort.size() > 0) {
		exit(0);
	}
}

}
