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

public:
	NPCSimple(float posX, float posY, float posZ);

	void run() override;
};

#endif /* NPCSIMPLE_H_ */
