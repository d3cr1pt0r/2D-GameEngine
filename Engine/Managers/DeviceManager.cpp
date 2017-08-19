#include "DeviceManager.h"

#include <iostream>

#include "LogManager.h"

namespace Engine {

	DeviceManager* pDeviceManager = nullptr;

	DeviceManager::DeviceManager() {
		pLogManager->logDebug("DeviceManager", "initialized");

		pDeviceManager = this;
	}

	DeviceManager::~DeviceManager() {
		pLogManager->logDebug("DeviceManager", "destroyed");

		SDL_GL_DeleteContext(sdl_glcontext_);
		SDL_DestroyWindow(sdl_window_);

		pDeviceManager = nullptr;
	}

	void DeviceManager::createWindow(const char *title, int width, int height) {
		// init window
		sdl_window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

		if (sdl_window_ == NULL) {
			std::cout << "SDL failed to create window! SDL Error: " << SDL_GetError() << std::endl;
		}

		// init opengl context
		sdl_glcontext_ = SDL_GL_CreateContext(sdl_window_);

		if (sdl_glcontext_ == NULL) {
			std::cout << "SDL failed to create OpenGL context! SDL Error: " << SDL_GetError() << std::endl;
		}

		//std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

		// disable deprecated functions
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		// set OpenGL version to 3.3
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

		// enable double buffering
		// you may need to change this to 16 or 32 for your system
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 32);

		// init glew
		GLenum error = glewInit();

		if (error != GLEW_OK) {
			std::cout << "Glew failed to initialize! GLEW Error: " << glewGetErrorString(error) << std::endl;
		}

		setViewport(0, 0, width, height);
	}

	void DeviceManager::swapBuffers() {
		SDL_GL_SwapWindow(sdl_window_);
	}

	int DeviceManager::getWindowWidth() {
		int width;
		int height;

		SDL_GetWindowSize(sdl_window_, &width, &height);

		return width;
	}

	int DeviceManager::getWindowHeight() {
		int width;
		int height;

		SDL_GetWindowSize(sdl_window_, &width, &height);

		return height;
	}

	void DeviceManager::setWindowSize(int width, int height) {
		SDL_SetWindowSize(sdl_window_, width, height);
	}

	void DeviceManager::setWindowTitle(const char* title) {
		SDL_SetWindowTitle(sdl_window_, title);
	}

	void DeviceManager::setViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
		glViewport(x, y, width, height);
	}
}