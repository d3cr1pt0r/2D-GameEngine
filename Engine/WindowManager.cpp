#include "WindowManager.h"
#include "Manager.h"
#include <glew.h>

namespace Engine {

	void WindowManager::init() {
		pLogManager->logDebug("WindowManager", "initialized");
	}

	void WindowManager::destroy() {
		pLogManager->logDebug("WindowManager", "destroyed");

		SDL_GL_DeleteContext(sdl_glcontext_);
		SDL_DestroyWindow(sdl_window_);
	}

	void WindowManager::create(const char *title, int width, int height) {
		title_ = title;
		width_ = width;
		height_ = height;

		// init window
		sdl_window_ = SDL_CreateWindow(title_, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

		if (sdl_window_ == NULL) {
			std::cout << "SDL failed to create window! SDL Error: " << SDL_GetError() << std::endl;
		}

		// init opengl context
		sdl_glcontext_ = SDL_GL_CreateContext(sdl_window_);

		if (sdl_glcontext_ == NULL) {
			std::cout << "SDL failed to create OpenGL context! SDL Error: " << SDL_GetError() << std::endl;
		}

		std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

		// disable deprecated functions
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		// set OpenGL version to 3.2
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

		// enable double buffering
		// you may need to change this to 16 or 32 for your system
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		// init glew
		GLenum error = glewInit();

		if (error != GLEW_OK) {
			std::cout << "Glew failed to initialize! GLEW Error: " << glewGetErrorString(error) << std::endl;
		}
	}
	void WindowManager::swapBuffers() {
		SDL_GL_SwapWindow(sdl_window_);
	}
}