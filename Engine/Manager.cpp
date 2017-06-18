#include "Manager.h"
#include "Log.h"

namespace Engine {

	Manager *Manager::instance_ = 0;

	Manager::Manager() : camera_manager_() {

	}

	void Manager::init() {
		if (instance_ == 0) {
			Log::logDebug("Manager", "initialized");
			instance_ = new Manager();
		}
	}

	void Manager::destroy() {

	}

	Manager* Manager::getInstance() {
		if (instance_ == 0) {
			Log::logWarning("Manager", "Manager not initialized! Make sure you call Manager::init()");
		}

		return instance_;
	}
}