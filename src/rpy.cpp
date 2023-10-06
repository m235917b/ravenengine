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
#include <glm/geometric.hpp>
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
//

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

    if (in.size() == 0) {
      continue;
    }

    auto s1 = std::make_shared<sphere>(in.at(0)->getSphere());

    /* iterate over every previously detected collision group
    (for an otheraxis), or the list of sorted solids */
    for (unsigned int i = 1; i < in.size(); ++i) {
      auto s2 = std::make_shared<sphere>(in.at(i)->getSphere());

      // if bounding spheres collide
      if (f(*s1, *s2)) {
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

      /* only compare next bounding sphere with the sphere that has the
      highest bound in the direction of search, otherwise a smaller object
      might not collide with its successor, but with a larger previous object
      */
      if (glm::distance(s1->pos, s2->pos) + s2->rad >= s1->rad) {
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
  /* sweep through all bounding spheres to detect all separate groups of
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
  /* sweep through all bounding spheres to detect all separate groups of
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
  /* sweep through all bounding spheres to detect all separate groups of
   * possibly colliding spheres in y-direction */
  sweep(solidsorty, solidsort, [](sphere &s1, sphere &s2) -> bool {
    return abs(s2.pos.y - s1.pos.y) <= s1.rad + s2.rad;
  });
}

inline void reduceCollisionsTriangle(float lo_x, float hi_x, float lo_y,
                                     float hi_y, float lo_z, float hi_z,
                                     std::shared_ptr<Solid> o) {
  o->updateVertices();

  o->getSolidSortB().clear();

  for (unsigned int i = 0; i < o->getSolidSortA().size(); ++i) {
    const auto &t = o->getSolidSortA().at(i);
    const auto t_min = min(t, x);
    const auto t_max = max(t, x);

    if ((lo_x > t_min && lo_x < t_max) || (t_min > lo_x && t_min < hi_x)) {
      o->getSolidSortB().push_back(t);
    }
  }

  o->getSolidSortC().clear();

  for (unsigned int i = 0; i < o->getSolidSortB().size(); ++i) {
    const auto &t = o->getSolidSortB().at(i);
    const auto t_min = min(t, y);
    const auto t_max = max(t, y);

    if ((lo_y > t_min && lo_y < t_max) || (t_min > lo_y && t_min < hi_y)) {
      o->getSolidSortC().push_back(t);
    }
  }

  o->getSolidSortB().clear();

  for (unsigned int i = 0; i < o->getSolidSortC().size(); ++i) {
    const auto &t = o->getSolidSortC().at(i);
    const auto t_min = min(t, z);
    const auto t_max = max(t, z);

    if ((lo_z > t_min && lo_z < t_max) || (t_min > lo_z && t_min < hi_z)) {
      o->getSolidSortB().push_back(t);
    }
  }
}

inline void getCollisionsTriangle(std::shared_ptr<Solid> o1,
                                  std::shared_ptr<Solid> o2) {
  o1->getSolidSortC().clear();
  o2->getSolidSortC().clear();

  auto n_o1 = glm::vec3(0.0);
  auto n_o2 = glm::vec3(0.0);

  for (int i = 0; i < o1->getSolidSortB().size(); ++i) {
    // auto collision = false;
    for (int j = 0; j < o2->getSolidSortB().size(); ++j) {
      const auto t1 = o1->getSolidSortB().at(i);
      const auto t2 = o2->getSolidSortB().at(j);

      if (max(t1, x) > min(t2, x))
        if (min(t1, y) < max(t2, y) && max(t1, y) > min(t2, y))
          if (min(t1, z) < max(t2, z) && max(t1, z) > min(t2, z)) {
            auto collision = false;

            // normal vector of triangle plane of t2
            const auto n_t2 = // t2->n;
                glm::normalize(glm::cross(glm::vec3(t2->b->pos - t2->a->pos),
                                          glm::vec3(t2->c->pos - t2->a->pos)));

            // calculate on which side of t2 each point of t1 is
            const auto side_a =
                glm::dot(n_t2, glm::vec3(t2->a->pos - t1->a->pos));
            const auto side_b =
                glm::dot(n_t2, glm::vec3(t2->a->pos - t1->b->pos));
            const auto side_c =
                glm::dot(n_t2, glm::vec3(t2->a->pos - t1->c->pos));

            /* if edge a-b of t1 crosses the plane of t2 (side_a and side_b have
             * opposite signs) */
            if (side_a <= 0 && side_b >= 0 || side_a >= 0 && side_b <= 0) {
              // edge a-b of t1 as normal vector
              const auto n = glm::normalize(t1->b->pos - t1->a->pos);
              // project the vertices of t2 on the subspace (plane) defined by n
              const auto p_a =
                  glm::vec3(t2->a->pos - glm::dot(t2->a->pos, n) * n);
              const auto p_b =
                  glm::vec3(t2->b->pos - glm::dot(t2->b->pos, n) * n);
              const auto p_c =
                  glm::vec3(t2->c->pos - glm::dot(t2->c->pos, n) * n);
              // project the edge a-b of t1 on the subspace (plane) defined by n
              const auto p_e_ab =
                  glm::vec3(t1->a->pos - glm::dot(t1->a->pos, n) * n);

              /* Check if the projected point p_e_ab lies inside the projected
               * triangle defined by p_a, p_b and p_c. In this case, the edge
               * a-b crossed the triangle and t1 and t2 must be colliding. */

              const auto n1 = glm::cross(p_b - p_e_ab, p_c - p_e_ab);
              const auto n2 = glm::cross(p_c - p_e_ab, p_a - p_e_ab);
              const auto n3 = glm::cross(p_a - p_e_ab, p_b - p_e_ab);

              const auto angle1 = glm::dot(n1, n2);
              const auto angle2 = glm::dot(n1, n3);

              if (angle1 > 0 && angle2 > 0) {
                // exit(0);
                collision = true;
              }
            } // repeat the same for the other 2 edges of t1
            else if (side_b <= 0 && side_c >= 0 || side_b >= 0 && side_c <= 0) {
              // edge a-b of t1 as normal vector
              const auto n = glm::normalize(t1->c->pos - t1->b->pos);
              // project the vertices of t2 on the subspace (plane) defined by n
              const auto p_a =
                  glm::vec3(t2->a->pos - glm::dot(t2->a->pos, n) * n);
              const auto p_b =
                  glm::vec3(t2->b->pos - glm::dot(t2->b->pos, n) * n);
              const auto p_c =
                  glm::vec3(t2->c->pos - glm::dot(t2->c->pos, n) * n);
              // project the edge a-b of t1 on the subspace (plane) defined by n
              const auto p_e_bc =
                  glm::vec3(t1->b->pos - glm::dot(t1->b->pos, n) * n);

              /* Check if the projected point p_e_ab lies inside the projected
               * triangle defined by p_a, p_b and p_c. In this case, the edge
               * a-b crossed the triangle and t1 and t2 must be colliding. */

              const auto n1 = glm::cross(p_b - p_e_bc, p_c - p_e_bc);
              const auto n2 = glm::cross(p_c - p_e_bc, p_a - p_e_bc);
              const auto n3 = glm::cross(p_a - p_e_bc, p_b - p_e_bc);

              const auto angle1 = glm::dot(n1, n2);
              const auto angle2 = glm::dot(n1, n3);

              if (angle1 > 0 && angle2 > 0) {
                collision = true;
              }
            } else if (side_c <= 0 && side_a >= 0 ||
                       side_c >= 0 && side_a <= 0) {
              // edge a-b of t1 as normal vector
              const auto n = glm::normalize(t1->a->pos - t1->c->pos);
              // project the vertices of t2 on the subspace (plane) defined by n
              const auto p_a =
                  glm::vec3(t2->a->pos - glm::dot(t2->a->pos, n) * n);
              const auto p_b =
                  glm::vec3(t2->b->pos - glm::dot(t2->b->pos, n) * n);
              const auto p_c =
                  glm::vec3(t2->c->pos - glm::dot(t2->c->pos, n) * n);
              // project the edge a-b of t1 on the subspace (plane) defined by n
              const auto p_e_ca =
                  glm::vec3(t1->c->pos - glm::dot(t1->c->pos, n) * n);

              /* Check if the projected point p_e_ab lies inside the projected
               * triangle defined by p_a, p_b and p_c. In this case, the edge
               * a-b crossed the triangle and t1 and t2 must be colliding. */

              const auto n1 = glm::cross(p_b - p_e_ca, p_c - p_e_ca);
              const auto n2 = glm::cross(p_c - p_e_ca, p_a - p_e_ca);
              const auto n3 = glm::cross(p_a - p_e_ca, p_b - p_e_ca);

              const auto angle1 = glm::dot(n1, n2);
              const auto angle2 = glm::dot(n1, n3);

              if (angle1 > 0 && angle2 > 0) {
                collision = true;
              }
            }

            if (collision) {
              const auto n_t1 = // t1->n;
                  glm::normalize(
                      glm::cross(glm::vec3(t1->b->pos - t1->a->pos),
                                 glm::vec3(t1->c->pos - t1->a->pos)));

              auto v_aa = glm::dot(n_t1, glm::vec3(t1->a->pos - t2->a->pos));
              auto v_ba = glm::dot(n_t1, glm::vec3(t1->a->pos - t2->b->pos));
              auto v_ca = glm::dot(n_t1, glm::vec3(t1->a->pos - t2->c->pos));
              auto max_t1 = (v_aa > v_ba && v_aa > v_ca)
                                ? v_aa
                                : (v_ba > v_ca ? v_ba : v_ca);
              // auto max_n1 = n_t1 * max_t1;

              // n_o1 = glm::length(max_n1) > glm::length(n_o1) ? max_n1 : n_o1;
              
              n_o1 = glm::normalize(n_o1 + n_t1);


              auto max_t2 = (side_a > side_b && side_a > side_c)
                                ? side_a
                                : (side_b > side_c ? side_b : side_c);
              auto max_n2 = n_t2 * max_t2;

              // n_o2 = glm::length(max_n2) > glm::length(n_o2) ? max_n2 : n_o2;

              n_o2 = glm::normalize(n_o2 + n_t2);
            }
          }
    }

    // if collision occured, add t1 to list of colliding triangles
    /*if (collision) {
      o1->getSolidSortC().push_back(o1->getSolidSortB().at(i));
      // o2->getSolidSortC().push_back(o2->getSolidSortB().at(j));
    }*/
  }

  o1->move(n_o2 * 0.6f);
  o2->move(n_o1 * 0.6f);
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
          // sortCollisionsTriangle(solidsort.at(k), solidsort.at(i));
          const auto lo_x = s1.pos.x - s1.rad <= s2.pos.x - s2.rad
                                ? s2.pos.x - s2.rad
                                : s1.pos.x - s1.rad;
          const auto hi_x = s1.pos.x + s1.rad >= s2.pos.x + s2.rad
                                ? s2.pos.x + s2.rad
                                : s1.pos.x + s1.rad;
          const auto lo_y = s1.pos.y - s1.rad <= s2.pos.y - s2.rad
                                ? s2.pos.y - s2.rad
                                : s1.pos.y - s1.rad;
          const auto hi_y = s1.pos.y + s1.rad >= s2.pos.y + s2.rad
                                ? s2.pos.y + s2.rad
                                : s1.pos.y + s1.rad;
          const auto lo_z = s1.pos.z - s1.rad <= s2.pos.z - s2.rad
                                ? s2.pos.z - s2.rad
                                : s1.pos.z - s1.rad;
          const auto hi_z = s1.pos.z + s1.rad >= s2.pos.z + s2.rad
                                ? s2.pos.z + s2.rad
                                : s1.pos.z + s1.rad;

          reduceCollisionsTriangle(lo_x, hi_x, lo_y, hi_y, lo_z, hi_z,
                                   solidsort.at(k));
          reduceCollisionsTriangle(lo_x, hi_x, lo_y, hi_y, lo_z, hi_z,
                                   solidsort.at(i));

          getCollisionsTriangle(solidsort.at(i), solidsort.at(k));

          // solidsort.at(i)->getSolidSortC().clear();
          if (!solidsort.at(i)->getSolidSortC().isEmpty()) {
            // std::cout << "exit\n";
            // exit(0);
          }
        }
      }
    }
  }
}

} // namespace rpy