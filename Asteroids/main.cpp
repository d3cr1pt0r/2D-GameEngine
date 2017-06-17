#include <iostream>

#include <Engine/CoreEngine.h>
#include "AsteroidsGame.h"

int main(int argc, char *argv[]) {
	bool block_input;

	AsteroidsGame *game = new AsteroidsGame();
	Engine::CoreEngine core_engine(game, "SDL_ASTEROIDS", 800, 600, 60);

	if (!core_engine.init()) {
		std::cout << "Failed to initialize CoreEngine!" << std::endl;
		std::cin >> block_input;
		return EXIT_FAILURE;
	}

	core_engine.run();

	return EXIT_SUCCESS;
}