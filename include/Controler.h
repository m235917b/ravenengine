/*
 * Controler.h
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_CONTROLER_H_
#define INCLUDE_CONTROLER_H_

#include <View.h>
#include <Model.h>
#include <WorldObject.h>
#include <Player.hpp>

class Controler {
private:
	bool keyW = false;
	bool keyA = false;
	bool keyS = false;
	bool keyD = false;

	View view;
	Model model;
	std::shared_ptr<Player> player;

public:
	Controler();
	virtual ~Controler();

	void run();
};

#endif /* INCLUDE_CONTROLER_H_ */
