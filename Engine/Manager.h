#pragma once
#include "WindowManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "CameraManager.h"
#include "RenderManager.h"
#include "LogManager.h"

#define pManager Manager::getInstance()
#define pWindowManager pManager->window_manager_
#define pInputManager pManager->input_manager_
#define pObjectManager pManager->object_manager_
#define pCameraManager pManager->camera_manager_
#define pRenderManager pManager->render_manager_
#define pLogManager pManager->log_manager_

namespace Engine {

	class Manager {

	public:
		static void init();
		static void destroy();
		static Manager* getInstance();

	public:
		WindowManager *window_manager_;
		InputManager *input_manager_;
		ObjectManager *object_manager_;
		CameraManager *camera_manager_;
		RenderManager *render_manager_;
		LogManager *log_manager_;

	private:
		Manager();

	private:
		static Manager* instance_;
	};
}