#include "Manager.h"

namespace Engine {

	Manager *Manager::instance_ = 0;

	Manager::Manager() {

	}

	void Manager::init() {
		if (instance_ == 0) {
			instance_ = new Manager();

			instance_->log_manager_ = new LogManager();
			instance_->window_manager_ = new WindowManager();
			instance_->input_manager_ = new InputManager();
			instance_->object_manager_ = new ObjectManager();
			instance_->camera_manager_ = new CameraManager();
			instance_->render_manager_ = new RenderManager();

			instance_->log_manager_->init();
			instance_->window_manager_->init();
			instance_->input_manager_->init();
			instance_->object_manager_->init();
			instance_->camera_manager_->init();
			instance_->render_manager_->init();
		}
	}

	void Manager::destroy() {
		instance_->render_manager_->destroy();
		instance_->camera_manager_->destroy();
		instance_->object_manager_->destroy();
		instance_->input_manager_->destroy();
		instance_->window_manager_->destroy();
		instance_->log_manager_->destroy();

		delete instance_->render_manager_;
		delete instance_->camera_manager_;
		delete instance_->object_manager_;
		delete instance_->input_manager_;
		delete instance_->window_manager_;
		delete instance_->log_manager_;
	}

	Manager* Manager::getInstance() {
		return instance_;
	}
}