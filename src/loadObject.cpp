/*
 * loadObj.cpp
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#include "Solid.hpp"
#include <Animation.hpp>
#include <fstream>
#include <loadObject.hpp>

#include <iostream>

template<typename T>
int findElem(std::vector<T> &v, std::function<bool(T)> f) {
	for (unsigned int i = 0; i < v.size(); ++i) {
		if (f(v.at(i))) {
			return i;
		}
	}

	return -1;
}

compObj loadObject(const std::string filename) {
	auto out = compObj();
	out.meshes = std::vector<Mesh>();
	out.bones = std::vector<bone>();

	std::ifstream file(filename);
	std::string str;

	auto vertexData = std::vector<GLfloat>();
	auto normalData = std::vector<GLfloat>();
	auto texData = std::vector<GLfloat>();
	auto indexData = std::vector<GLuint>();
	auto tex = std::string();
	auto name = std::string();

	bone b = bone();
	b.name = "";

	int ctr = 0;
	int mode = 0;

	while (std::getline(file, str)) {
		if (str.find("mesh", 0) == 0) {
			mode = 0;

			if (name != "") {
				out.meshes.push_back(
						Mesh(vertexData, normalData, texData, indexData, tex,
								name));
			}

			vertexData = std::vector<GLfloat>();
			normalData = std::vector<GLfloat>();
			texData = std::vector<GLfloat>();
			indexData = std::vector<GLuint>();
			tex = std::string();
			name = str.substr(str.find('=', 0) + 1, str.length());
		} else if (str.find("skeleton", 0) == 0) {
			mode = 1;
			if (name != "") {
				out.meshes.push_back(
						Mesh(vertexData, normalData, texData, indexData, tex,
								name));
			}
		} else if (str.find("parentbones", 0) == 0) {
			mode = 2;
			if (b.name != "") {
				out.bones.push_back(b);
			}
		} else {
			switch (mode) {
			case 0:
				if (str.at(0) == 'i') {
					indexData.push_back(std::stoi(str.substr(1, str.length())));
				} else {
					switch (ctr) {
					case 0:
						indexData.push_back(std::stoi(str));
						break;
					case 1:
						vertexData.push_back(std::stof(str));
						break;
					case 2:
						vertexData.push_back(std::stof(str));
						break;
					case 3:
						vertexData.push_back(std::stof(str));
						break;
					case 4:
						normalData.push_back(std::stof(str));
						break;
					case 5:
						normalData.push_back(std::stof(str));
						break;
					case 6:
						normalData.push_back(std::stof(str));
						break;
					case 7:
						texData.push_back(std::stof(str));
						break;
					case 8:
						texData.push_back(std::stof(str));
						break;
					}

					ctr = ctr >= 8 ? 0 : ctr + 1;
				}
				break;
			case 1:
				if (b.name != "") {
					out.bones.push_back(b);
				}
				b = bone();
				if (str.find("armature mat", 0) == 0) {
					auto arm_mat = glm::mat4();
					for (int i = 0; i < 4; ++i) {
						for (int j = 0; j < 4; ++j) {
							std::getline(file, str);
							arm_mat[i][j] = std::stof(str);
						}
					}
					out.arm_mat = arm_mat;
				} else {
					if (str.find("p ", 0) == 0) {
						b.name = str.substr(str.find(" ", 0) + 1, str.length());
						std::getline(file, str);
						b.parent = findElem<bone>(out.bones,
								[&str](const bone &n) {
									return n.name == str;
								});
					} else {
						b.name = str.substr(0, str.length());
					}
					b.mat = glm::mat4();
					for (int i = 0; i < 4; ++i) {
						for (int j = 0; j < 4; ++j) {
							std::getline(file, str);
							b.mat[i][j] = std::stof(str);
						}
					}
				}
				break;
			case 2:
				auto mesh = findElem<Mesh>(out.meshes, [&str](const Mesh &m) {
					return m.getName() == str;
				});
				std::getline(file, str);
				auto parent = findElem<bone>(out.bones, [&str](const bone &n) {
					return n.name == str;
				});

				if (mesh > -1 && parent > -1) {
					out.meshes.at(mesh).addBone(parent);
				}
				break;
			}
		}
	}

	return out;
}

rpy::solidData loadSolid(const std::string filename) {
	auto out = rpy::solidData();

	std::ifstream file(filename);
	std::string str;

	auto vertexData = std::vector<GLfloat>();
	auto normalData = std::vector<GLfloat>();
	auto texData = std::vector<GLfloat>();
	auto indexData = std::vector<GLuint>();
	auto name = std::string();

	int ctr = 0;
	int mode = 0;

	while (std::getline(file, str)) {
		if (str.find("mesh", 0) == 0 || str.find("end", 0) == 0) {
			mode = 0;

			if (name != "") {
				out.vertices.insert(out.vertices.begin(), vertexData.begin(), vertexData.end());
				out.normals.insert(out.normals.begin(), normalData.begin(), normalData.end());
				out.indices.insert(out.indices.begin(), indexData.begin(), indexData.end());
				out.texData.insert(out.texData.begin(), texData.begin(), texData.end());

				std::cout << "hello\n";
  				for (auto v : out.vertices) {
    				std::cout << v << "\n";
  				}
  				std::cout << "hello\n";
			}

			vertexData = std::vector<GLfloat>();
			normalData = std::vector<GLfloat>();
			texData = std::vector<GLfloat>();
			indexData = std::vector<GLuint>();
			name = str.substr(str.find('=', 0) + 1, str.length());
		} else {
			switch (mode) {
			case 0:
				if (str.at(0) == 'i') {
					indexData.push_back(std::stoi(str.substr(1, str.length())));
				} else {
					switch (ctr) {
					case 0:
						indexData.push_back(std::stoi(str));
						break;
					case 1:
						vertexData.push_back(std::stof(str));
						break;
					case 2:
						vertexData.push_back(std::stof(str));
						break;
					case 3:
						vertexData.push_back(std::stof(str));
						break;
					case 4:
						normalData.push_back(std::stof(str));
						break;
					case 5:
						normalData.push_back(std::stof(str));
						break;
					case 6:
						normalData.push_back(std::stof(str));
						break;
					case 7:
						texData.push_back(std::stof(str));
						break;
					case 8:
						texData.push_back(std::stof(str));
						break;
					}

					ctr = ctr >= 8 ? 0 : ctr + 1;
				}
				break;
			}
		}
	}

	return out;
}
