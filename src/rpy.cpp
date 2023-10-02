/*
 * rpy.cpp
 *
 *  Created on: Nov 5, 2020
 *      Author: marvi
 */

#include <ArrayVector2D.hpp>
#include <Solid.hpp>
#include <functional>
#include <glm/common.hpp>
#include <glm/glm.hpp>
#include <memory>
#include <rpy.hpp>

#include <iostream>
#include <stdlib.h>
#include <vector>

static ArrayVector2D<std::shared_ptr<rpy::Solid>> solidsortx;
static ArrayVector2D<std::shared_ptr<rpy::Solid>> solidsorty;
static ArrayVector2D<std::shared_ptr<rpy::Solid>> solidsortz;
static ArrayVector2D<std::shared_ptr<rpy::Solid>> solidsort;
static std::vector<std::shared_ptr<rpy::Solid>> aux;
static unsigned int sort_ctr;

namespace rpy {

void initSolids(std::vector<std::shared_ptr<rpy::Solid>> &objects) {
  solidsortx = ArrayVector2D<std::shared_ptr<rpy::Solid>>(objects.size());
  solidsorty = ArrayVector2D<std::shared_ptr<rpy::Solid>>(objects.size());
  solidsortz = ArrayVector2D<std::shared_ptr<rpy::Solid>>(objects.size());
  solidsort = ArrayVector2D<std::shared_ptr<rpy::Solid>>(objects.size());
  aux = std::vector<std::shared_ptr<rpy::Solid>>(objects.size());

  for (std::shared_ptr<rpy::Solid> s : objects) {
    solidsortx.push_back(s);
  }
}

inline unsigned int min(unsigned int x, unsigned int y) {
  return (x < y) ? x : y;
}

template <typename T>
inline void merge(unsigned int lo, unsigned int mid, unsigned int hi,
                  ArrayVector2D<T> &a, std::vector<T> &aux,
                  std::function<bool(T &, T &)> comp) {
  unsigned int i = mid + 1;
  sort_ctr = lo;

  for (unsigned int k = lo; k <= hi; ++k) {
    aux.at(k) = a.at(k);
  }
  while (lo <= mid && i <= hi) {
    if (comp(aux.at(lo), aux.at(i))) {
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

template <typename T>
inline void mergesort(ArrayVector2D<T> &a, std::vector<T> &aux,
                      std::function<bool(T &, T &)> comp) {
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
        merge<T>(left_start, mid, right_end, a, aux, comp);
      }
    }
  }
}

/**
 * This function takes a list of solids, that is sorted for the lower bound in a
 * certain direction and searches for possible collision groups (colliding
 * objects in a chain) in that direction. It returns a list of lists where each
 * inner list represents a possible collision group.
 *
 * @param in Sorted ArrayVector2D of solids in one direction (sorted for lower
 * bounds)
 * @param out ArrayVector2D of lists containing possible collision groups in the
 * sorted direction
 * @param f Function for determining when a collision occurs
 */
inline void sweep(ArrayVector2D<std::shared_ptr<Solid>> &in,
                  ArrayVector2D<std::shared_ptr<Solid>> &out,
                  std::function<bool(sphere &, sphere &)> f) {
  bool noCollisionBefore;

  for (unsigned int k = 0; k < in.numLists(); ++k) {
    /* Switch for detecting groups of collisions.
    Only needed, if no empty list should created at the end. */
    noCollisionBefore = true;
    in.getList(k);
    auto &s1 = in.at(0)->getSphere();

    /* iterate over every previously detected collision group
    (for an otheraxis), or the list of sorted solids */
    for (unsigned int i = 1; i < in.size(); ++i) {
      auto &s2 = in.at(i)->getSphere();

      // if bounding spheres collide
      if (f(s1, s2)) {
        // if this is new collision group
        if (noCollisionBefore) {
          noCollisionBefore = false;
          // create a new list for new collision group
          out.addList();
        }
        // add colliding solids to the list for the collision group
        if (out.size() == 0 || out.head() != in.at(i - 1)) {
          out.push_back(in.at(i - 1));
        }
        out.push_back(in.at(i));
      } else {
        noCollisionBefore = true;
      }

      /* only compare next bounding sphere with the sphere that has the highest
      bound in the direction of search, otherwise a smaller object might not
      collide with its successor, but with a larger previous object */
      if (glm::distance(s1.pos, s2.pos) + s2.rad >= s1.rad) {
        s1 = s2;
      }
    }
  }
}

inline float min(std::shared_ptr<triangle> t, Axis a) {
  float p1;
  float p2;
  float p3;

  switch (a) {
  case x:
    p1 = t->a->pos.x;
    p2 = t->b->pos.x;
    p3 = t->c->pos.x;
    break;
  case y:
    p1 = t->a->pos.y;
    p2 = t->b->pos.y;
    p3 = t->c->pos.y;
    break;
  case z:
    p1 = t->a->pos.z;
    p2 = t->b->pos.z;
    p3 = t->c->pos.z;
    break;
  }

  return p1 <= p2 && p1 <= p3 ? p1 : p2 <= p3 ? p2 : p3;
}

inline float max(std::shared_ptr<triangle> t, Axis a) {
  float p1;
  float p2;
  float p3;

  switch (a) {
  case x:
    p1 = t->a->pos.x;
    p2 = t->b->pos.x;
    p3 = t->c->pos.x;
    break;
  case y:
    p1 = t->a->pos.y;
    p2 = t->b->pos.y;
    p3 = t->c->pos.y;
    break;
  case z:
    p1 = t->a->pos.z;
    p2 = t->b->pos.z;
    p3 = t->c->pos.z;
    break;
  }

  return p1 >= p2 && p1 >= p3 ? p1 : p2 >= p3 ? p2 : p3;
}

/**
 * Detects which triangles of the first solid collide with the second solid, by
 * sweeping through a sorted list of the traingles, which makes it possible to
 * detect those collisions in O(n) runtime. The triangles that will be detected,
 * are stored in the ArrayVector2D of the first solid.
 *
 * @param o1 The first solid of which the triangles that collide with the second
 * solid will be detected
 * @param o2 The second solid for which the collisions with the trianles of the
 * first solid should be tested */
inline void sweepTriangle(std::shared_ptr<Solid> o1,
                          std::shared_ptr<Solid> o2) {
  // clear any previously found colliding triangles
  o1->getSolidSort().clear();
  unsigned int j = 0;

  // iterate over every triangle t1 of the sorted list of o1
  for (unsigned int i = 0; i < o1->getSolidSortX().size(); ++i) {
    /* ignore every triangle t2 from o2 that can not collide with current
     * triangle t1, because its upper bound is lower that the lower
     * bound of t1 */
    while (min(o1->getSolidSortX().at(i), x) >
           max(o2->getSolidSortX().at(j), x)) {
      ++j;

      /* if no traingle that is left of o2 collides with the current triangle
       * t1, stop the seach */
      if (j >= o2->getSolidSortX().size()) {
        return;
      }
    }

    /* if a triangle of o2 has been found, that could collide with the current
     * triangle t1 (upper bound is higher than lower bound of t1), test for
     * collision */

    if (max(o1->getSolidSortX().at(i), x) > min(o2->getSolidSortX().at(j), x))
      if (min(o1->getSolidSortX().at(i), y) < max(o2->getSolidSortX().at(j), y))
        if (max(o1->getSolidSortX().at(i), y) >
            min(o2->getSolidSortX().at(j), y))
          if (min(o1->getSolidSortX().at(i), z) <
              max(o2->getSolidSortX().at(j), z))
            if (max(o1->getSolidSortX().at(i), z) >
                min(o2->getSolidSortX().at(j), z))
              o1->getSolidSort().push_back(o1->getSolidSortX().at(i));

    /* No matter if the triangles collided or not, whe can safely continue to
     * the next triangle of o2. This is, because it only matters, which
     * triangles of o1 are colliding with o2, not with which, or how many
     * triangles of o2. Thus, if t1 does collide with the first
     * triangle t2 of o2 with lower_bound >= t1.upper_bund, we already detected
     * t1 in this iteration and it doesn't matter if it also collides with the
     * next triangle. Otherwise, if t1 does not collide with the first triangle
     * of o2 with lower_bound >= t1.upper_bund, no triangle that comes next in
     * the list could collide with t1, because of the ordering. So only the next
     * triangle in the list for o1 needs to be checked for collision with t2.*/
  }
}

/**
 * This function detects collisions between triangles of two solids. All
 * traingles that are part of the collision can be found in the ArrayVector2D
 * SolidSort of the respective objects (call object.getSolidSort()), so their
 * normals can be used for collision handling after calling this function.
 *
 * @param o1 First solid for collision detection
 * @param o2 Second solid for collision detection
 */
inline void sortCollisionsTriangle(std::shared_ptr<Solid> o1,
                                   std::shared_ptr<Solid> o2) {
  o1->updateVertices();
  o2->updateVertices();

  // sort all triangles of o1 for their lower bound in any direction
  mergesort<std::shared_ptr<triangle>>(
      o1->getSolidSortX(), o1->getAux(),
      [](std::shared_ptr<triangle> lo, std::shared_ptr<triangle> hi) -> bool {
        return min(lo, x) <= min(hi, x);
      });
  // sort all triangles of o2 for their upper bound in the same direction
  mergesort<std::shared_ptr<triangle>>(
      o2->getSolidSortX(), o2->getAux(),
      [](std::shared_ptr<triangle> lo, std::shared_ptr<triangle> hi) -> bool {
        return max(lo, x) <= max(hi, x);
      });
  /* detect all triangles of o1 that are colliding with o2 and store them in
  o1.SolidSort */
  sweepTriangle(o1, o2);

  /* because only the triangles of the first object that collide with the second
   * can be found in O(n) runtime, the entire process needs to be done again for
   * the second object*/

  // sort all triangles of o1 for their upper bound in any direction
  mergesort<std::shared_ptr<triangle>>(
      o1->getSolidSortX(), o1->getAux(),
      [](std::shared_ptr<triangle> lo, std::shared_ptr<triangle> hi) -> bool {
        return max(lo, x) <= max(hi, x);
      });
  // sort all triangles of o2 for their lower bound in the same direction
  mergesort<std::shared_ptr<triangle>>(
      o2->getSolidSortX(), o2->getAux(),
      [](std::shared_ptr<triangle> lo, std::shared_ptr<triangle> hi) -> bool {
        return min(lo, x) <= min(hi, x);
      });
  /* detect all triangles of o2 that are colliding with o1 and store them in
  o2.SolidSort */
  sweepTriangle(o2, o1);
}

/**
 * Searches for all separate groups of colliding bounding spheres, to eliminate
 * as much objects that have to be tested for collision as possible. The objects
 * in each group have to be tested for collision pair wise after calling this
 * function.
 */
inline void sortCollisions() {
  solidsorty.clear();
  solidsortz.clear();
  solidsort.clear();

  /* sort the bounding spheres of all solids for possible collisions in
   * x-direction by their lower bound */
  mergesort<std::shared_ptr<Solid>>(
      solidsortx, aux,
      [](std::shared_ptr<Solid> &lo, std::shared_ptr<Solid> &hi) -> bool {
        return lo->getSphere().pos.x - lo->getSphere().rad <=
               hi->getSphere().pos.x - hi->getSphere().rad;
      });
  /* sweep through all bounding spheres to detect all seperate groups of
   * possibly colliding spheres in x-direction */
  sweep(solidsortx, solidsortz, [](sphere &s1, sphere &s2) -> bool {
    return abs(s2.pos.x - s1.pos.x) <= s1.rad + s2.rad;
  });

  /* sort the bounding spheres of all solids for possible collisions in
   * z-direction by their lower bound */
  mergesort<std::shared_ptr<Solid>>(
      solidsortz, aux,
      [](std::shared_ptr<Solid> &lo, std::shared_ptr<Solid> &hi) -> bool {
        return lo->getSphere().pos.z - lo->getSphere().rad <=
               hi->getSphere().pos.z - hi->getSphere().rad;
      });
  /* sweep through all bounding spheres to detect all seperate groups of
   * possibly colliding spheres in z-direction */
  sweep(solidsortz, solidsorty, [](sphere &s1, sphere &s2) -> bool {
    return abs(s2.pos.z - s1.pos.z) <= s1.rad + s2.rad;
  });

  /* sort the bounding spheres of all solids for possible collisions in
   * y-direction by their lower bound */
  mergesort<std::shared_ptr<Solid>>(
      solidsorty, aux,
      [](std::shared_ptr<Solid> &lo, std::shared_ptr<Solid> &hi) -> bool {
        return lo->getSphere().pos.y - lo->getSphere().rad <=
               hi->getSphere().pos.y - hi->getSphere().rad;
      });
  /* sweep through all bounding spheres to detect all seperate groups of
   * possibly colliding spheres in y-direction */
  sweep(solidsorty, solidsort, [](sphere &s1, sphere &s2) -> bool {
    return abs(s2.pos.y - s1.pos.y) <= s1.rad + s2.rad;
  });
}

void handleCollisions() {
  sortCollisions();

  for (unsigned int l = 0; l < solidsort.numLists(); ++l) {
    solidsort.getList(l);
    auto size = solidsort.size() > 0 ? solidsort.size() - 1 : 0;
    for (unsigned int k = 0; k < size; ++k) {
      for (auto i = k + 1; i < solidsort.size(); ++i) {
        // get collision boxes
        auto s1 = solidsort.at(k)->getSphere();
        auto s2 = solidsort.at(i)->getSphere();
        // when collision boxes collide
        if (glm::distance(s1.pos, s2.pos) < s1.rad + s2.rad) {
          sortCollisionsTriangle(solidsort.at(k), solidsort.at(i));

          if (!solidsort.at(i)->getSolidSort().isEmpty()) {
            exit(0);
          }
        }
      }
    }
  }
}

} // namespace rpy
