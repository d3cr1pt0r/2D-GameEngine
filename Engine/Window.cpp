#include "Window.h"
#include "Input.h"
#include <iostream>

namespace Engine {

	SDL_Window *Window::window_;
	SDL_Renderer *Window::renderer_;

	Window::Window(const char *title, int width, int height) :
		title_(title),
		width_(width),
		height_(height) {}

	Window::~Window() {
	}

	bool Window::init() {
		window_ = SDL_CreateWindow(title_, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_, height_, SDL_WINDOW_ALLOW_HIGHDPI);

		if (window_ == NULL) {
			std::cout << "SDL failed to create window! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}

		renderer_ = SDL_CreateRenderer(window_, -1, 0);

		if (renderer_ == NULL) {
			std::cout << "SDL failed to create renderer! SDL Error: " << SDL_GetError() << std::endl;
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
		SDL_SetRenderDrawColor(renderer_, 20, 20, 20, 255);
		SDL_RenderClear(renderer_);
	}

	void Window::render() {
		SDL_RenderPresent(renderer_);
	}

	bool Window::isOpen() {
		return is_open_;
	}

	void Window::destroy() {
		SDL_DestroyRenderer(renderer_);
		SDL_DestroyWindow(window_);
	}
}