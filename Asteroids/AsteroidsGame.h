#pragma once
#include <Engine/Game.h>
#include <Engine/Renderable.h>
#include <Engine/GLSLShader.h>

class AsteroidsGame : public Engine::Game {

public:
	AsteroidsGame();
	~AsteroidsGame();

	void init() override;
	void update(const float &delta_time) override;
	void render() override;
	void destroy() override;

private:
	Engine::GLSLShader shader_;
	Engine::Renderable renderable_;
	bool drag_mode_ = false;

};