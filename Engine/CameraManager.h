#pragma once
#include "Camera.h"

namespace Engine {

	class CameraManager {

	public:
		CameraManager();
		~CameraManager();

		void setMainCamera(Camera &camera);
		Camera* getMainCamera();

	private:
		Camera *camera_;
	};
}