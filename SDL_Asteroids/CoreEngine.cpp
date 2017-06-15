#include "CoreEngine.h"
#include "SDL.h"
#include "Input.h"

CoreEngine::CoreEngine(Game *game, const char *title, int width, int height, double frames_per_second) :
	game_(game),
	display_(title, width, height),
	input_(),
	frames_per_second_limit_(frames_per_second) {}


CoreEngine::~CoreEngine() {
}

bool CoreEngine::init() {
	bool sdl_initialized = SDL::init();
	bool display_initialized = display_.init();
	bool input_initialized = input_.init();

	if (!sdl_initialized || !display_initialized || !input_initialized) {
		return false;
	}

	return true;
}

void CoreEngine::run() {
	bool should_render;

	int frames = 0;
	double frame_time = 1.0 / frames_per_second_limit_;
	double frame_counter = 0;

	double current_time = 0;
	double previous_time = 0;
	double elapsed_time = 0;
	double lag = 0;

	frames_per_second_ = 0;

	game_->init();

	while (display_.isOpen()) {
		should_render = false;

		current_time = SDL_GetTicks() * 0.001;
		elapsed_time = current_time - previous_time;
		previous_time = current_time;

		lag += elapsed_time;
		frame_counter += elapsed_time;

		while (lag >= frame_time) {
			update(frame_time);

			should_render = true;
			lag -= frame_time;

			if (frame_counter >= 1.0) {
				frames_per_second_ = frames;
				frames = 0;
				frame_counter = 0;
			}
		}

		if (should_render) {
			render();
			frames++;
		}
		else {
			SDL_Delay(1);
		}
	}

	destroy();
}

const float CoreEngine::getFramesPerSecond() const {
	return frames_per_second_;
}

void CoreEngine::update(const float &frame_time) {
	input_.update();
	display_.update();
	game_->update(frame_time);
}

void CoreEngine::render() {
	display_.clear();
	game_->render();
	display_.render();
}

void CoreEngine::destroy() {
	display_.destroy();
	game_->destroy();
	SDL::destroy();
}