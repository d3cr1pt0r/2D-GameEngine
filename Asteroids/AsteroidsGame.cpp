#include "AsteroidsGame.h"

#include <iostream>

#include <Engine/Input.h>
#include <Engine/Manager.h>

AsteroidsGame::AsteroidsGame() {
}

AsteroidsGame::~AsteroidsGame() {
}

void AsteroidsGame::init() {
	rect_ = Engine::RectObject(Engine::Vector2f(400, 300), Engine::Vector2f(20, 20), Engine::Color(255, 0, 0, 255));
}

void AsteroidsGame::update(const float &delta_time) {
	if (Engine::Input::getKeyDown(SDL_SCANCODE_1)) {
		drag_mode_ = true;
	}
	if (Engine::Input::getKeyUp(SDL_SCANCODE_1)) {
		drag_mode_ = false;
	}


	if (Engine::Input::getKey(SDL_SCANCODE_W)) {
		rect_.transform_.position_.y_ -= delta_time * 100.0;
	}
	if (Engine::Input::getKey(SDL_SCANCODE_S)) {
		rect_.transform_.position_.y_ += delta_time * 100.0;
	}
	if (Engine::Input::getKey(SDL_SCANCODE_A)) {
		rect_.transform_.position_.x_ -= delta_time * 100.0;
	}
	if (Engine::Input::getKey(SDL_SCANCODE_D)) {
		rect_.transform_.position_.x_ += delta_time * 100.0;
	}

	if (drag_mode_) {
		rect_.transform_.position_ = Engine::Input::getMousePosition() - Engine::Vector2f(rect_.transform_.scale_.x_ * 0.5f, rect_.transform_.scale_.y_ * 0.5f);
	}
}

void AsteroidsGame::render() {
	rect_.render();
}

void AsteroidsGame::destroy() {

}