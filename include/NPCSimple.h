/*
 * NPCSimple.h
 *
 *  Created on: Oct 31, 2020
 *      Author: marvi
 */

#ifndef NPCSIMPLE_H_
#define NPCSIMPLE_H_

#include <WorldObject.h>

class NPCSimple: public WorldObject {
private:

protected:
	std::vector<GLfloat> getVertexData();
	std::vector<GLfloat> getNormalData();
	std::vector<GLfloat> getTexData();
	std::vector<GLuint> getIndexData();

	void run();

public:
	NPCSimple(float posX, float posY, float posZ);
};

#endif /* NPCSIMPLE_H_ */
