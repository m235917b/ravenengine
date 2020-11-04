/*
 * View.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: marvi
 */

#include <View.h>
#include <algorithm>

View::View() {
	SCREEN_WIDTH = 1820;
	SCREEN_HEIGHT = 1024;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
			SDL_GL_CONTEXT_PROFILE_CORE);

	window = SDL_CreateWindow("Game", 500, 500, SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	//Create context
	gContext = SDL_GL_CreateContext(window);
	//Initialize GLEW
	//glewExperimental = GL_TRUE;
	glewInit();

	SDL_GL_SetSwapInterval(1);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	glEnable(GL_CULL_FACE); // cull face
	glCullFace(GL_BACK); // cull back face
	glFrontFace(GL_CCW); // GL_CCW for counter clock-wise

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	projection = glm::perspective(glm::radians(45.0f),
			(float) SCREEN_WIDTH / (float) SCREEN_HEIGHT, 0.1f, 1000.0f);

	// Camera matrix
	v = glm::mat4(0.0f);
}

View::View(const View &that) {
	if (this != &that) {
		this->SCREEN_WIDTH = that.SCREEN_WIDTH;
		this->SCREEN_HEIGHT = that.SCREEN_HEIGHT;

		SDL_Init(SDL_INIT_VIDEO);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
				SDL_GL_CONTEXT_PROFILE_CORE);

		window = SDL_CreateWindow("Game", 500, 500, SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

		gContext = SDL_GL_CreateContext(window);

		glewInit();

		SDL_GL_SetSwapInterval(1);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		glEnable(GL_CULL_FACE); // cull face
		glCullFace(GL_BACK); // cull back face
		glFrontFace(GL_CCW); // GL_CCW for counter clock-wise

		this->projection = that.projection;
		this->v = that.v;
	}
}

View& View::operator=(const View &that) {
	if (this != &that) {
		this->SCREEN_WIDTH = that.SCREEN_WIDTH;
		this->SCREEN_HEIGHT = that.SCREEN_HEIGHT;

		SDL_Init(SDL_INIT_VIDEO);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
				SDL_GL_CONTEXT_PROFILE_CORE);

		window = SDL_CreateWindow("Game", 500, 500, SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

		gContext = SDL_GL_CreateContext(window);

		glewInit();

		SDL_GL_SetSwapInterval(1);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		glEnable(GL_CULL_FACE); // cull face
		glCullFace(GL_BACK); // cull back face
		glFrontFace(GL_CCW); // GL_CCW for counter clock-wise

		this->projection = that.projection;
		this->v = that.v;
	}

	return *this;
}

View::~View() {
	SDL_DestroyWindow(window);
}

void View::render(Model &model) {
	v = glm::lookAt(
			model.getPlayer().get()->getPos()
					- 10.0f * model.getPlayer().get()->getLook(),
			model.getPlayer().get()->getPos()
					+ model.getPlayer().get()->getLook(),
			model.getPlayer().get()->getUp());

	//Clear color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	std::for_each(model.firstObject(), model.lastObject(),
			[this](auto const &o) {
				o->render(projection, v);
			});

	SDL_GL_SwapWindow(window);
}

