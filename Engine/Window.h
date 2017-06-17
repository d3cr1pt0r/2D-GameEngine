#pragma once
#include <SDL.h>

namespace Engine {

	class Window {

	public:
		Window(const char *title, int width, int height);
		~Window();

		bool init();
		void update();
		void clear();
		void render();
		bool isOpen();
		void destroy();
	public:
		static SDL_Window *window_;
		static SDL_Renderer *renderer_;
		static SDL_GLContext context_;

	private:
		const char *title_;
		int width_;
		int height_;

		bool is_open_;

	};
}
