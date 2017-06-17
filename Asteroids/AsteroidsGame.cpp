#include "AsteroidsGame.h"

#include <iostream>

#include <Engine/Input.h>
#include <Engine/Manager.h>

AsteroidsGame::AsteroidsGame() {
}

AsteroidsGame::~AsteroidsGame() {
}

void AsteroidsGame::init() {
	renderable_.transform_.position_ = Engine::Vector2f(0, 0);
	renderable_.transform_.scale_ = Engine::Vector2f(0.5, 0.5);
	renderable_.color_ = Engine::Color(1.0, 0.0, 0.0, 1.0);
	renderable_.init();
}

void AsteroidsGame::update(const float &delta_time) {
	if (Engine::Input::getKeyDown(SDL_SCANCODE_1)) {
		drag_mode_ = true;
	}
	if (Engine::Input::getKeyUp(SDL_SCANCODE_1)) {
		drag_mode_ = false;
	}


	if (Engine::Input::getKey(SDL_SCANCODE_W)) {
		renderable_.transform_.position_.y_ -= delta_time * 1;
	}
	if (Engine::Input::getKey(SDL_SCANCODE_S)) {
		renderable_.transform_.position_.y_ += delta_time * 1;
	}
	if (Engine::Input::getKey(SDL_SCANCODE_A)) {
		renderable_.transform_.position_.x_ -= delta_time * 1;
	}
	if (Engine::Input::getKey(SDL_SCANCODE_D)) {
		renderable_.transform_.position_.x_ += delta_time * 1;
	}

	if (drag_mode_) {
		renderable_.transform_.position_ = Engine::Input::getMousePosition() - Engine::Vector2f(renderable_.transform_.scale_.x_ * 0.5f, renderable_.transform_.scale_.y_ * 0.5f);
	}

	renderable_.update();
}

void AsteroidsGame::render() {
	renderable_.render();
}

void AsteroidsGame::destroy() {

}