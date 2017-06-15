#pragma once
#include "Game.h"
#include "RectObject.h"
#include <vector>

class AsteroidsGame : public Game {

public:
	AsteroidsGame();
	~AsteroidsGame();

	void init() override;
	void update(const float &delta_time) override;
	void render() override;
	void destroy() override;

private:
	RectObject rect_;

};

