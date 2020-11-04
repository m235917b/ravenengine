/*
 * loadObject.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: marvi
 */

#include <loadObject.h>
#include <fstream>

#include <iostream>
#include <algorithm>

std::vector<GLfloat> getVertices(const char *filename) {
	std::ifstream file(filename);
	std::string str;
	std::vector<GLfloat> out = std::vector<GLfloat>();

	while (std::getline(file, str)) {
		if (str.at(0) == 'v' && str.at(1) == ' ') {
			int beg = 0;
			int end = str.find(' ', 0);

			for (int i = 0; i < 3; ++i) {
				beg = ++end;
				end = str.find(' ', beg);
				out.push_back(std::stof(str.substr(beg, end - beg)));
			}
		}
	}

	file.close();

	return out;
}

std::vector<GLfloat> getNormals(const char *filename) {
	std::ifstream file(filename);
	std::string str;
	std::vector<GLfloat> out = std::vector<GLfloat>();

	while (std::getline(file, str)) {
		if (str.at(0) == 'v' && str.at(1) == 'n') {
			int beg = 0;
			int end = str.find(' ', 0);

			for (int i = 0; i < 3; ++i) {
				beg = ++end;
				end = str.find(' ', beg);
				out.push_back(std::stof(str.substr(beg, end - beg)));
			}
		}
	}

	file.close();

	return out;
}

std::vector<GLuint> getIndices(const char *filename) {
	std::ifstream file(filename);
	std::string str;
	std::vector<GLuint> out = std::vector<GLuint>();

	while (std::getline(file, str)) {
		if (str.at(0) == 'f' && str.at(1) == ' ') {
			int beg = 0;
			int end = str.find(' ', 0);

			for (int i = 0; i < 3; ++i) {
				beg = ++end;
				end = str.find(' ', beg);
				out.push_back(
						std::stoi(str.substr(beg, str.find('/', beg) - beg))
								- 1);
			}
		}
	}

	file.close();

	return out;
}

std::vector<GLfloat> getTexCoords(const char *filename) {
	std::ifstream file(filename);
	std::string str;
	std::vector<GLfloat> out = std::vector<GLfloat>();

	while (std::getline(file, str)) {
		if (str.at(0) == 'v' && str.at(1) == 't') {
			int beg = 0;
			int end = str.find(' ', 0);

			for (int i = 0; i < 2; ++i) {
				beg = ++end;
				end = str.find(' ', beg);
				out.push_back(std::stof(str.substr(beg, end - beg)));
			}
		}
	}

	file.close();

	return out;
}

int findElem(std::vector<std::string> &v, std::string &comp) {
	for (unsigned int i = 0; i < v.size(); ++i) {
		if (v.at(i) == comp) {
			return i;
		}
	}

	return -1;
}

objData getObject(const char *filename) {
	objData out;

	std::vector<GLfloat> v = std::vector<GLfloat>();
	std::vector<GLfloat> n = std::vector<GLfloat>();
	std::vector<GLfloat> t = std::vector<GLfloat>();
	std::vector<GLuint> indexV = std::vector<GLuint>();
	std::vector<GLuint> indexT = std::vector<GLuint>();
	std::vector<GLuint> indexN = std::vector<GLuint>();

	std::ifstream file(filename);
	std::string str;

	while (std::getline(file, str)) {
		if (str.at(0) == 'v' && str.at(1) == ' ') {
			int beg = 0;
			int end = str.find(' ', 0);

			for (int i = 0; i < 3; ++i) {
				beg = ++end;
				end = str.find(' ', beg);
				v.push_back(std::stof(str.substr(beg, end - beg)));
			}
		} else if (str.at(0) == 'v' && str.at(1) == 'n') {
			int beg = 0;
			int end = str.find(' ', 0);

			for (int i = 0; i < 3; ++i) {
				beg = ++end;
				end = str.find(' ', beg);
				n.push_back(std::stof(str.substr(beg, end - beg)));
			}
		} else if (str.at(0) == 'v' && str.at(1) == 't') {
			int beg = 0;
			int end = str.find(' ', 0);

			for (int i = 0; i < 2; ++i) {
				beg = ++end;
				end = str.find(' ', beg);
				t.push_back(std::stof(str.substr(beg, end - beg)));
			}
		} else if (str.at(0) == 'f' && str.at(1) == ' ') {
			int beg = 0;
			int end = str.find(' ', 0);

			for (int i = 0; i < 3; ++i) {
				beg = ++end;
				end = str.find(' ', beg);

				int begIndex = beg;
				int endIndex = str.find('/', begIndex);
				indexV.push_back(
						std::stoi(str.substr(begIndex, endIndex - begIndex))
								- 1);
				begIndex = ++endIndex;
				endIndex = str.find('/', begIndex);
				indexT.push_back(
						std::stoi(str.substr(begIndex, endIndex - begIndex))
								- 1);
				begIndex = ++endIndex;
				indexN.push_back(
						std::stoi(str.substr(begIndex, end - begIndex)) - 1);
			}
		}
	}

	file.close();

	out.v = std::vector<GLfloat>();
	out.n = std::vector<GLfloat>();
	out.t = std::vector<GLfloat>();
	out.i = std::vector<GLuint>();

	std::vector<std::string> tracker = std::vector<std::string>();

	unsigned int indexCtr = 0;

	for (unsigned int i = 0; i < indexV.size(); ++i) {
		std::string track = std::to_string(indexV.at(i)) + " "
				+ std::to_string(indexN.at(i)) + " "
				+ std::to_string(indexT.at(i));

		int find = findElem(tracker, track);

		if (find != -1) {
			out.i.push_back(find);
		} else {
			out.i.push_back(indexCtr++);

			out.v.push_back(v.at(indexV.at(i) * 3));
			out.v.push_back(v.at(indexV.at(i) * 3 + 1));
			out.v.push_back(v.at(indexV.at(i) * 3 + 2));

			out.n.push_back(n.at(indexN.at(i) * 3));
			out.n.push_back(n.at(indexN.at(i) * 3 + 1));
			out.n.push_back(n.at(indexN.at(i) * 3 + 2));

			out.t.push_back(t.at(indexT.at(i) * 2));
			out.t.push_back(1 - t.at(indexT.at(i) * 2 + 1));

			tracker.push_back(track);
		}
	}

	return out;
}
