#pragma once
#include "Display.h"
#include "Input.h"
#include "Game.h"

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
	Display display_;
	Input input_;

	double frames_per_second_;
	double frames_per_second_limit_;

	Game *game_;
};

