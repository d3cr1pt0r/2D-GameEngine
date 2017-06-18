#pragma once
#include <SDL.h>

namespace Engine {

	class Window {

	public:
		Window(const char *title, int width, int height);
		~Window();

		bool init();
		void update();
		void swapBuffers();
		bool isOpen();
		void destroy();

	public:
		static int width_;
		static int height_;

	private:
		SDL_Window *window_;
		SDL_GLContext context_;

		const char *title_;
		bool is_open_;

	};
}
