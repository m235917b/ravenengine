/*
 * main.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: marvi
 */

#include <Controler.hpp>
#include <iostream>
#include <vector>

int main(int argc, char *args[]) {
	std::cout << "test\n";

	Controler c = Controler();

	c.run();

	return 0;
}
