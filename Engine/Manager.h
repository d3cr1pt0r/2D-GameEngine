#pragma once
#include "WindowManager.h"
#include "InputManager.h"
#include "CameraManager.h"
#include "LogManager.h"

#define pManager Manager::getInstance()
#define pLogManager pManager->log_manager_
#define pWindowManager pManager->window_manager_
#define pInputManager pManager->input_manager_
#define pCameraManager pManager->camera_manager_

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
		LogManager *log_manager_;

	private:
		Manager();

	private:
		static Manager* instance_;
	};
}