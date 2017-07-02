#include "Component.h"
#include "Manager.h"

namespace Engine {

	Component::Component(const char *name) : Object(name) {
		
	}

	Component::~Component() {
		
	}

	void Component::init() {
		pObjectManager->addComponent(this);
	}

	void Component::deinit() {
		pObjectManager->removeComponent(this);
	}
}
