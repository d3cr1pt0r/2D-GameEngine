#pragma once
#include "Component.h"

namespace Engine {

	class RenderableComponent : public Component {

	public:
		RenderableComponent();
		~RenderableComponent();

		void onCreate() override;
		void onUpdate() override;
		void onDestroy() override;

		virtual void onRender() = 0;
	};
}

