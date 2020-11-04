/*
 * Controler.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#include <Controler.h>

#include <SDL2\SDL.h>
#include <gl\glew.h>
#include <SDL2\SDL_opengl.h>
#include <gl\glu.h>
#include <glm\glm.hpp>
#include <glm\gtx\rotate_vector.hpp>
#include <iostream>
#include <stdio.h>

Controler::Controler() :
		view(), model(), player(model.getPlayer()) {
	SDL_SetRelativeMouseMode(SDL_TRUE);
}

Controler::~Controler() {

}

void Controler::run() {
	bool quit = false;
	//Event handler
	SDL_Event e;

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
				player.get()->rotateX(-e.motion.xrel * 0.001f);
				player.get()->rotateY(-e.motion.yrel * 0.001f);
				break;
			}
		}

		if (keyW) {
			player.get()->moveForeward(0.5f);
		}
		if (keyS) {
			player.get()->moveForeward(-0.5f);
		}
		if (keyD) {
			player.get()->moveLeft(0.5f);
		}
		if (keyA) {
			player.get()->moveLeft(-0.5f);
		}

		view.render(model);
	}

	SDL_Quit();
}

