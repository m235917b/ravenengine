/*
 * View.h
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#ifndef INCLUDE_VIEW_HPP_
#define INCLUDE_VIEW_HPP_

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <Model.hpp>

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

#endif /* INCLUDE_VIEW_HPP_ */
