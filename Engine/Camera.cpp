#include "Camera.h"
#include "Managers\ManagerSystem.h"
#include <glew.h>

namespace Engine {

	Camera::Camera() : Camera(glm::vec3(0.0f), glm::vec3(0.0f)) {
	}

	Camera::Camera(const glm::vec3 &position, const glm::vec3 &rotation) :
		GameObject("Camera"),
		clear_color_(),
		matrix_(),
		width_(800.0f),
		height_(600.0f),
		fov_(60.0f),
		near_plane_(-0.01f),
		far_plane_(100.0f),
		scale_(1.0f)
	{
		transform_.setLocalPosition(position);
		transform_.setLocalRotation(rotation);
	}

	Camera::~Camera() {
	}

	void Camera::clear() {
		glClearDepth(1.0);
		glClearColor(clear_color_.r_, clear_color_.g_, clear_color_.b_, clear_color_.a_);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Camera::setToOrtographic(const float &width, const float &height, const float &near_plane, const float &far_plane, const float &scale) {
		width_ = width;
		height_ = height;
		near_plane_ = near_plane;
		far_plane_ = far_plane;
		scale_ = scale;

		matrix_ = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, near_plane_, far_plane_);
	}

	void Camera::setToPerspective(const float &width, const float &height, const float &fov, const float &near_plane, const float &far_plane) {
		width_ = width;
		height_ = height;
		fov_ = fov;
		near_plane_ = near_plane;
		far_plane_ = far_plane;

		matrix_ = glm::perspective(fov_, width_ / height_, near_plane_, far_plane_);
	}

	void Camera::setClearColor(const Color &color) {
		clear_color_ = color;
	}

	void Camera::setClearColor(const float &r, const float &g, const float &b, const float &a) {
		clear_color_.r_ = r;
		clear_color_.g_ = g;
		clear_color_.b_ = b;
		clear_color_.a_ = a;
	}

	const Color& Camera::getClearColor() const {
		return clear_color_;
	}

	glm::mat4& Camera::getProjectionMatrix() {
		return matrix_;
	}

	glm::mat4& Camera::getInverseTransformMatrix() {
		return transform_.getWorldToLocalMatrix();
	}
}
