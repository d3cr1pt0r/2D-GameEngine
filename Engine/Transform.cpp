#include "Transform.h"
#include <gtc\matrix_transform.hpp>
#include <gtx\transform.hpp>

namespace Engine {

	Transform::Transform() :
		Transform(glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(1.0f))
	{}

	Transform::Transform(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) :
		position_(position),
		rotation_(rotation),
		scale_(scale),
		parent_(0),
		trs_matrix_(1.0f),
		identity_matrix_(1.0f)
	{}


	Transform::~Transform() {
	}

	void Transform::setPosition(const glm::vec3 &position) {
		position_ = position;
	}

	void Transform::setRotation(const glm::vec3 &rotation) {
		rotation_ = rotation;
	}

	void Transform::move(const glm::vec3 &v) {
		position_ += v;
	}

	void Transform::rotate(const glm::vec3 &v) {
		rotation_ += v;
	}

	void Transform::scale(const glm::vec3 &v) {
		scale_ += v;
	}

	void Transform::addChild(Transform *transform) {
		transform->setParent(this);
	}

	void Transform::setParent(Transform *transform) {
		parent_ = transform;
	}

	void Transform::setScale(const glm::vec3 &scale) {
		scale_ = scale;
	}

	glm::vec3& Transform::getPosition() {
		return position_;
	}

	glm::vec3& Transform::getRotation() {
		return rotation_;
	}

	glm::vec3& Transform::getScale() {
		return scale_;
	}

	glm::mat4& Transform::getModelMatrix() {
		recalculateTRS();
		return trs_matrix_;
	}

	glm::mat4& Transform::getParentModelMatrix() {
		if (parent_ != 0) {
			return parent_->getModelMatrix();
		}
		return identity_matrix_;
	}

	void Transform::recalculateTRS() {
		glm::mat4 translation_matrix = glm::translate(position_);
		glm::mat4 rotation_matrix = glm::rotate(rotation_.z, glm::vec3(0.0f, 0.0f, 1.0f));
		glm::mat4 scale_matrix = glm::scale(scale_);
		
		trs_matrix_ = getParentModelMatrix() * translation_matrix * rotation_matrix * scale_matrix;
	}
}