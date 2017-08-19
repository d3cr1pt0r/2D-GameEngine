#include "RenderableComponent.h"
#include "Managers\ObjectManager.h"

namespace Engine {

	RenderableComponent::RenderableComponent() : Component("RenderableComponent") {

	}

	RenderableComponent::~RenderableComponent() {

	}

	void RenderableComponent::onCreate() {
		pObjectManager->addRenderableComponent(this);
	}

	void RenderableComponent::onUpdate() {

	}

	void RenderableComponent::onDestroy() {
		pObjectManager->removeRenderableComponent(this);
	}
}

