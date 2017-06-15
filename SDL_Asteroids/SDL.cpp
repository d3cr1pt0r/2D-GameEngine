#include "SDL.h"
#include <iostream>
#include <SDL.h>

bool SDL::init() {
	int sdl_init = SDL_Init(SDL_INIT_EVERYTHING);

	if (sdl_init < 0) {
		std::cout << "SDL failed to initalize! SDL Error: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void SDL::destroy() {
	SDL_Quit();
}