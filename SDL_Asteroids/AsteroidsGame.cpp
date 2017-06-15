#include "AsteroidsGame.h"

#include "Display.h"
#include "Input.h"
#include "Manager.h"

#include <iostream>

AsteroidsGame::AsteroidsGame() {
}

AsteroidsGame::~AsteroidsGame() {
}

void AsteroidsGame::init() {
	rect_ = RectObject(Vector2f(400, 300), Vector2f(20, 20), Color(255, 0, 0, 255));
}

void AsteroidsGame::update(const float &delta_time) {
	if (Input::getKey(SDL_SCANCODE_W)) {
		rect_.transform_.position_.y_ -= delta_time * 100.0;
	}
	if (Input::getKey(SDL_SCANCODE_S)) {
		rect_.transform_.position_.y_ += delta_time * 100.0;
	}
	if (Input::getKey(SDL_SCANCODE_A)) {
		rect_.transform_.position_.x_ -= delta_time * 100.0;
	}
	if (Input::getKey(SDL_SCANCODE_D)) {
		rect_.transform_.position_.x_ += delta_time * 100.0;
	}
}

void AsteroidsGame::render() {
	rect_.render();
}

void AsteroidsGame::destroy() {

}