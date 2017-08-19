#include <iostream>

#include <Engine/CoreEngine.h>
#include "AsteroidsGame.h"

inline int runEngine() {
	Engine::CoreEngine core_engine("SDL_ASTEROIDS", 800, 600, 60);
	AsteroidsGame* asteroids_game = new AsteroidsGame();

	if (!core_engine.init()) {
		std::cout << "Failed to initialize CoreEngine!" << std::endl;
		getchar();
		return EXIT_FAILURE;
	}

	core_engine.setGame(asteroids_game);
	core_engine.run();
	core_engine.deinit();

	//getchar();

	return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
	return runEngine();
}