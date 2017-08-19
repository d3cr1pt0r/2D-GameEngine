#include "ObjectManager.h"

#include "LogManager.h"

namespace Engine {

	ObjectManager* pObjectManager = nullptr;

	ObjectManager::ObjectManager() {
		pLogManager->logDebug("ObjectManager", "initialized");

		pObjectManager = this;
	}

	ObjectManager::~ObjectManager() {
		pLogManager->logDebug("ObjectManager", "destroyed");

		destroyComponents();

		pObjectManager = nullptr;
	}

	GameObject* ObjectManager::createGameObject(const char* name) {
		GameObject* game_object = new GameObject(name);
		addGameObject(game_object);

		return game_object;
	}

	void ObjectManager::addGameObject(GameObject * game_object) {
		game_objects_.emplace(std::make_pair(game_object->getInstanceID(), game_object));
		pLogManager->logDebug("ObjectManager", "Add GameObject name=%s instance_id=%d", game_object->getName(), game_object->getInstanceID());
	}

	void ObjectManager::removeGameObject(GameObject * game_object) {
		game_objects_.erase(game_object->getInstanceID());
		pLogManager->logDebug("ObjectManager", "Remove GameObject name=%s instance_id=%d", game_object->getName(), game_object->getInstanceID());
	}

	void ObjectManager::addComponent(Component *component) {
		components_.emplace(std::make_pair(component->getInstanceID(), component));
		pLogManager->logDebug("ObjectManager", "Add Component name=%s instance_id=%d", component->getName(), component->getInstanceID());
	}

	void ObjectManager::removeComponent(Component *component) {
		components_.erase(component->getInstanceID());
		pLogManager->logDebug("ObjectManager", "Remove Component name=%s instance_id=%d", component->getName(), component->getInstanceID());
	}

	void ObjectManager::addRenderableComponent(RenderableComponent *renderable_component) {
		renderable_components_.emplace(std::make_pair(renderable_component->getInstanceID(), renderable_component));
		pLogManager->logDebug("ObjectManager", "Add RenderableComponent name=%s instance_id=%d", renderable_component->getName(), renderable_component->getInstanceID());
	}

	void ObjectManager::removeRenderableComponent(RenderableComponent *renderable_component) {
		renderable_components_.erase(renderable_component->getInstanceID());
		pLogManager->logDebug("ObjectManager", "Remove RenderableComponent name=%s instance_id=%d", renderable_component->getName(), renderable_component->getInstanceID());
	}

	std::unordered_map<unsigned int, GameObject*>& ObjectManager::getGameObjects() {
		return game_objects_;
	}

	std::unordered_map<unsigned int, Component*>& ObjectManager::getComponents() {
		return components_;
	}

	std::unordered_map<unsigned int, RenderableComponent*>& ObjectManager::getRenderableComponents() {
		return renderable_components_;
	}

	void ObjectManager::destroyComponents() {
		// destroy objects
		for (auto it = game_objects_.begin(); it != game_objects_.end(); ++it) {
			it->second->destroy();
		}
	}
}

