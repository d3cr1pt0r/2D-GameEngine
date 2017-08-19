#pragma once
#include "Object.h"
#include "Transform.h"
#include <vector>

namespace Engine {

	class Component;

	class GameObject : public Object {

	public:
		GameObject();
		GameObject(const char *name);
		~GameObject();

		void setParent(GameObject *game_object);
		void destroy();

		template <class T>
		inline T* addComponent() {
			Component* component;

			// return existing component if exists
			for (int i = 0; i < components_.size(); i++) {
				T* c = dynamic_cast<T*>(components_[i]);
				if (c != nullptr) {
					return c;
				}
			}

			// create a new component and add it to the list of components under current game object
			component = new T();
			component->setGameObject(this);
			component->onCreate();

			components_.push_back(component);

			return reinterpret_cast<T*>(component);
		}

		template <class T>
		inline T* getComponent() {
			for (int i = 0; i < components_.size(); i++) {
				T* c = dynamic_cast<T*>(components_[i]);
				if (c != nullptr) {
					return components_[i];
				}
			}

			return nullptr;
		}

		template <class T>
		inline void removeComponent() {
			for (int i = 0; i < components_.size(); i++) {
				T* c = dynamic_cast<T*>(components_[i]);
				if (c != nullptr) {
					components_[i]->onDestroy();
					components_.erase(components_.begin() + i);

					break;
				}
			}
		}

	public:
		Transform transform_;

	private:
		std::vector<Component*> components_;
		uint32_t layer;

	};
}

