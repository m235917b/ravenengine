/*
 * AnimTest.h
 *
 *  Created on: Nov 1, 2020
 *      Author: marvi
 */

#ifndef ANIMTEST_H_
#define ANIMTEST_H_

#include <ComposedObject.hpp>

class AnimTest : public ComposedObject {
private:
	int getLowKeyframe(int frame, int index = 0);

protected:
	void run();

public:
	AnimTest(float posX, float posY, float posZ);
	~AnimTest();
};

#endif /* ANIMTEST_H_ */
