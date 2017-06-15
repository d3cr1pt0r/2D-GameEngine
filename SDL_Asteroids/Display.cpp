#include "Display.h"
#include "Input.h"
#include <iostream>

SDL_Window *Display::window_;
SDL_Renderer *Display::renderer_;

Display::Display(const char *title, int width, int height) :
	title_(title),
	width_(width),
	height_(height) {}

Display::~Display() {
}

bool Display::init() {
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

void Display::update() {
	if (Input::getQuitRequested()) {
		is_open_ = false;
		return;
	}
}

void Display::clear() {
	SDL_SetRenderDrawColor(renderer_, 20, 20, 20, 255);
	SDL_RenderClear(renderer_);
}

void Display::render() {
	SDL_RenderPresent(renderer_);
}

bool Display::isOpen() {
	return is_open_;
}

void Display::destroy() {
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
}