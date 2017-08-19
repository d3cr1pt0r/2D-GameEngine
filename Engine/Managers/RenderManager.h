#pragma once
#include "BaseManager.h"

namespace Engine {

	class RenderManager : public BaseManager {

	public:
		RenderManager();
		~RenderManager();

		void render();
	};

	extern RenderManager* pRenderManager;
}