#include "LogManager.h"

namespace Engine {

	LogManager* pLogManager = nullptr;

	LogManager::LogManager() {
		logDebug("LogManager", "initialized");

		pLogManager = this;
	}

	LogManager::~LogManager() {
		logDebug("LogManager", "destroyed");

		pLogManager = nullptr;
	}
}
