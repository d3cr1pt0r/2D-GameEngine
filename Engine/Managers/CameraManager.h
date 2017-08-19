#pragma once
#include "BaseManager.h"
#include "../Camera.h"

namespace Engine {

	class CameraManager : public BaseManager {

	public:
		CameraManager();
		~CameraManager();

		void setupCamera(float width, float height);

		Camera* getMainCamera();
		void setMainCamera(Camera &camera);

	private:
		Camera default_camera_;
		Camera *camera_;
	};

	extern CameraManager* pCameraManager;
}