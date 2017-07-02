#include "GameObject.h"
#include "Manager.h"

namespace Engine {

	GameObject::GameObject(const char *name) : Object(name), transform_() {
		init();
	}

	GameObject::~GameObject() {
		destroy();
	}

	void GameObject::init() {
		Object::init();
	}

	void GameObject::destroy() {
		Object::destroy();
	}

	void GameObject::addComponent(Component *component) {
		component->game_object_ = this;
	}

	void GameObject::addComponent(RenderableComponent * renderable_component) {
		renderable_component->game_object_ = this;
	}
}

