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

public:
	AnimTest(float posX, float posY, float posZ);
	~AnimTest();

	void run() override;
};

#endif /* ANIMTEST_H_ */
