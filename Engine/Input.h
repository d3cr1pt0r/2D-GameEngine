#pragma once

#define MAX_KEYS		284
#define MAX_BUTTONS		32

#include <SDL.h>
#include <glm.hpp>

namespace Engine {

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

		static glm::vec2 getMousePosition();
		static glm::vec2 getMouseDelta();

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

		static glm::vec2 mouse_position_;
		static glm::vec2 mouse_delta_;
	};
}