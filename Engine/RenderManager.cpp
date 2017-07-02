#include "RenderManager.h"
#include "Manager.h"

namespace Engine {

	void RenderManager::init() {
		pLogManager->logDebug("RenderManager", "initialized");
	}

	void RenderManager::destroy() {
		pLogManager->logDebug("RenderManager", "destroyed");
	}

	void RenderManager::render() {
		if (pCameraManager->getMainCamera() == 0) {
			pLogManager->logError("RenderManager", "No camera ready for rendering. Set main camera with Manager::getInstance()->camera_manager_.setMainCamera method!");
			return;
		}

		pCameraManager->getMainCamera()->clear();

		for (auto it = pObjectManager->getRenderableComponents().begin(); it != pObjectManager->getRenderableComponents().end(); ++it) {
			it->second->render();
		}

		pWindowManager->swapBuffers();
	}
}

