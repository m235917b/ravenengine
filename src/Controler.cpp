/*
 * Controler.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#include <Controler.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <rpy.hpp>
#include <iostream>

Controler::Controler() :
		view(), model(), player(model.getPlayer()) {
	SDL_SetRelativeMouseMode(SDL_TRUE);
	rpy::initSolids(model.getSolids());
}

Controler::~Controler() {

}

void Controler::run() {
	bool quit = false;
	//Event handler
	SDL_Event e;

	Uint32 ticks = SDL_GetTicks();
	unsigned int frameCtr = 0;

	while (!quit) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;

			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE:
					quit = true;
					break;

				case SDLK_w:
					keyW = true;
					break;

				case SDLK_a:
					keyA = true;
					break;

				case SDLK_s:
					keyS = true;
					break;

				case SDLK_d:
					keyD = true;
					break;
				}
				break;

			case SDL_KEYUP:
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE:
					quit = false;
					break;

				case SDLK_w:
					keyW = false;
					break;

				case SDLK_a:
					keyA = false;
					break;

				case SDLK_s:
					keyS = false;
					break;

				case SDLK_d:
					keyD = false;
					break;
				}
				break;

			case SDL_MOUSEMOTION:
				player->rotateX(-e.motion.xrel * 0.001f);
				player->rotateY(-e.motion.yrel * 0.001f);
				break;
			}
		}

		if (keyW) {
			player->moveForeward(0.5f);
		}
		if (keyS) {
			player->moveForeward(-0.5f);
		}
		if (keyD) {
			player->moveLeft(0.5f);
		}
		if (keyA) {
			player->moveLeft(-0.5f);
		}

		rpy::handleCollisions();

		view.render(model);

		++frameCtr;
		if (SDL_GetTicks() - ticks > 1000) {
			std::cout << "FPS: " << frameCtr << "\n";
			ticks = SDL_GetTicks();
			frameCtr = 0;
		}
	}

	SDL_Quit();
}
