#pragma once

#define MAX_KEYS		284
#define MAX_BUTTONS		32

#include "BaseManager.h"

#include <SDL.h>
#include <glm.hpp>
#include <unordered_map>

namespace Engine {

	class InputManager : public BaseManager {

	public:
		InputManager();
		~InputManager();
		void update();

		bool getKey(int keycode);
		bool getKeyUp(int keycode);
		bool getKeyDown(int keycode);

		bool getButton(int button);
		bool getButtonUp(int button);
		bool getButtonDown(int button);

		bool getQuitRequested();

		glm::vec2 getMousePosition();
		glm::vec2 getMouseDelta();

	private:
		void updateLastKeys();
		void updateLastButtons();

		const bool isKeyInRange(const int &key);
		const bool isButtonInRange(const int &button);

	private:
		SDL_Event sdl_event_;

		bool keys_[MAX_KEYS];
		bool keys_last_[MAX_KEYS];
		bool buttons_[MAX_BUTTONS];
		bool buttons_last_[MAX_BUTTONS];

		bool quit_requested_;
		int last_key_pressed_;
		int last_button_pressed_;

		glm::vec2 mouse_position_;
		glm::vec2 mouse_delta_;
	};

	extern InputManager* pInputManager;

}