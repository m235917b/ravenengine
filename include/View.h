/*
 * View.h
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_VIEW_H_
#define INCLUDE_VIEW_H_

#include <SDL2\SDL.h>
#include <gl\glew.h>
#include <SDL2\SDL_opengl.h>
#include <gl\glu.h>
#include <glm\glm.hpp>
#include <glm\gtx\rotate_vector.hpp>
#include <iostream>
#include <stdio.h>

#include <Model.h>
#include <Player.hpp>
#include <CubeTest.h>

class View {
private:
	//Screen dimension constants
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	SDL_Window *window;

	SDL_GLContext gContext;

	glm::mat4 projection;
	glm::mat4 v;

	glm::vec3 lookAt = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 pos = glm::vec3(0.0f, 0.0f, -1.0f);

public:
	View();
	View(const View &that);
	View& operator=(const View &that);
	virtual ~View();

	void render(Model &model);
};

#endif /* INCLUDE_VIEW_H_ */
