/*
 * rpy.cpp
 *
 *  Created on: Nov 5, 2020
 *      Author: marvi
 */

#include <rpy.hpp>
#include <functional>
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

inline float abs(float x) {
	return x < 0 ? -x : x;
}

template<typename T>
inline void merge(unsigned int lo, unsigned int mid, unsigned int hi,
		std::vector<T> &v, ArrayVector2D<int> &a, std::vector<int> &aux,
		std::function<bool(T&, T&)> comp) {
	unsigned int i = mid + 1;
	sort_ctr = lo;

	for (unsigned int k = lo; k <= hi; ++k) {
		aux.at(k) = a.at(k);
	}
	while (lo <= mid && i <= hi) {
		if (comp(v.at(aux.at(lo)), v.at(aux.at(i)))) {
			a.at(sort_ctr++) = aux.at(lo++);
		} else {
			a.at(sort_ctr++) = aux.at(i++);
		}

	}
	while (lo <= mid) {
		a.at(sort_ctr++) = aux.at(lo++);
	}

	while (i <= hi) {
		a.at(sort_ctr++) = aux.at(i++);
	}
}

template<typename T>
inline void mergesort(std::vector<T> &v, ArrayVector2D<int> &a,
		std::vector<int> &aux, std::function<bool(T&, T&)> comp) {
	sort_ctr = 0;
	unsigned int size = 0;

	for (unsigned int k = 0; k < a.numLists(); ++k) {
		a.getList(k);
		size = a.size() > 1 ? a.size() - 1 : 0;
		for (unsigned int curr_size = 1; curr_size <= size;
				curr_size = 2 * curr_size) {
			for (unsigned int left_start = 0; left_start < size;
					left_start += 2 * curr_size) {
				auto mid = min(left_start + curr_size - 1, size);
				auto right_end = min(left_start + 2 * curr_size - 1, size);
				merge<T>(left_start, mid, right_end, v, a, aux, comp);
			}
		}
	}
}

inline void sweep(std::vector<std::shared_ptr<Solid>> &objects,
		ArrayVector2D<int> &in, ArrayVector2D<int> &out,
		std::function<bool(sphere&, sphere&)> f) {
	unsigned int size;
	bool noCollisionBefore;

	for (unsigned int k = 0; k < in.numLists(); ++k) {
		noCollisionBefore = true;
		in.getList(k);
		size = in.size() > 1 ? in.size() - 1 : 0;
		for (unsigned int i = 0; i < size; ++i) {
			auto s1 = objects.at(in.at(i))->getSphere();
			auto s2 = objects.at(in.at(i + 1))->getSphere();
			if (f(s1, s2)) {
				if (noCollisionBefore) {
					noCollisionBefore = false;
					out.addList();
				}
				if (out.size() == 0 || out.head() != in.at(i)) {
					out.push_back(in.at(i));
				}
				out.push_back(in.at(i + 1));
			} else {
				noCollisionBefore = true;
			}
		}
	}
}

inline float min(triangle &t1, Axis a) {
	float p1;
	float p2;
	float p3;

	switch (a) {
	case x:
		p1 = t1.a->pos.x;
		p2 = t1.b->pos.x;
		p3 = t1.c->pos.x;
		break;
	case y:
		p1 = t1.a->pos.y;
		p2 = t1.b->pos.y;
		p3 = t1.c->pos.y;
		break;
	case z:
		p1 = t1.a->pos.z;
		p2 = t1.b->pos.z;
		p3 = t1.c->pos.z;
		break;
	}

	return p1 <= p2 && p1 <= p3 ? p1 : p2 <= p3 ? p2 : p3;
}

inline float max(triangle &t1, Axis a) {
	float p1;
	float p2;
	float p3;

	switch (a) {
	case x:
		p1 = t1.a->pos.x;
		p2 = t1.b->pos.x;
		p3 = t1.c->pos.x;
		break;
	case y:
		p1 = t1.a->pos.y;
		p2 = t1.b->pos.y;
		p3 = t1.c->pos.y;
		break;
	case z:
		p1 = t1.a->pos.z;
		p2 = t1.b->pos.z;
		p3 = t1.c->pos.z;
		break;
	}

	return p1 >= p2 && p1 >= p3 ? p1 : p2 >= p3 ? p2 : p3;
}

/*inline Tuple<unsigned int> findGap(std::shared_ptr<Solid> o,
 ArrayVector2D<int> &av, unsigned int offset, Axis a) {
 if (av.size() < 2 + offset) {
 return Tuple<unsigned int>::empty();
 }

 for (unsigned int i = offset; i < av.size() - 1; ++i) {
 if (max(o->getPolygon().at(av.at(i)), a)
 < min(o->getPolygon().at(av.at(i + 1)), a)) {
 return Tuple<unsigned int>::of(i, i + 1);
 }
 }

 return Tuple<unsigned int>::empty();
 }*/

inline void sweepTriangle(std::shared_ptr<Solid> o1, std::shared_ptr<Solid> o2,
		Axis a) {
	unsigned int i, j;

	std::function<bool(triangle&, triangle&)> f = [&a](triangle &t1,
			triangle &t2) {
		auto min1 = min(t1, a);
		auto min2 = min(t2, a);
		auto max1 = max(t1, a);
		auto max2 = max(t2, a);
		std::cout << "-> " << min1 << ", " << min2 << ", " << max1 << ", "
				<< max2 << "\n";
		return min1 <= min2 ? max1 >= min2 : max2 >= min1;
	};

	ArrayVector2D<int> *in1;
	ArrayVector2D<int> *in2;
	ArrayVector2D<int> *out1;
	ArrayVector2D<int> *out2;

	switch (a) {
	case x:
		in1 = &o1->getSolidSortX();
		in2 = &o2->getSolidSortX();
		out1 = &o1->getSolidSortY();
		out2 = &o2->getSolidSortY();
		break;
	case y:
		in1 = &o1->getSolidSortY();
		in2 = &o2->getSolidSortY();
		out1 = &o1->getSolidSortZ();
		out2 = &o2->getSolidSortZ();
		break;
	case z:
		in1 = &o1->getSolidSortZ();
		in2 = &o2->getSolidSortZ();
		out1 = &o1->getSolidSort();
		out2 = &o2->getSolidSort();
		break;
	}

	out1->clear();
	out2->clear();

	for (unsigned int k = 0; k < in1->numLists(); ++k) {
		in1->getList(k);
		in2->getList(k);
		i = 0;
		j = 0;

		/*ArrayVector2D<int> *inmin;
		 ArrayVector2D<int> *inmax;
		 ArrayVector2D<int> *outmin;
		 ArrayVector2D<int> *outmax;
		 Solid *omin;
		 Solid *omax;

		 if (min(o1->getPolygon().at(in1->at(i)), a)
		 <= min(o2->getPolygon().at(in2->at(j)), a)) {
		 inmin = in1;
		 inmax = in2;
		 outmin = out1;
		 outmax = out2;
		 omin = o1.get();
		 omax = o2.get();
		 } else {
		 inmin = in2;
		 inmax = in1;
		 outmin = out2;
		 outmax = out1;
		 omin = o2.get();
		 omax = o1.get();
		 }

		 while (i < inmin->size() && j < inmax->size()) {
		 if (min(o1->getPolygon().at(in1->at(i)), a)
		 <= min(o2->getPolygon().at(in2->at(j)), a)) {
		 inmin = in1;
		 inmax = in2;
		 outmin = out1;
		 outmax = out2;
		 omin = o1.get();
		 omax = o2.get();
		 } else {
		 inmin = in2;
		 inmax = in1;
		 outmin = out2;
		 outmax = out1;
		 omin = o2.get();
		 omax = o1.get();
		 }

		 //copy until next gap in inmin is found
		 while (i + 1 < inmin->size()
		 && max(omin->getPolygon().at(inmin->at(i)), a)
		 > min(omin->getPolygon().at(inmin->at(i + 1)), a)) {
		 if (!outmin->isEmpty() && outmin->head() != inmin->at(i)) {
		 outmin->push_back(inmin->at(i));
		 }
		 std::cout << inmin->at(i) << "\n";
		 outmin->push_back(inmin->at(++i));
		 }

		 std::cout << "->\n";

		 //if groups don't collide, clear smaller group
		 if (max(omin->getPolygon().at(inmin->at(i)), a)
		 < min(omax->getPolygon().at(inmax->at(j)), a)) {
		 outmin->clearCurrent();
		 }

		 //copy until next gap in inmax is found
		 while (j + 1 < inmax->size()
		 && max(omax->getPolygon().at(inmax->at(j)), a)
		 > min(omax->getPolygon().at(inmax->at(j + 1)), a)) {
		 if (!outmax->isEmpty() && outmax->head() != inmax->at(j)) {
		 outmax->push_back(inmax->at(j));
		 }
		 outmax->push_back(inmax->at(++j));
		 }

		 //if gap splits both groups
		 if (++i < inmin->size()) {
		 if (min(omin->getPolygon().at(inmin->at(i)), a)
		 > max(omax->getPolygon().at(inmax->at(j)), a)) {
		 outmin->addList();
		 outmax->addList();
		 } else {
		 ++j;
		 }
		 } else if (outmin->isEmpty()) {
		 outmax->clearCurrent();
		 }
		 }*/

		/*//copy until next gap in in1 is found
		 while (i + 1 < in1->size()
		 && max(o1->getPolygon().at(i), a)
		 >= min(o1->getPolygon().at(i + 1), a)) {
		 if (!out1->isEmpty() && out1->head() != in1->at(i)) {
		 out1->push_back(in1->at(i));
		 }
		 out1->push_back(in1->at(++i));
		 }

		 //copy until next gap in in2 is found
		 while (j + 1 < in2->size()
		 && max(o2->getPolygon().at(j), a)
		 >= min(o2->getPolygon().at(j + 1), a)) {
		 if (!out2->isEmpty() && out2->head() != in2->at(j)) {
		 out2->push_back(in2->at(j));
		 }
		 out2->push_back(in2->at(++j));
		 }

		 if (!out1->isEmpty() && !out2->isEmpty()) {
		 //check which interval has biggest max
		 if (max(o1->getPolygon().at(out1->head()), a)
		 <= max(o2->getPolygon().at(out2->head()), a)) {
		 //do they collide?
		 if (max(o1->getPolygon().at(out1->head()), a)
		 < min(o2->getPolygon().at(out2->head()), a)) {
		 //if not, delete smaller group
		 out1->clearCurrent();

		 //does bigger group collide with next element?
		 if (i + 1 >= in1->size()
		 || min(o1->getPolygon().at(in1->at(i + 1)), a)
		 > max(o2->getPolygon().at(out2->head()),
		 a)) {
		 //if not, delete bigger group too
		 out2->clearCurrent();
		 }
		 } else {
		 //does bigger group collide with next element?
		 if (i + 1 >= in1->size()
		 || min(o1->getPolygon().at(in1->at(i + 1)), a)
		 > max(o2->getPolygon().at(out2->head()),
		 a)) {
		 //if not, cut lists
		 out1->addList();
		 out2->addList();
		 }
		 }
		 }
		 }*/
		bool sw = false;

		if (i < in1->size() && j < in2->size()) {
			sw = min(o1->getPolygon().at(in1->at(i)), a) <= min(o2->getPolygon().at(in2->at(j)), a);
		}

		std::cout << "->" << in1->size() << "\n";
		std::cout << "->" << in2->size() << "\n";
		//while (!in1->isEmpty() && i < in1->size() - 1 && )
		while (i < in1->size() && j < in2->size()) {
			auto &t1 = o1->getPolygon().at(in1->at(i));
			auto &t2 = o2->getPolygon().at(in2->at(j));

			std::cout << in1->at(i) << "#" << in2->at(j) << "\n";

			if (f(t1, t2)) {
				if (!out1->isEmpty())
					std::cout << out1->head() << "...\n";
				if (!out2->isEmpty())
					std::cout << out2->head() << "...\n";

				if (sw) {
					if (out2->isEmpty() || out2->head() != in2->at(j)) {
						out2->push_back(in2->at(j));
					}

					out1->push_back(in1->at(i));

					if (i + 1 == in1->size()) {
						while (j < in2->size()) {
							// auto &t1 = o1->getPolygon().at(in1->at(i));
							auto &t2 = o2->getPolygon().at(in2->at(j));

							if (f(t1, t2)) {
								if (out2->isEmpty()
										|| out2->head() != in2->at(j)) {
									out2->push_back(in2->at(j));
								}
							}

							++j;
						}
					}

					++i;
				} else {
					if (out1->isEmpty() || out1->head() != in1->at(i)) {
						out1->push_back(in1->at(i));
					}

					out2->push_back(in2->at(j));

					if (j + 1 == in2->size()) {
						while (i < in1->size()) {
							auto &t1 = o1->getPolygon().at(in1->at(i));
							//auto &t2 = o2->getPolygon().at(in2->at(j));

							if (f(t1, t2)) {
								if (out1->isEmpty()
										|| out1->head() != in1->at(i)) {
									out1->push_back(in1->at(i));
								}
							}

							++i;
						}
					}
					++j;
				}

				///---

				/*if (out1->isEmpty() || out1->head() != in1->at(i)) {
				 std::cout << "ggg\n";
				 out1->push_back(in1->at(i));
				 }

				 if (out2->isEmpty() || out2->head() != in2->at(j)) {
				 std::cout << "ggg\n";
				 out2->push_back(in2->at(j));
				 }

				 if (min(t1, a) <= min(t2, a)) {
				 ++i;
				 } else {
				 ++j;
				 }*/
			} else {
				/*if (sw) {
					++i;
				} else {
					++j;
				}*/

				/*if (i < in1->size() && j < in2->size()) {
					t1 = o1->getPolygon().at(in1->at(i));
					t2 = o2->getPolygon().at(in2->at(j));
				}*/

				if (min(t1, a) <= min(t2, a)) {
					//out2->addList();
					//++i;
					sw = true;
					if (j > 0) {
						--j;
					} else {
						++i;
					}
					//j = j > 0 ? j - 1 : 0;
				} else {
					//out1->addList();
					//++j;
					sw = false;
					//i = i > 0 ? i - 1 : 0;
					if (i > 0) {
						--i;
					} else {
						++j;
					}
				}
			}
		}

		/*if (!out2->isEmpty() && i < in1->size()
		 && (out1->isEmpty() || out1->head() != in1->at(i))) {
		 while (i < in1->size()) {
		 auto &t1 = o1->getPolygon().at(in1->at(i));
		 auto &t2 = o2->getPolygon().at(out2->head());

		 if (f(t1, t2)) {
		 out1->push_back(in1->at(i));
		 }

		 ++i;
		 }
		 }

		 if (!out1->isEmpty() && j < in2->size()
		 && (out2->isEmpty() || out2->head() != in2->at(j))) {
		 while (j < in2->size()) {
		 auto &t1 = o1->getPolygon().at(out1->head());
		 auto &t2 = o2->getPolygon().at(in2->at(j));

		 if (f(t1, t2)) {
		 out2->push_back(in2->at(j));
		 }

		 ++j;
		 }
		 }*/

		//out1->addList();
		//out2->addList();
	}

	/*for (unsigned int i = 0; i < in1.size(); ++i) {
	 out1.addList();
	 out2.addList();

	 std::cout << "->" << in2.size() << "\n";

	 while (j < in2.size() && f(p1.at(in1.at(i)), p2.at(in2.at(j)))) {
	 out2.push_back(in2.at(j++));
	 }

	 std::cout << "->" << in2.size() << "\n";

	 while (i < in1.size() && !out2.isEmpty()
	 && f(p1.at(in1.at(i)), p2.at(out2.head()))) {
	 out1.push_back(in1.at(i++));
	 }
	 }*/
}

inline void sortCollisionsTriangle(std::shared_ptr<Solid> o1,
		std::shared_ptr<Solid> o2) {
	o1->updateVertices();
	o2->updateVertices();

	mergesort<triangle>(o1->getPolygon(), o1->getSolidSortX(), o1->getAux(),
			[](triangle &lo, triangle &hi) {
				return min(lo, x) == min(hi, x) ?
						max(lo, x) <= max(hi, x) : min(lo, x) <= min(hi, x);
			});
	mergesort<triangle>(o2->getPolygon(), o2->getSolidSortX(), o2->getAux(),
			[](triangle &lo, triangle &hi) {
				return min(lo, x) == min(hi, x) ?
						max(lo, x) <= max(hi, x) : min(lo, x) <= min(hi, x);
			});
	/*sweepTriangle(o1, o2, o1->getSolidSortX(), o2->getSolidSortX(),
	 o1->getSolidSortY(), o2->getSolidSortY(),
	 [](triangle &t1, triangle &t2) {
	 auto min1 = min(t1, x);
	 auto min2 = min(t2, x);
	 auto max1 = max(t1, x);
	 auto max2 = max(t2, x);
	 std::cout << "-> " << min1 << ", " << min2 << ", " << max1
	 << ", " << max2 << "\n";
	 return min1 <= min2 ? max1 >= min2 : max2 >= min1;
	 });*/
	sweepTriangle(o1, o2, x);

	std::cout << "X";
	auto poly = o1->getPolygon();
	for (unsigned int l = 0; l < o1->getSolidSortX().numLists(); ++l) {
		o1->getSolidSortX().getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < o1->getSolidSortX().size(); ++i) {
			std::cout << " " << o1->getSolidSortX().at(i) << " ";
		}
	}
	std::cout << "|\n";

	std::cout << "X";
	for (unsigned int l = 0; l < o2->getSolidSortX().numLists(); ++l) {
		o2->getSolidSortX().getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < o2->getSolidSortX().size(); ++i) {
			std::cout << " " << o2->getSolidSortX().at(i) << " ";
		}
	}
	std::cout << "|\n";

	std::cout << "X";
	for (unsigned int l = 0; l < o2->getSolidSortX().numLists(); ++l) {
		o2->getSolidSortX().getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < o2->getSolidSortX().size(); ++i) {
			std::cout << " "
					<< min(o2->getPolygon().at(o2->getSolidSortX().at(i)), x)
					<< " ";
		}
	}
	std::cout << "|\n";

	mergesort<triangle>(o1->getPolygon(), o1->getSolidSortY(), o1->getAux(),
			[](triangle &lo, triangle &hi) {
				return min(lo, y) == min(hi, y) ?
						max(lo, y) <= max(hi, y) : min(lo, y) <= min(hi, y);
			});
	mergesort<triangle>(o2->getPolygon(), o2->getSolidSortY(), o2->getAux(),
			[](triangle &lo, triangle &hi) {
				return min(lo, y) == min(hi, y) ?
						max(lo, y) <= max(hi, y) : min(lo, y) <= min(hi, y);
			});
	/*sweepTriangle(o1, o2, o1->getSolidSortY(), o2->getSolidSortY(),
	 o1->getSolidSortZ(), o2->getSolidSortZ(),
	 [](triangle &t1, triangle &t2) {
	 auto min1 = min(t1, y);
	 auto min2 = min(t2, y);
	 auto max1 = max(t1, y);
	 auto max2 = max(t2, y);
	 return min1 <= min2 ? max1 >= min2 : max2 >= min1;
	 });*/
	sweepTriangle(o1, o2, y);

	std::cout << "Y";
	for (unsigned int l = 0; l < o1->getSolidSortY().numLists(); ++l) {
		o1->getSolidSortY().getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < o1->getSolidSortY().size(); ++i) {
			std::cout << " " << o1->getSolidSortY().at(i) << " ";
		}
	}
	std::cout << "|\n";

	std::cout << "Y";
	for (unsigned int l = 0; l < o2->getSolidSortY().numLists(); ++l) {
		o2->getSolidSortY().getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < o2->getSolidSortY().size(); ++i) {
			std::cout << " " << o2->getSolidSortY().at(i) << " ";
		}
	}
	std::cout << "|\n";

	mergesort<triangle>(o1->getPolygon(), o1->getSolidSortZ(), o1->getAux(),
			[](triangle &lo, triangle &hi) {
				return min(lo, z) == min(hi, z) ?
						max(lo, z) <= max(hi, z) : min(lo, z) <= min(hi, z);
			});
	mergesort<triangle>(o2->getPolygon(), o2->getSolidSortZ(), o2->getAux(),
			[](triangle &lo, triangle &hi) {
				return min(lo, z) == min(hi, z) ?
						max(lo, z) <= max(hi, z) : min(lo, z) <= min(hi, z);
			});
	/*sweepTriangle(o1, o2, o1->getSolidSortZ(), o2->getSolidSortZ(),
	 o1->getSolidSort(), o2->getSolidSort(),
	 [](triangle &t1, triangle &t2) {
	 auto min1 = min(t1, z);
	 auto min2 = min(t2, z);
	 auto max1 = max(t1, z);
	 auto max2 = max(t2, z);
	 std::cout << "-> " << min1 << ", " << min2 << ", " << max1
	 << ", " << max2 << "\n";
	 return min1 <= min2 ? max1 >= min2 : max2 >= min1;
	 });*/
	sweepTriangle(o1, o2, z);

	std::cout << "Z";
	for (unsigned int l = 0; l < o1->getSolidSortZ().numLists(); ++l) {
		o1->getSolidSortZ().getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < o1->getSolidSortZ().size(); ++i) {
			std::cout << " " << o1->getSolidSortZ().at(i) << " ";
		}
	}
	std::cout << "|\n";

	std::cout << "Z";
	for (unsigned int l = 0; l < o2->getSolidSortZ().numLists(); ++l) {
		o2->getSolidSortZ().getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < o2->getSolidSortZ().size(); ++i) {
			std::cout << " " << o2->getSolidSortZ().at(i) << " ";
		}
	}
	std::cout << "|\n";

	for (unsigned int l = 0; l < o1->getSolidSort().numLists(); ++l) {
		o1->getSolidSort().getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < o1->getSolidSort().size(); ++i) {
			std::cout << " " << o1->getSolidSort().at(i) << " ";
		}
	}
	std::cout << "|\n";

	for (unsigned int l = 0; l < o2->getSolidSort().numLists(); ++l) {
		o2->getSolidSort().getList(l);
		std::cout << "|";
		for (unsigned int i = 0; i < o2->getSolidSort().size(); ++i) {
			std::cout << " " << o2->getSolidSort().at(i) << " ";
		}
	}
	std::cout << "|\n";
	o1->getSolidSort().getList(0);
	if (!o1->getSolidSort().isEmpty() || !o2->getSolidSort().isEmpty()) {
		exit(0);
	}
}

inline void sortCollisions(std::vector<std::shared_ptr<Solid>> &objects) {
	solidsorty.clear();
	solidsortz.clear();
	solidsort.clear();

	//sort for possible collisions in x-direction
	mergesort<std::shared_ptr<Solid>>(objects, solidsortx, aux,
			[](std::shared_ptr<Solid> &lo, std::shared_ptr<Solid> &hi) {
				return lo->getSphere().pos.x - lo->getSphere().rad
						<= hi->getSphere().pos.x - hi->getSphere().rad;
			});
	sweep(objects, solidsortx, solidsortz, [](sphere &s1, sphere &s2) {
		return abs(s2.pos.x - s1.pos.x) <= s1.rad + s2.rad;
	});

	//sort for possible collisions in z-direction
	mergesort<std::shared_ptr<Solid>>(objects, solidsortz, aux,
			[](std::shared_ptr<Solid> &lo, std::shared_ptr<Solid> &hi) {
				return lo->getSphere().pos.z - lo->getSphere().rad
						<= hi->getSphere().pos.z - hi->getSphere().rad;
			});
	sweep(objects, solidsortz, solidsorty, [](sphere &s1, sphere &s2) {
		return abs(s2.pos.z - s1.pos.z) <= s1.rad + s2.rad;
	});

	//sort for possible collisions in y-direction
	mergesort<std::shared_ptr<Solid>>(objects, solidsorty, aux,
			[](std::shared_ptr<Solid> &lo, std::shared_ptr<Solid> &hi) {
				return lo->getSphere().pos.y - lo->getSphere().rad
						<= hi->getSphere().pos.y - hi->getSphere().rad;
			});
	sweep(objects, solidsorty, solidsort, [](sphere &s1, sphere &s2) {
		return abs(s2.pos.y - s1.pos.y) <= s1.rad + s2.rad;
	});
}

void handleCollisions(std::vector<std::shared_ptr<Solid>> &objects) {
	sortCollisions(objects);

	for (unsigned int l = 0; l < solidsort.numLists(); ++l) {
		solidsort.getList(l);
		auto size = solidsort.size() > 0 ? solidsort.size() - 1 : 0;
		for (unsigned int k = 0; k < size; ++k) {
			for (auto i = k + 1; i < solidsort.size(); ++i) {
				//get collision boxes
				auto s1 = objects.at(solidsort.at(k))->getSphere();
				auto s2 = objects.at(solidsort.at(i))->getSphere();
				//when collision boxes collide
				if (glm::distance(s1.pos, s2.pos) < s1.rad + s2.rad) {
					sortCollisionsTriangle(objects.at(solidsort.at(k)),
							objects.at(solidsort.at(i)));
				}
			}
		}
	}
}

}
