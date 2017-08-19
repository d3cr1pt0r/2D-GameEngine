#pragma once
#include "Game.h"
#include "Camera.h"

namespace Engine {

	class CoreEngine {

	public:
		CoreEngine(const char *title, int width, int height, double frames_per_second);
		~CoreEngine();

		bool init();
		void deinit();
		void run();

		const char* getTitle() const;
		const int& getWidth() const;
		const int& getHeight() const;
		const float getFramesPerSecond() const;

		void setGame(Game* game);

	private:
		void update(const float &frame_time);
		void render();

	private:
		Game *game_;

		double frames_per_second_;
		double frames_per_second_limit_;

		const char *title_;
		int width_;
		int height_;
	};
}