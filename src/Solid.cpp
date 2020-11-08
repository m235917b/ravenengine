/*
 * Solid.cpp
 *
 *  Created on: Nov 5, 2020
 *      Author: marvi
 */

#include <Solid.hpp>

#include <iostream>

using namespace rpy;

Solid::Solid(float posX, float posY, float posZ) :
		WorldObject(posX, posY, posZ) {

}

Solid::~Solid() {

}

inline void Solid::setSphere() {
	// approximate the polygon radius
	auto dist = 0.0f;
	auto dist_old = 0.0f;
	auto point1 = polygon.front().a;
	auto point2 = polygon.front().a;

	do {
		dist = 0.0f;
		dist_old = glm::distance(point1, point2);
		point1 = point2;
		for (auto i = polygon.size() - 1; i > 0; --i) {
			auto point = polygon.at(i).a;
			if (glm::distance(point1, point) > dist) {
				dist = glm::distance(point1, point);
				point2 = point;
			}
			point = polygon.at(i).b;
			if (glm::distance(point1, point) > dist) {
				dist = glm::distance(point1, point);
				point2 = point;
			}
			point = polygon.at(i).c;
			if (glm::distance(point1, point) > dist) {
				dist = glm::distance(point1, point);
				point2 = point;
			}
		}
	} while (dist_old < dist);

	bs.rad = glm::distance(point1, point2) / 2.0f;
	bs.pos = point1 + (point2 - point1) / 2.0f;
}

void Solid::fillTriangles(std::vector<GLfloat> &vertices,
		std::vector<GLfloat> &normals, std::vector<GLuint> &indices) {
	for (auto i = indices.size() - 1; i >= 3; i -= 3) {
		auto t = triangle();

		t.a.x = vertices.at(indices.at(i));
		t.a.y = vertices.at(indices.at(i) + 1);
		t.a.z = vertices.at(indices.at(i) + 2);

		t.b.x = vertices.at(indices.at(i - 1));
		t.b.y = vertices.at(indices.at(i - 1) + 1);
		t.b.z = vertices.at(indices.at(i - 1) + 2);

		t.c.x = vertices.at(indices.at(i - 2));
		t.c.y = vertices.at(indices.at(i - 2) + 1);
		t.c.z = vertices.at(indices.at(i - 2) + 2);

		auto n1 = glm::vec3(normals.at(indices.at(i)),
				normals.at(indices.at(i) + 1), normals.at(indices.at(i) + 2));
		auto n2 = glm::vec3(normals.at(indices.at(i - 1)),
				normals.at(indices.at(i - 1) + 1),
				normals.at(indices.at(i - 1) + 2));
		auto n3 = glm::vec3(normals.at(indices.at(i - 2)),
				normals.at(indices.at(i - 2) + 1),
				normals.at(indices.at(i - 2) + 2));

		t.n = (n1 + n2 + n3) / 3.0f;

		polygon.emplace_back(t);
	}

	setSphere();
}

sphere Solid::getSphere() {
	return bs;
}

void Solid::transformSphere(glm::mat4 m) {
	bs.pos.x = (m * glm::vec4(bs.pos, 1.0f)).x;
	bs.pos.y = (m * glm::vec4(bs.pos, 1.0f)).y;
	bs.pos.z = (m * glm::vec4(bs.pos, 1.0f)).z;
}

void Solid::moveSphere(glm::vec3 v) {
	bs.pos += v;
}

void Solid::setSpherePos(glm::vec3 v) {
	bs.pos = v;
}

