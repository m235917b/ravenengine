/*
 * NPCSimple.h
 *
 *  Created on: Oct 31, 2020
 *      Author: marvi
 */

#ifndef NPCSIMPLE_H_
#define NPCSIMPLE_H_

#include <ComposedObject.hpp>

class NPCSimple: public ComposedObject {
private:

protected:
	void run();

public:
	NPCSimple(float posX, float posY, float posZ);
};

#endif /* NPCSIMPLE_H_ */
