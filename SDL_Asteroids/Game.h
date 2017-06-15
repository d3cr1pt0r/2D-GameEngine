#pragma once

class Game {

public:
	Game();
	~Game();

	virtual void init() = 0;
	virtual void update(const float &delta_time) = 0;
	virtual void render() = 0;
	virtual void destroy() = 0;
};

