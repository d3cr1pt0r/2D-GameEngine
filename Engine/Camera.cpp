#include "Camera.h"
#include "Manager.h"

namespace Engine {

	Camera::Camera() : Camera(glm::vec3(1.0f), glm::vec3(0.0f)) {
	}

	Camera::Camera(const glm::vec3 &position, const glm::vec3 &rotation) :
		transform_(position, rotation, glm::vec3(1.0f)),
		matrix_(),
		fov_(60.0f),
		width_(800.0f),
		height_(600.0f),
		near_plane_(-0.01f),
		far_plane_(100.0f),
		scale_(1.0f)
{}

	Camera::~Camera() {
	}

	void Camera::setToOrtographic(const float &width, const float &height, const float &scale) {
		width_ = width;
		height_ = height;
		scale_ = scale;

		matrix_ = glm::ortho(0.0f, width_, 0.0f, height_);

		setAsMainCamera();
	}

	void Camera::setToPerspective(const float &width, const float &height, const float &fov, const float &near_plane, const float &far_plane) {
		width_ = width;
		height_ = height;
		fov_ = fov;
		near_plane_ = near_plane;
		far_plane_ = far_plane;

		matrix_ = glm::perspective(fov_, 1.0f, near_plane_, far_plane_);

		setAsMainCamera();
	}

	void Camera::setAsMainCamera() {
		Manager::getInstance()->camera_manager_.setMainCamera(*this);
	}

	glm::mat4 Camera::getProjectionMatrix() {
		return matrix_;
	}
}
