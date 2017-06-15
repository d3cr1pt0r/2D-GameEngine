#include "Input.h"
#include <iostream>

bool Input::keys_[MAX_KEYS];
bool Input::keys_last_[MAX_KEYS];

bool Input::buttons_[MAX_BUTTONS];
bool Input::buttons_last_[MAX_BUTTONS];

bool Input::quit_requested_;
int Input::last_key_pressed_;
int Input::last_button_pressed_;

Vector2f Input::mouse_position_;

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
	SDL_PollEvent(&sdl_event_);

	updateLastKeys();
	updateLastButtons();

	//SDL_PumpEvents();
	//const Uint8 *state = SDL_GetKeyboardState(NULL);
	//std::cout << (int)state[SDL_SCANCODE_W] << std::endl;

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
			mouse_position_.x_ = sdl_event_.motion.x;
			mouse_position_.y_ = sdl_event_.motion.y;
			break;
		case SDL_QUIT:
			quit_requested_ = true;
			break;
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

Vector2f Input::getMousePosition() {
	return mouse_position_;
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
