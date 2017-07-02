#pragma once
#include <Engine/Game.h>
#include <Engine/Camera.h>
#include <Engine/GameObject.h>
#include <Engine/SpriteRenderer.h>

class AsteroidsGame : public Engine::Game {

public:
	void init() override;
	void update(const float &delta_time) override;
	void destroy() override;

private:
	Engine::Camera camera_;
	Engine::GameObject *game_object_1_;
	Engine::GameObject *game_object_2_;

	Engine::SpriteRenderer *sprite_renderer_1;
	Engine::SpriteRenderer *sprite_renderer_2;

	bool drag_mode_ = false;

};