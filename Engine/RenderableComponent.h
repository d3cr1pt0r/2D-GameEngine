#pragma once
#include "Component.h"

namespace Engine {

	class RenderableComponent : public Component {

	public:
		RenderableComponent();
		~RenderableComponent();

		void init() override;
		void deinit() override;

		virtual void render() = 0;
	};
}

