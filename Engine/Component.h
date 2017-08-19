#pragma once
#include "Object.h"
#include "IComponent.h"

namespace Engine {

	class GameObject;

	class Component : public Object, public IComponent {
	
	public:
		Component(const char *name);
		virtual ~Component();

		virtual void onCreate() override;
		virtual void onUpdate() override;
		virtual void onDestroy() override;

		GameObject* getGameObject();
		void setGameObject(GameObject* game_object);

	private:
		GameObject* game_object_;
	};
}

