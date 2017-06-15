#include "Manager.h"

namespace Engine {

	Manager *Manager::instance_ = 0;

	Manager::Manager() {
	}

	Manager * Manager::getInstance() {
		if (instance_ == 0) {
			instance_ = new Manager();
		}

		return instance_;
	}
}