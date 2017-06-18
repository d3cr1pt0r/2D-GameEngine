#include "Manager.h"
#include "ErrorLog.h"

namespace Engine {

	Manager *Manager::instance_ = 0;

	Manager::Manager() : camera_manager_() {

	}

	void Manager::init() {
		if (instance_ == 0) {
			ErrorLog::logDebug("Manager", "initialized");
			instance_ = new Manager();
		}
	}

	void Manager::destroy() {

	}

	Manager* Manager::getInstance() {
		if (instance_ == 0) {
			ErrorLog::logWarning("Manager", "Manager not initialized! Make sure you call Manager::init()");
		}

		return instance_;
	}
}