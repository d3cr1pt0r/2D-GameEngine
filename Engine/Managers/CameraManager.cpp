#include "CameraManager.h"

#include "LogManager.h"
#include "DeviceManager.h"
#include "ObjectManager.h"

namespace Engine {

	CameraManager* pCameraManager = nullptr;

	CameraManager::CameraManager() {
		pLogManager->logDebug("CameraManager", "initialized");

		pCameraManager = this;
	}

	CameraManager::~CameraManager() {
		pLogManager->logDebug("CameraManager", "destroyed");

		pCameraManager = nullptr;
	}

	void CameraManager::setupDefaultCamera(float width, float height) {
		if (camera_component_ == nullptr) {
			camera_game_object_ = pObjectManager->createGameObject("MainCamera");
			camera_component_ = camera_game_object_->addComponent<Camera>();
		}

		camera_component_->setToPerspective(width, height, 45.0f, 0.1f, 100.0f);
		camera_component_->setClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	}

	Camera* CameraManager::getMainCamera() {
		return camera_component_;
	}

	void CameraManager::setMainCamera(Camera &camera) {
		camera_component_ = &camera;
	}
}
