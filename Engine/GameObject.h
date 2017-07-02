#pragma once
#include "Object.h"
#include "Transform.h"

namespace Engine {

	class Component;
	class RenderableComponent;

	class GameObject : public Object {

	public:
		GameObject(const char *name);
		~GameObject();

		void init() override;
		void destroy() override;

		void addComponent(Component *component);
		void addComponent(RenderableComponent *renderable_component);

	public:
		Transform transform_;
	};
}

