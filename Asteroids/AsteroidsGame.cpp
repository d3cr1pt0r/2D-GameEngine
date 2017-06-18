#include "AsteroidsGame.h"

#include <iostream>
#include <glm.hpp>

#include <Engine/Input.h>
#include <Engine/Manager.h>
#include <Engine/Window.h>
#include <Engine/ErrorLog.h>

AsteroidsGame::AsteroidsGame() : camera_(), renderable_() {
}

AsteroidsGame::~AsteroidsGame() {
}

void AsteroidsGame::init() {
	camera_.setToOrtographic(Engine::Window::width_, Engine::Window::height_, 1.0f);

	renderable_.transform_.setPosition(glm::vec3(200.0f, 200.0f, 0.0f));
	renderable_.transform_.setScale(glm::vec3(5.0f, 5.0f, 1.0f));
	renderable_.color_ = Engine::Color(0.0, 1.0, 0.0, 1.0);

	renderable_.init();
}

void AsteroidsGame::update(const float &delta_time) {
	const float speed = 50.0f;

	if (Engine::Input::getKeyDown(SDL_SCANCODE_1)) {
		drag_mode_ = true;
	}
	if (Engine::Input::getKeyUp(SDL_SCANCODE_1)) {
		drag_mode_ = false;
	}

	if (Engine::Input::getKey(SDL_SCANCODE_W)) {
		renderable_.transform_.move(glm::vec3(0.0f, delta_time * speed, 0.0f));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_S)) {
		renderable_.transform_.move(glm::vec3(0.0f, -delta_time * speed, 0.0f));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_A)) {
		renderable_.transform_.move(glm::vec3(-delta_time * speed, 0.0f, 0.0f));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_D)) {
		renderable_.transform_.move(glm::vec3(delta_time * speed, 0.0f, 0.0f));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_Q)) {
		renderable_.transform_.rotate(glm::vec3(0.0f, 0.0f, delta_time));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_E)) {
		renderable_.transform_.rotate(glm::vec3(0.0f, 0.0f, -delta_time));
	}

	if (drag_mode_) {
		glm::vec3 mouse_position = glm::vec3(Engine::Input::getMousePosition().x, Engine::Input::getMousePosition().y, 0.0f);
		renderable_.transform_.setPosition(mouse_position - renderable_.transform_.getScale() * 0.5f);
	}
}

void AsteroidsGame::render() {
	renderable_.render();
}

void AsteroidsGame::destroy() {

}