#pragma once
#include "BaseManager.h"
#include "../GameObject.h"
#include "../Component.h"
#include "../RenderableComponent.h"

#include <unordered_map>

namespace Engine {

	class ObjectManager : public BaseManager {

	public:
		ObjectManager();
		~ObjectManager();

		GameObject* createGameObject(const char* name);

		void addGameObject(GameObject* game_object);
		void removeGameObject(GameObject* game_object);

		void addComponent(Component *component);
		void removeComponent(Component *component);

		void addRenderableComponent(RenderableComponent *renderable_component);
		void removeRenderableComponent(RenderableComponent *renderable_component);

		std::unordered_map<unsigned int, GameObject*>& getGameObjects();
		std::unordered_map<unsigned int, Component*>& getComponents();
		std::unordered_map<unsigned int, RenderableComponent*>& getRenderableComponents();

	private:
		void destroyComponents();

	private:
		std::unordered_map<unsigned int, GameObject*> game_objects_;
		std::unordered_map<unsigned int, Component*> components_;
		std::unordered_map<unsigned int, RenderableComponent*> renderable_components_;
	};

	extern ObjectManager* pObjectManager;
}