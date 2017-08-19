#include "CameraManager.h"
#include "LogManager.h"
#include "DeviceManager.h"

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

	void CameraManager::setupCamera(float width, float height) {
		//projection = glm::perspective( 45.0f, ( float )coreSettings->GetWindowWidth( )/( float )coreSettings->GetWindowHeight( ), 0.1f, 1000.0f );
		default_camera_.setToPerspective(width, height, 45.0f, 0.1f, 100.0f);
		//default_camera_.setToOrtographic(width, height, 0.0f, 10.0f, 1.0f);
		default_camera_.setClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		setMainCamera(default_camera_);
	}

	Camera* CameraManager::getMainCamera() {
		return camera_;
	}

	void CameraManager::setMainCamera(Camera &camera) {
		camera_ = &camera;
	}
}
