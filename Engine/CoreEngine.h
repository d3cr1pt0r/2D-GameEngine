#pragma once
#include "Game.h"
#include "Camera.h"

namespace Engine {

	class CoreEngine {

	public:
		CoreEngine(Game *game, const char *title, int width, int height, double frames_per_second);
		~CoreEngine();

		bool init();
		void run();

		const float getFramesPerSecond() const;

	private:
		void update(const float &frame_time);
		void render();
		void destroy();
	private:
		Game *game_;

		double frames_per_second_;
		double frames_per_second_limit_;

		const char *title_;
		int width_;
		int height_;
	};
}