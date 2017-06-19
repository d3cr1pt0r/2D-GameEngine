#include "AsteroidsGame.h"

#include <iostream>
#include <glm.hpp>

#include <Engine/Manager.h>
#include <Engine/Log.h>

void AsteroidsGame::init() {
	int width = Engine::Manager::getInstance()->window_manager_->getWidth();
	int height = Engine::Manager::getInstance()->window_manager_->getHeight();

	sprite_.transform_.setPosition(glm::vec3(width * 0.5f, height * 0.5f, 0.0f));
	sprite_.transform_.setScale(glm::vec3(5.0f, 5.0f, 5.0f));
	sprite_.color_ = Engine::Color(0.0, 1.0, 0.0, 1.0);

	sprite2_.transform_.setPosition(glm::vec3(10.0f, 10.0f, 0.0f));
	sprite2_.transform_.setScale(glm::vec3(1.0f, 1.0f, 1.0f));
	sprite2_.color_ = Engine::Color(0.0, 0.0, 1.0, 1.0);

	sprite_.init();
	sprite2_.init();

	sprite_.transform_.addChild(&sprite2_.transform_);
}

void AsteroidsGame::update(const float &delta_time) {
	const float speed = 50.0f;

	if (Engine::Manager::getInstance()->input_manager_->getButtonDown(1)) {
		drag_mode_ = true;
	}
	if (Engine::Manager::getInstance()->input_manager_->getButtonUp(1)) {
		drag_mode_ = false;
	}

	if (Engine::Manager::getInstance()->input_manager_->getKey(SDL_SCANCODE_W)) {
		sprite_.transform_.move(glm::vec3(0.0f, delta_time * speed, 0.0f));
	}
	if (Engine::Manager::getInstance()->input_manager_->getKey(SDL_SCANCODE_S)) {
		sprite_.transform_.move(glm::vec3(0.0f, -delta_time * speed, 0.0f));
	}
	if (Engine::Manager::getInstance()->input_manager_->getKey(SDL_SCANCODE_A)) {
		sprite_.transform_.move(glm::vec3(-delta_time * speed, 0.0f, 0.0f));
	}
	if (Engine::Manager::getInstance()->input_manager_->getKey(SDL_SCANCODE_D)) {
		sprite_.transform_.move(glm::vec3(delta_time * speed, 0.0f, 0.0f));
	}
	if (Engine::Manager::getInstance()->input_manager_->getKey(SDL_SCANCODE_Q)) {
		sprite_.transform_.rotate(glm::vec3(0.0f, 0.0f, -delta_time));
	}
	if (Engine::Manager::getInstance()->input_manager_->getKey(SDL_SCANCODE_E)) {
		sprite_.transform_.rotate(glm::vec3(0.0f, 0.0f, delta_time));
	}

	if (Engine::Manager::getInstance()->input_manager_->getKey(SDL_SCANCODE_2)) {
		sprite_.transform_.scale(glm::vec3(-delta_time * 10.0f, -delta_time * 10.0f, 0.0f));
	}
	if (Engine::Manager::getInstance()->input_manager_->getKey(SDL_SCANCODE_3)) {
		sprite_.transform_.scale(glm::vec3(delta_time * 10.0f, delta_time * 10.0f, 0.0f));
	}

	if (drag_mode_) {
		glm::vec3 mouse_position = glm::vec3(Engine::Manager::getInstance()->input_manager_->getMousePosition().x, Engine::Manager::getInstance()->input_manager_->getMousePosition().y, 0.0f);
		sprite_.transform_.setPosition(mouse_position - sprite_.transform_.getScale() * 0.5f);
	}
}

void AsteroidsGame::render() {
	sprite_.render();
	sprite2_.render();
}

void AsteroidsGame::destroy() {
	sprite_.destroy();
	sprite2_.destroy();
}