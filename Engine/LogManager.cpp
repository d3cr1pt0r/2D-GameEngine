#include "LogManager.h"

namespace Engine {

	void LogManager::init() {
		logDebug("LogManager", "initialized");
	}

	void LogManager::destroy() {
		logDebug("LogManager", "destroyed");
	}
}
