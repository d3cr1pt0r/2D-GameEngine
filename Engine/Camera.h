#pragma once
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include "Transform.h"
#include "Color.h"

namespace Engine {

	class Camera {

	public:
		Camera();
		Camera(const glm::vec3 &position, const glm::vec3 &rotation);
		~Camera();

		void clear();

		void setToOrtographic(const float &width, const float &height, const float &near_plane, const float &far_plane, const float &scale);
		void setToPerspective(const float &width, const float &height, const float &fov, const float &near_plane, const float &far_plane);
		void setAsMainCamera();

		glm::mat4 getProjectionMatrix();

	public:
		Transform transform_;
		Color clear_color_;

	private:
		glm::mat4 matrix_;

		float width_;
		float height_;
		float fov_;
		float near_plane_;
		float far_plane_;
		float scale_;
	};
}

