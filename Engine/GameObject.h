#pragma once
#include "Object.h"
#include "Transform.h"
#include <vector>

namespace Engine {

	class Component;
	class RenderableComponent;

	class GameObject : public Object {

	public:
		GameObject(const char *name);
		~GameObject();

		void init() override;
		void deinit() override;

		void setParent(GameObject *game_object);

		void addComponent(Component *component);
		void addComponent(RenderableComponent *renderable_component);

	public:
		Transform transform_;
	};
}

