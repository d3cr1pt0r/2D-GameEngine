#include "CameraManager.h"
#include "Manager.h"

namespace Engine {

	void CameraManager::init() {
		pLogManager->logDebug("CameraManager", "initialized");

		default_camera_.setToOrtographic(800.0f, 600.0f, 0.0f, 100.0f, 1.0f);
		default_camera_.setClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		setMainCamera(default_camera_);
	}

	void CameraManager::destroy() {
		pLogManager->logDebug("CameraManager", "destroyed");
	}

	void Engine::CameraManager::setMainCamera(Camera &camera) {
		camera_ = &camera;
	}

	Camera* Engine::CameraManager::getMainCamera() {
		return camera_;
	}
}
