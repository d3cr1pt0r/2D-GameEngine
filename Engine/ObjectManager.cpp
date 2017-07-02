#include "ObjectManager.h"
#include "Manager.h"

namespace Engine {

	void ObjectManager::init() {
		pLogManager->logDebug("ObjectManager", "initialized");
	}
	
	void ObjectManager::deinit() {
		pLogManager->logDebug("ObjectManager", "destroyed");
	}

	void ObjectManager::addObject(Object *object) {
		objects_.emplace(std::make_pair(object->getInstanceID(), object));
		pLogManager->logDebug("ObjectManager", "Add object");
	}

	void ObjectManager::removeObject(const Object *object) {
		objects_.erase(object->getInstanceID());
		pLogManager->logDebug("ObjectManager", "Remove object");
	}

	void ObjectManager::addComponent(Component *component) {
		components_.emplace(std::make_pair(component->getInstanceID(), component));
		pLogManager->logDebug("ObjectManager", "Add component");
	}

	void ObjectManager::removeComponent(Component *component) {
		components_.erase(component->getInstanceID());
		pLogManager->logDebug("ObjectManager", "Remove component");
	}

	void ObjectManager::addRenderableComponent(RenderableComponent *renderable_component) {
		renderable_components_.emplace(std::make_pair(renderable_component->getInstanceID(), renderable_component));
		pLogManager->logDebug("ObjectManager", "Add renderable component");
	}

	void ObjectManager::removeRenderableComponent(RenderableComponent *renderable_component) {
		renderable_components_.erase(renderable_component->getInstanceID());
		pLogManager->logDebug("ObjectManager", "Remove renderable component");
	}

	std::unordered_map<unsigned int, Object*>& ObjectManager::getObjects() {
		return objects_;
	}

	std::unordered_map<unsigned int, Component*>& ObjectManager::getComponents() {
		return components_;
	}

	std::unordered_map<unsigned int, RenderableComponent*>& ObjectManager::getRenderableComponents() {
		return renderable_components_;
	}
}

