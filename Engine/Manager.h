#pragma once
#include <memory>
#include "CameraManager.h"

namespace Engine {

	class Manager {

	public:
		static void init();
		static void destroy();
		static Manager* getInstance();

	public:
		CameraManager camera_manager_;

	private:
		Manager();

	private:
		static Manager* instance_;
	};
}