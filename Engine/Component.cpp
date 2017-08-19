#include "Component.h"
#include "Managers\ObjectManager.h"

namespace Engine {

	Component::Component(const char *name) : Object(name) {

	}

	Component::~Component() {

	}

	void Component::onCreate() {
		pObjectManager->addComponent(this);
	}

	void Component::onUpdate() {

	}

	void Component::onDestroy() {
		pObjectManager->removeComponent(this);
	}

	GameObject* Component::getGameObject() {
		return game_object_;
	}

	void Component::setGameObject(GameObject* game_object) {
		game_object_ = game_object;
	}
}
