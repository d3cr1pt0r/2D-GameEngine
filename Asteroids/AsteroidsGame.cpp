#include "AsteroidsGame.h"

#include <iostream>
#include <glm.hpp>

#include <Engine/Manager.h>
#include <Engine/GameObject.h>
#include <Engine/SpriteRenderer.h>
#include <Engine/Color.h>

void AsteroidsGame::init() {
	int width = Engine::pWindowManager->getWidth();
	int height = Engine::pWindowManager->getHeight();

	game_object_1_ = new Engine::GameObject("GameObject 1");
	game_object_2_ = new Engine::GameObject("GameObject 2");

	sprite_renderer_1 = new Engine::SpriteRenderer(Engine::Color(0.0f, 1.0f, 0.0f, 1.0f));
	sprite_renderer_2 = new Engine::SpriteRenderer(Engine::Color(0.0f, 0.0f, 1.0f, 1.0f));

	game_object_1_->addComponent(sprite_renderer_1);
	game_object_2_->addComponent(sprite_renderer_2);

	game_object_1_->transform_.setPosition(glm::vec3(width * 0.5f, height * 0.5f, 0.0f));
	game_object_1_->transform_.setScale(glm::vec3(5.0f, 5.0f, 5.0f));
	sprite_renderer_1->color_ = Engine::Color(0.0, 1.0, 0.0, 1.0);

	game_object_2_->transform_.setPosition(glm::vec3(10.0f, 10.0f, 0.0f));
	game_object_2_->transform_.setScale(glm::vec3(1.0f, 1.0f, 1.0f));
	sprite_renderer_1->color_ = Engine::Color(0.0, 0.0, 1.0, 1.0);

	game_object_1_->transform_.addChild(&game_object_2_->transform_);
}

void AsteroidsGame::update(const float &delta_time) {
	const float speed = 50.0f;

	if (Engine::pInputManager->getButtonDown(1)) {
		drag_mode_ = true;
	}
	if (Engine::pInputManager->getButtonUp(1)) {
		drag_mode_ = false;
	}

	if (Engine::pInputManager->getKey(SDL_SCANCODE_W)) {
		game_object_1_->transform_.move(glm::vec3(0.0f, delta_time * speed, 0.0f));
	}
	if (Engine::pInputManager->getKey(SDL_SCANCODE_S)) {
		game_object_1_->transform_.move(glm::vec3(0.0f, -delta_time * speed, 0.0f));
	}
	if (Engine::pInputManager->getKey(SDL_SCANCODE_A)) {
		game_object_1_->transform_.move(glm::vec3(-delta_time * speed, 0.0f, 0.0f));
	}
	if (Engine::pInputManager->getKey(SDL_SCANCODE_D)) {
		game_object_1_->transform_.move(glm::vec3(delta_time * speed, 0.0f, 0.0f));
	}
	if (Engine::pInputManager->getKey(SDL_SCANCODE_Q)) {
		game_object_1_->transform_.rotate(glm::vec3(0.0f, 0.0f, -delta_time));
	}
	if (Engine::pInputManager->getKey(SDL_SCANCODE_E)) {
		game_object_1_->transform_.rotate(glm::vec3(0.0f, 0.0f, delta_time));
	}

	if (Engine::pInputManager->getKey(SDL_SCANCODE_2)) {
		game_object_1_->transform_.scale(glm::vec3(-delta_time * 10.0f, -delta_time * 10.0f, 0.0f));
	}
	if (Engine::pInputManager->getKey(SDL_SCANCODE_3)) {
		game_object_1_->transform_.scale(glm::vec3(delta_time * 10.0f, delta_time * 10.0f, 0.0f));
	}

	if (drag_mode_) {
		glm::vec3 mouse_position = glm::vec3(Engine::pInputManager->getMousePosition().x, Engine::pInputManager->getMousePosition().y, 0.0f);
		game_object_1_->transform_.setPosition(mouse_position - game_object_1_->transform_.getScale() * 0.5f);
	}
}

void AsteroidsGame::deinit() {
	sprite_renderer_1->deinit();
	sprite_renderer_2->deinit();

	game_object_1_->deinit();
	game_object_2_->deinit();
}