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

		pObjectManager = nullptr;
	}

	void ObjectManager::addComponent(Component *component) {
		components_.emplace(std::make_pair(component->getInstanceID(), component));
		pLogManager->logDebug("ObjectManager", "Add Component");
	}

	void ObjectManager::removeComponent(Component *component) {
		components_.erase(component->getInstanceID());
		pLogManager->logDebug("ObjectManager", "Remove Component");
	}

	void ObjectManager::addRenderableComponent(RenderableComponent *renderable_component) {
		renderable_components_.emplace(std::make_pair(renderable_component->getInstanceID(), renderable_component));
		pLogManager->logDebug("ObjectManager", "Add RenderableComponent");
	}

	void ObjectManager::removeRenderableComponent(RenderableComponent *renderable_component) {
		renderable_components_.erase(renderable_component->getInstanceID());
		pLogManager->logDebug("ObjectManager", "Remove renderable component");
	}

	std::unordered_map<unsigned int, Component*>& ObjectManager::getComponents() {
		return components_;
	}

	std::unordered_map<unsigned int, RenderableComponent*>& ObjectManager::getRenderableComponents() {
		return renderable_components_;
	}
}

