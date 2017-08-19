#pragma once
#include "BaseManager.h"
#include "../Camera.h"

namespace Engine {

	class CameraManager : public BaseManager {

	public:
		CameraManager();
		~CameraManager();

		void setupDefaultCamera(float width, float height);

		Camera* getMainCamera();
		void setMainCamera(Camera &camera);

	private:
		GameObject* camera_game_object_ = nullptr;
		Camera* camera_component_ = nullptr;
	};

	extern CameraManager* pCameraManager;
}