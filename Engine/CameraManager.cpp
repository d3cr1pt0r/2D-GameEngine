#include "CameraManager.h"

namespace Engine {

	CameraManager::CameraManager() : camera_(0) {
	}

	CameraManager::~CameraManager() {
	}

	void Engine::CameraManager::setMainCamera(Camera &camera) {
		camera_ = &camera;
	}

	Camera* Engine::CameraManager::getMainCamera() {
		return camera_;
	}
}
