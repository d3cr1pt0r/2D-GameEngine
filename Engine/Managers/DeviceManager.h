#pragma once

#include <glew.h>

#include "BaseManager.h"
#include <SDL.h>

namespace Engine {

	class DeviceManager : public BaseManager {

	public:
		DeviceManager();
		~DeviceManager();

		void createWindow(const char *title, int width, int height);
		void swapBuffers();

		int getWindowWidth();
		int getWindowHeight();

		void setWindowSize(int width, int height);
		void setWindowTitle(const char* title);

		void setViewport(GLint x, GLint y, GLsizei width, GLsizei height);

	private:
		SDL_Window *sdl_window_;
		SDL_GLContext sdl_glcontext_;
	};

	extern DeviceManager* pDeviceManager;

}