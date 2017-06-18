#pragma once
#include <Engine/Game.h>
#include <Engine/Camera.h>
#include <Engine/Sprite.h>

class AsteroidsGame : public Engine::Game {

public:
	AsteroidsGame();
	~AsteroidsGame();

	void init() override;
	void update(const float &delta_time) override;
	void render() override;
	void destroy() override;

private:
	Engine::Camera camera_;
	Engine::Sprite sprite_;
	bool drag_mode_ = false;

};