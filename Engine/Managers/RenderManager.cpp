#include "RenderManager.h"

#include "LogManager.h"
#include "CameraManager.h"
#include "ObjectManager.h"
#include "DeviceManager.h"

namespace Engine {

	RenderManager* pRenderManager = nullptr;

	RenderManager::RenderManager() {
		pLogManager->logDebug("RenderManager", "initialized");

		pRenderManager = this;
	}

	RenderManager::~RenderManager() {
		pLogManager->logDebug("RenderManager", "destroyed");

		pRenderManager = nullptr;
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

		pDeviceManager->swapBuffers();
	}
}

