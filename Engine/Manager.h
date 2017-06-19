#pragma once
#include "WindowManager.h"
#include "InputManager.h"
#include "CameraManager.h"

namespace Engine {

	class Manager {

	public:
		static void init();
		static void destroy();
		static Manager* getInstance();

	public:
		WindowManager *window_manager_;
		InputManager *input_manager_;
		CameraManager *camera_manager_;

	private:
		Manager();

	private:
		static Manager* instance_;
	};
}