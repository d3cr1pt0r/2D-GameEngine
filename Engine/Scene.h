#pragma once
#include "GameObject.h"

namespace Engine {

	class Scene {

	public:
		Scene();
		~Scene();

	private:
		GameObject parent_;
	};
}