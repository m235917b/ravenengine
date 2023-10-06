/*
 * View.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>
#include <View.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

/*
 * SDL and OpenGL are initialized when the view object gets created.
 * A SDL window is created, that can then be used for rendering
 * in the render() method.
 */
View::View() {
	SCREEN_WIDTH = 2560;
	SCREEN_HEIGHT = 1440;

	SDL_Init(SDL_INIT_EVERYTHING);

	// enable msaa antialiasing
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 16);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	glEnable(GL_MULTISAMPLE);

	// create SDL OpenGL window
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
			SDL_GL_CONTEXT_PROFILE_CORE);

	window = SDL_CreateWindow("Game", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	gContext = SDL_GL_CreateContext(window);

	// initialize glew
	glewInit();

	SDL_GL_SetSwapInterval(0);

	// enable depth test
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// enable face culling; show only counter clock-wise faces
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	// projection matrix : 45 degrees field of view, 4:3 ratio, display range : 0.1 unit <-> 100 units
	projection = glm::perspective(glm::radians(45.0f),
			(float) SCREEN_WIDTH / (float) SCREEN_HEIGHT, 0.1f, 10000.0f);

	// camera matrix
	v = glm::mat4(0.0f);
}

View::View(const View &that) {
	if (this != &that) {
		this->SCREEN_WIDTH = that.SCREEN_WIDTH;
		this->SCREEN_HEIGHT = that.SCREEN_HEIGHT;

		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 16);
		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
		glEnable(GL_MULTISAMPLE);

		SDL_Init(SDL_INIT_VIDEO);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
				SDL_GL_CONTEXT_PROFILE_CORE);

		window = SDL_CreateWindow("Game", 500, 500, SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

		gContext = SDL_GL_CreateContext(window);

		glewInit();

		SDL_GL_SetSwapInterval(0);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);

		this->projection = that.projection;
		this->v = that.v;
	}
}

View& View::operator=(const View &that) {
	if (this != &that) {
		this->SCREEN_WIDTH = that.SCREEN_WIDTH;
		this->SCREEN_HEIGHT = that.SCREEN_HEIGHT;

		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 16);
		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
		glEnable(GL_MULTISAMPLE);

		SDL_Init(SDL_INIT_VIDEO);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
				SDL_GL_CONTEXT_PROFILE_CORE);

		window = SDL_CreateWindow("Game", 500, 500, SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

		gContext = SDL_GL_CreateContext(window);

		glewInit();

		SDL_GL_SetSwapInterval(0);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);

		this->projection = that.projection;
		this->v = that.v;
	}

	return *this;
}

View::~View() {
	SDL_DestroyWindow(window);
}

// rendering loop for everything visible on the screen
void View::render(Model &model) {
	// adjust camera to the player position and orientation
	v = glm::lookAt(
			model.getPlayer()->getPos() - 10.0f * model.getPlayer()->getLook(),
			model.getPlayer()->getPos() + model.getPlayer()->getLook(),
			model.getPlayer()->getUp());

	// clear color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// draw objects stored in the model
	std::for_each(model.firstObject(), model.lastObject(), [this](auto &o) {
		o->render(projection, v);
	});
	std::for_each(model.firstSolid(), model.lastSolid(), [this](auto &o) {
		o->render(projection, v);
	});

	//update the window
	SDL_GL_SwapWindow(window);
}
