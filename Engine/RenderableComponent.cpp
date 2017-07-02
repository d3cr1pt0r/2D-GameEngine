#include "RenderableComponent.h"
#include "Manager.h"

namespace Engine {

	RenderableComponent::RenderableComponent() : Component("RenderableComponent") {
	}

	RenderableComponent::~RenderableComponent() {
	}

	void RenderableComponent::init() {
		pObjectManager->addRenderableComponent(this);
	}

	void RenderableComponent::destroy() {
		pObjectManager->removeRenderableComponent(this);
	}
}
