#pragma once
#include "BaseManager.h"
#include "../Object.h"
#include "../Component.h"
#include "../RenderableComponent.h"

#include <vector>
#include <unordered_map>

#define MAX_OBJECTS		4294967296

namespace Engine {

	class ObjectManager : public BaseManager {

	public:
		ObjectManager();
		~ObjectManager();

		void addComponent(Component *component);
		void removeComponent(Component *component);

		void addRenderableComponent(RenderableComponent *renderable_component);
		void removeRenderableComponent(RenderableComponent *renderable_component);

		std::unordered_map<unsigned int, Component*>& getComponents();
		std::unordered_map<unsigned int, RenderableComponent*>& getRenderableComponents();

	private:
		std::unordered_map<unsigned int, Component*> components_;
		std::unordered_map<unsigned int, RenderableComponent*> renderable_components_;
	};

	extern ObjectManager* pObjectManager;
}