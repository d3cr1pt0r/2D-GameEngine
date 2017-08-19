#include "ManagerSystem.h"

namespace Engine {

	void ManagerSystem::onCreate() {
		
	}

	void ManagerSystem::onDestroy() {
		unregisterManagers();
	}

}