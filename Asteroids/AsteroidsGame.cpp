#include "AsteroidsGame.h"

#include <iostream>
#include <glm.hpp>

#include <Engine/Managers/CameraManager.h>
#include <Engine/Managers/DeviceManager.h>
#include <Engine/Managers/InputManager.h>
#include <Engine/Managers/ObjectManager.h>
#include <Engine/Color.h>

void AsteroidsGame::init() {
	Engine::pCameraManager->getMainCamera()->getGameObject()->transform_.setLocalPosition(glm::vec3(0.0f, 0.0f, 5.0f));

	game_object_1_ = Engine::pObjectManager->createGameObject("GameObject 1");
	game_object_2_ = Engine::pObjectManager->createGameObject("GameObject 2");

	sprite_renderer_1 = game_object_1_->addComponent<Engine::SpriteRenderer>();
	sprite_renderer_2 = game_object_2_->addComponent<Engine::SpriteRenderer>();

	sprite_renderer_1->setColor(Engine::Color(0.0f, 1.0f, 0.0f, 1.0f));
	sprite_renderer_2->setColor(Engine::Color(1.0f, 0.0f, 0.0f, 1.0f));

	game_object_1_->transform_.setLocalPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	game_object_1_->transform_.setLocalScale(glm::vec3(1.0f, 1.0f, 1.0f));
	sprite_renderer_1->color_ = Engine::Color(0.0, 1.0, 0.0, 1.0);

	game_object_2_->transform_.setLocalPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	game_object_2_->transform_.setLocalScale(glm::vec3(1.0f, 1.0f, 1.0f));
	game_object_2_->transform_.setLocalRotation(glm::vec3(0.0f, 30.0f, 0.0f));
	sprite_renderer_1->color_ = Engine::Color(0.0, 0.0, 1.0, 1.0);

	game_object_2_->setParent(game_object_1_);
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
		game_object_1_->transform_.move(glm::vec3(0.0f, delta_time, 0.0f));
	}
	if (Engine::pInputManager->getKey(SDL_SCANCODE_S)) {
		game_object_1_->transform_.move(glm::vec3(0.0f, -delta_time, 0.0f));
	}
	if (Engine::pInputManager->getKey(SDL_SCANCODE_A)) {
		game_object_1_->transform_.move(glm::vec3(-delta_time, 0.0f, 0.0f));
	}
	if (Engine::pInputManager->getKey(SDL_SCANCODE_D)) {
		game_object_1_->transform_.move(glm::vec3(delta_time, 0.0f, 0.0f));
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
	if (Engine::pInputManager->getKey(SDL_SCANCODE_4)) {
		game_object_1_->transform_.rotate(glm::vec3(delta_time * 2.0f, 0.0f, 0.0f));
	}
	if (Engine::pInputManager->getKey(SDL_SCANCODE_5)) {
		game_object_1_->transform_.rotate(glm::vec3(-delta_time * 2.0f, 0.0f, 0.0f));
	}
	if (Engine::pInputManager->getKey(SDL_SCANCODE_6)) {
		game_object_1_->transform_.rotate(glm::vec3(0.0f, delta_time * 2.0f, 0.0f));
	}
	if (Engine::pInputManager->getKey(SDL_SCANCODE_7)) {
		game_object_1_->transform_.rotate(glm::vec3(0.0f, -delta_time * 2.0f, 0.0f));
	}

	if (drag_mode_) {
		int w = Engine::pDeviceManager->getWindowWidth();
		int h = Engine::pDeviceManager->getWindowHeight();

		glm::vec3 mouse_position = glm::vec3(Engine::pInputManager->getMousePosition().x, Engine::pInputManager->getMousePosition().y, 0.0f);
		game_object_1_->transform_.setLocalPosition(glm::vec3(mouse_position.x, mouse_position.y, -25.0f));
	}
}

void AsteroidsGame::deinit() {
	
}