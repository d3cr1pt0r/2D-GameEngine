#include "Window.h"

#include <iostream>
#include <glew.h>

#include "Input.h"
#include "ErrorLog.h"

namespace Engine {
	int Window::width_;
	int Window::height_;

	Window::Window(const char *title, int width, int height) : title_(title) {
		width_ = width;
		height_ = height;
	}

	Window::~Window() {
	}

	bool Window::init() {
		// init window
		window_ = SDL_CreateWindow(title_, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
		
		if (window_ == NULL) {
			std::cout << "SDL failed to create window! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}

		// init opengl context
		context_ = SDL_GL_CreateContext(window_);

		if (context_ == NULL) {
			std::cout << "SDL failed to create OpenGL context! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}

		std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

		// disable deprecated functions
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		// set OpenGL version to 3.2
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

		// enable double buffering
		// you may need to change this to 16 or 32 for your system
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		// init glew
		GLenum error = glewInit();

		if (error != GLEW_OK) {
			std::cout << "Glew failed to initialize! GLEW Error: " << glewGetErrorString(error) << std::endl;
			return false;
		}

		is_open_ = true;

		return true;
	}

	void Window::update() {
		if (Input::getQuitRequested()) {
			is_open_ = false;
			return;
		}
	}

	void Window::clear() {
		glClearDepth(1.0);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::render() {
		SDL_GL_SwapWindow(window_);
	}

	bool Window::isOpen() {
		return is_open_;
	}

	void Window::destroy() {
		SDL_GL_DeleteContext(context_);
		SDL_DestroyWindow(window_);
	}
}