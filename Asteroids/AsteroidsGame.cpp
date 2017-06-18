#include "AsteroidsGame.h"

#include <iostream>
#include <glm.hpp>

#include <Engine/Input.h>
#include <Engine/Manager.h>
#include <Engine/Window.h>
#include <Engine/Log.h>

AsteroidsGame::AsteroidsGame() : camera_(), sprite_() {
}

AsteroidsGame::~AsteroidsGame() {
}

void AsteroidsGame::init() {
	camera_.setToOrtographic(Engine::Window::width_, Engine::Window::height_, -1.0f, 100.0f, 1.0f);
	camera_.clear_color_ = Engine::Color(0.1f, 0.1f, 0.1f, 1.0f);

	sprite_.transform_.setPosition(glm::vec3(Engine::Window::width_ * 0.5f, Engine::Window::height_ * 0.5f, 0.0f));
	sprite_.transform_.setScale(glm::vec3(5.0f, 5.0f, 1.0f));
	sprite_.color_ = Engine::Color(0.0, 1.0, 0.0, 1.0);

	sprite_.init();
}

void AsteroidsGame::update(const float &delta_time) {
	const float speed = 50.0f;

	if (Engine::Input::getKeyDown(SDL_SCANCODE_1)) {
		drag_mode_ = true;
	}
	if (Engine::Input::getKeyUp(SDL_SCANCODE_1)) {
		drag_mode_ = false;
	}

	if (Engine::Input::getKey(SDL_SCANCODE_2)) {
		camera_.transform_.move(glm::vec3(0.0f, 0.0f, delta_time * speed));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_3)) {
		camera_.transform_.move(glm::vec3(0.0f, 0.0f, -delta_time * speed));
	}

	if (Engine::Input::getKey(SDL_SCANCODE_UP)) {
		camera_.transform_.move(glm::vec3(0.0f, delta_time * speed, 0.0f));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_DOWN)) {
		camera_.transform_.move(glm::vec3(0.0f, -delta_time * speed, 0.0f));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_LEFT)) {
		camera_.transform_.move(glm::vec3(-delta_time * speed, 0.0f, 0.0f));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_RIGHT)) {
		camera_.transform_.move(glm::vec3(delta_time * speed, 0.0f, 0.0f));
	}

	if (Engine::Input::getKey(SDL_SCANCODE_W)) {
		sprite_.transform_.move(glm::vec3(0.0f, delta_time * speed, 0.0f));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_S)) {
		sprite_.transform_.move(glm::vec3(0.0f, -delta_time * speed, 0.0f));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_A)) {
		sprite_.transform_.move(glm::vec3(-delta_time * speed, 0.0f, 0.0f));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_D)) {
		sprite_.transform_.move(glm::vec3(delta_time * speed, 0.0f, 0.0f));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_Q)) {
		sprite_.transform_.rotate(glm::vec3(0.0f, 0.0f, -delta_time));
	}
	if (Engine::Input::getKey(SDL_SCANCODE_E)) {
		sprite_.transform_.rotate(glm::vec3(0.0f, 0.0f, delta_time));
	}

	if (drag_mode_) {
		glm::vec3 mouse_position = glm::vec3(Engine::Input::getMousePosition().x, Engine::Input::getMousePosition().y, 0.0f);
		sprite_.transform_.setPosition(mouse_position - sprite_.transform_.getScale() * 0.5f);
	}
}

void AsteroidsGame::render() {
	sprite_.render();
}

void AsteroidsGame::destroy() {
	sprite_.destroy();
}