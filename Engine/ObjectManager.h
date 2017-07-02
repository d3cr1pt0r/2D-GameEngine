#pragma once
#include "BaseManager.h"
#include "Object.h"
#include "Component.h"
#include "RenderableComponent.h"

#include <vector>
#include <unordered_map>

#define MAX_OBJECTS		4294967296

namespace Engine {

	class ObjectManager : public BaseManager {

	public:
		void init() override;
		void deinit() override;

		void addObject(Object *object);
		void removeObject(const Object *object);

		void addComponent(Component *component);
		void removeComponent(Component *component);

		void addRenderableComponent(RenderableComponent *renderable_component);
		void removeRenderableComponent(RenderableComponent *renderable_component);

		std::unordered_map<unsigned int, Object*>& getObjects();
		std::unordered_map<unsigned int, Component*>& getComponents();
		std::unordered_map<unsigned int, RenderableComponent*>& getRenderableComponents();

	private:
		std::unordered_map<unsigned int, Object*> objects_;
		std::unordered_map<unsigned int, Component*> components_;
		std::unordered_map<unsigned int, RenderableComponent*> renderable_components_;
	};
}