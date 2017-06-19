#pragma once
#include "BaseManager.h"
#include "Camera.h"

namespace Engine {

	class CameraManager : public BaseManager {

	public:
		void init() override;
		void destroy() override;

		void setMainCamera(Camera &camera);
		Camera* getMainCamera();

	private:
		Camera default_camera_;
		Camera *camera_;
	};
}