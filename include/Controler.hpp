/*
 * Controler.h
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_CONTROLER_HPP_
#define INCLUDE_CONTROLER_HPP_

#include <View.hpp>

class Controler {
private:
	bool keyW = false;
	bool keyA = false;
	bool keyS = false;
	bool keyD = false;

	View view;
	Model model;
	Player* player;

public:
	Controler();
	virtual ~Controler();

	void run();
};

#endif /* INCLUDE_CONTROLER_HPP_ */
