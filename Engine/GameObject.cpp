#include "GameObject.h"
#include "Managers\ObjectManager.h"

namespace Engine {

	GameObject::GameObject() : GameObject("GameObject") {

	}

	GameObject::GameObject(const char *name) : Object(name), transform_() {
		transform_.setGameObject(this);
	}

	GameObject::~GameObject() {
		transform_.setGameObject(0);
	}

	void GameObject::setParent(GameObject* game_object) {
		transform_.setParent(&game_object->transform_);
	}

	void GameObject::destroy() {
		for (int i = 0; i < components_.size(); i++) {
			components_[i]->onDestroy();
		}

		delete this;
	}
}

