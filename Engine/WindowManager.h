#pragma once
#include "BaseManager.h"
#include <SDL.h>

namespace Engine {

	class WindowManager : public BaseManager {

	public:
		void init() override;
		void destroy() override;

		void create(const char *title, int width, int height);
		void swapBuffers();

		inline const SDL_Window* getWindow() const { return sdl_window_; }
		inline const SDL_GLContext& getOpenGLContext() const { return sdl_glcontext_; }

		inline const int& getWidth() const { return width_; }
		inline const int& getHeight() const { return height_; }
		inline const char* getTitle() const { return title_; }

	private:
		SDL_Window *sdl_window_;
		SDL_GLContext sdl_glcontext_;

		int width_;
		int height_;
		const char *title_;
	};
}

