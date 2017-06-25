#include "InputManager.h"
#include "Manager.h"
#include <iostream>

namespace Engine {

	void InputManager::init() {
		pLogManager->logDebug("InputManager", "initialized");

		for (int i = 0; i < MAX_KEYS; i++) {
			keys_[i] = false;
			keys_last_[i] = false;
		}

		for (int i = 0; i < MAX_BUTTONS; i++) {
			buttons_[i] = false;
			buttons_last_[i] = false;
		}

		quit_requested_ = false;
		last_key_pressed_ = 0;
		last_button_pressed_ = 0;
	}

	void InputManager::update() {
		updateLastKeys();
		updateLastButtons();

		while (SDL_PollEvent(&sdl_event_)) {
			SDL_Scancode scancode = sdl_event_.key.keysym.scancode;
			int button = (int) sdl_event_.button.button;

			switch (sdl_event_.type) {
			case SDL_KEYDOWN:
				keys_[scancode] = true;
				break;
			case SDL_KEYUP:
				keys_[scancode] = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				buttons_[button] = true;
				break;
			case SDL_MOUSEBUTTONUP:
				buttons_[button] = false;
				break;
			case SDL_MOUSEMOTION:
				mouse_position_.x = (float)sdl_event_.motion.x;
				mouse_position_.y = pWindowManager->getHeight() - (float)sdl_event_.motion.y;
				mouse_delta_.x = (float)sdl_event_.motion.xrel;
				mouse_delta_.y = (float)sdl_event_.motion.yrel;
				break;
			case SDL_QUIT:
				quit_requested_ = true;
				break;
			}
		}
	}

	void InputManager::destroy() {
		pLogManager->logDebug("InputManager", "destroyed");
	}

	bool InputManager::getKey(int keycode) {
		SDL_assert(isKeyInRange(keycode));

		return keys_[keycode];
	}

	bool InputManager::getKeyUp(int keycode) {
		SDL_assert(isKeyInRange(keycode));

		return !keys_[keycode] && keys_last_[keycode];
	}

	bool InputManager::getKeyDown(int keycode) {
		SDL_assert(isKeyInRange(keycode));

		return keys_[keycode] && !keys_last_[keycode];
	}

	bool InputManager::getButton(int button) {
		SDL_assert(isButtonInRange(button));

		return buttons_[button];
	}

	bool InputManager::getButtonUp(int button) {
		SDL_assert(isButtonInRange(button));

		return !buttons_[button] && buttons_last_[button];
	}

	bool InputManager::getButtonDown(int button) {
		SDL_assert(isButtonInRange(button));

		return buttons_[button] && !buttons_last_[button];
	}

	bool InputManager::getQuitRequested() {
		return quit_requested_;
	}

	glm::vec2 InputManager::getMousePosition() {
		return mouse_position_;
	}

	glm::vec2 InputManager::getMouseDelta() {
		return glm::vec2(0, 0);
	}

	void InputManager::updateLastKeys() {
		for (int i = 0; i < MAX_KEYS; i++) {
			keys_last_[i] = keys_[i];
		}
	}

	void InputManager::updateLastButtons() {
		for (int i = 0; i < MAX_BUTTONS; i++) {
			buttons_last_[i] = buttons_[i];
		}
	}

	const bool InputManager::isKeyInRange(const int & key) {
		return key >= 0 && key < MAX_KEYS;
	}

	const bool InputManager::isButtonInRange(const int & button) {
		return button >= 0 && button < MAX_BUTTONS;
	}
}