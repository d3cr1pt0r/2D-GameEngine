#pragma once

#define MAX_KEYS		284
#define MAX_BUTTONS		32

#include <SDL.h>
#include "Vector2f.h"

class Input {

public:
	Input();
	~Input();

	bool init();
	void update();
	bool destroy();

	static bool getKey(int keycode);
	static bool getKeyUp(int keycode);
	static bool getKeyDown(int keycode);

	static bool getButton(int button);
	static bool getButtonUp(int button);
	static bool getButtonDown(int button);

	static bool getQuitRequested();

	static Vector2f getMousePosition();

private:
	void updateLastKeys();
	void updateLastButtons();

	static const bool isKeyInRange(const int &key);
	static const bool isButtonInRange(const int &button);

private:
	SDL_Event sdl_event_;

	static bool keys_[MAX_KEYS];
	static bool keys_last_[MAX_KEYS];
	static bool buttons_[MAX_BUTTONS];
	static bool buttons_last_[MAX_BUTTONS];

	static bool quit_requested_;
	static int last_key_pressed_;
	static int last_button_pressed_;

	static Vector2f mouse_position_;
};

