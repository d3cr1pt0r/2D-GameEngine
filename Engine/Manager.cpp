#include "Manager.h"
#include "Log.h"

namespace Engine {

	Manager *Manager::instance_ = 0;

	Manager::Manager() {

	}

	void Manager::init() {
		if (instance_ == 0) {
			Log::logDebug("Manager", "initialized");

			instance_ = new Manager();

			instance_->window_manager_ = new WindowManager();
			instance_->input_manager_ = new InputManager();
			instance_->camera_manager_ = new CameraManager();

			instance_->window_manager_->init();
			instance_->input_manager_->init();
			instance_->camera_manager_->init();
		}
	}

	void Manager::destroy() {
		instance_->window_manager_->destroy();
		instance_->input_manager_->destroy();
		instance_->camera_manager_->destroy();

		delete instance_->window_manager_;
		delete instance_->input_manager_;
		delete instance_->camera_manager_;
	}

	Manager* Manager::getInstance() {
		if (instance_ == 0) {
			Log::logWarning("Manager", "Manager not initialized! Make sure you call Manager::init()");
		}

		return instance_;
	}
}