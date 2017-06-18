#include "CoreEngine.h"
#include "SDL.h"
#include "Manager.h"
#include "Input.h"

namespace Engine {
	CoreEngine::CoreEngine(Game *game, const char *title, int width, int height, double frames_per_second) :
		game_(game),
		window_(title, width, height),
		input_(),
		frames_per_second_limit_(frames_per_second) {}


	CoreEngine::~CoreEngine() {
	}

	bool CoreEngine::init() {
		bool sdl_initialized = SDL::init();
		bool window_initialized = window_.init();
		bool input_initialized = input_.init();

		if (!sdl_initialized || !window_initialized || !input_initialized) {
			return false;
		}

		Manager::init();

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

		while (window_.isOpen()) {
			should_render = false;

			current_time = SDL_GetTicks() * 0.001;
			elapsed_time = current_time - previous_time;
			previous_time = current_time;

			lag += elapsed_time;
			frame_counter += elapsed_time;

			while (lag >= frame_time) {
				update((float)frame_time);

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
		return (float) frames_per_second_;
	}

	void CoreEngine::update(const float &frame_time) {
		input_.update();
		window_.update();
		game_->update(frame_time);
	}

	void CoreEngine::render() {
		window_.clear();
		game_->render();
		window_.render();
	}

	void CoreEngine::destroy() {
		window_.destroy();
		game_->destroy();
		SDL::destroy();
		Manager::destroy();
	}
}