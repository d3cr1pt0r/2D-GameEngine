#include "Input.h"
#include <iostream>
#include "Window.h"

namespace Engine {

	bool Input::keys_[MAX_KEYS];
	bool Input::keys_last_[MAX_KEYS];

	bool Input::buttons_[MAX_BUTTONS];
	bool Input::buttons_last_[MAX_BUTTONS];

	bool Input::quit_requested_;
	int Input::last_key_pressed_;
	int Input::last_button_pressed_;

	glm::vec2 Input::mouse_position_;
	glm::vec2 Input::mouse_delta_;

	Input::Input() {}

	Input::~Input() {
	}

	bool Input::init() {
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

		return true;
	}

	void Input::update() {
		updateLastKeys();
		updateLastButtons();

		while (SDL_PollEvent(&sdl_event_)) {
			SDL_Scancode scancode = sdl_event_.key.keysym.scancode;
			Uint8 button = sdl_event_.button.button;

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
				mouse_position_.x = (float) sdl_event_.motion.x;
				mouse_position_.y = Window::height_ - (float) sdl_event_.motion.y;
				mouse_delta_.x = (float) sdl_event_.motion.xrel;
				mouse_delta_.y = (float) sdl_event_.motion.yrel;
				break;
			case SDL_QUIT:
				quit_requested_ = true;
				break;
			}
		}
	}

	bool Input::destroy() {
		return true;
	}

	bool Input::getKey(int keycode) {
		SDL_assert(isKeyInRange(keycode));

		return keys_[keycode];
	}

	bool Input::getKeyUp(int keycode) {
		SDL_assert(isKeyInRange(keycode));

		return !keys_[keycode] && keys_last_[keycode];
	}

	bool Input::getKeyDown(int keycode) {
		SDL_assert(isKeyInRange(keycode));

		return keys_[keycode] && !keys_last_[keycode];
	}

	bool Input::getButton(int button) {
		SDL_assert(isButtonInRange(button));

		return buttons_[button];
	}

	bool Input::getButtonUp(int button) {
		SDL_assert(isButtonInRange(button));

		return !buttons_[button] && buttons_last_[button];
	}

	bool Input::getButtonDown(int button) {
		SDL_assert(isButtonInRange(button));

		return buttons_[button] && !buttons_last_[button];
	}

	bool Input::getQuitRequested() {
		return quit_requested_;
	}

	glm::vec2 Input::getMousePosition() {
		return mouse_position_;
	}

	glm::vec2 Input::getMouseDelta() {
		return glm::vec2(0, 0);
	}

	void Input::updateLastKeys() {
		for (int i = 0; i < MAX_KEYS; i++) {
			keys_last_[i] = keys_[i];
		}
	}

	void Input::updateLastButtons() {
		for (int i = 0; i < MAX_BUTTONS; i++) {
			buttons_last_[i] = buttons_[i];
		}
	}

	const bool Input::isKeyInRange(const int & key) {
		return key > 0 && key < MAX_KEYS;
	}

	const bool Input::isButtonInRange(const int & button) {
		return button > 0 && button < MAX_BUTTONS;
	}
}