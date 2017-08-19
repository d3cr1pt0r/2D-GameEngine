#include "GameObject.h"
#include "Managers\ManagerSystem.h"
#include "RenderableComponent.h"

namespace Engine {

	GameObject::GameObject() : GameObject("GameObject") {

	}

	GameObject::GameObject(const char *name) : Object(name), transform_() {

	}

	GameObject::~GameObject() {

	}

	void GameObject::init() {
		Object::init();

		transform_.setGameObject(this);
	}

	void GameObject::deinit() {
		Object::deinit();

		transform_.setGameObject(0);
	}

	void GameObject::setParent(GameObject *game_object) {
		transform_.setParent(&game_object->transform_);
	}

	void GameObject::addComponent(Component *component) {
		component->game_object_ = this;
	}

	void GameObject::addComponent(RenderableComponent *renderable_component) {
		renderable_component->game_object_ = this;
	}
}

