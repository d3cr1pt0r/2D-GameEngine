#pragma once
#include "BaseManager.h"

namespace Engine {

	class RenderManager : public BaseManager {

	public:
		void init() override;
		void deinit() override;

		void render();
	};
}