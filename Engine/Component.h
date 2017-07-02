#pragma once
#include "Object.h"

namespace Engine {

	class GameObject;

	class Component : public Object {
	
	public:
		Component(const char *name);
		~Component();

		void init() override;
		void destroy() override;

	public:
		GameObject *game_object_;
	};
}

