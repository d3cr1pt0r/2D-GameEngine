#include "Transform.h"
#include "Manager.h"
#include "GameObject.h"

#include <gtc\matrix_transform.hpp>
#include <gtx\transform.hpp>

namespace Engine {

	Transform::Transform() :
		Transform(glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(1.0f))
	{}

	Transform::Transform(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) :
		game_object_(0),
		parent_(0),
		local_to_world_matrix_(1.0f),
		world_to_local_matrix_(1.0f),
		local_position_(position),
		local_rotation_(rotation),
		local_scale_(scale),
		is_dirty_(true),
		is_inverse_dirty_(true)
	{
	}


	Transform::~Transform() {
		
	}

	void Transform::setLocalPosition(const glm::vec3 &position) {
		local_position_ = position;
		setDirty();
	}

	void Transform::setLocalRotation(const glm::vec3 &rotation) {
		local_rotation_ = rotation;
		setDirty();
	}

	void Transform::setLocalScale(const glm::vec3 &scale) {
		local_scale_ = scale;
		setDirty();
	}

	void Transform::move(const glm::vec3 &v) {
		local_position_ += v;
		setDirty();
	}

	void Transform::rotate(const glm::vec3 &v) {
		local_rotation_ += v;
		setDirty();
	}

	void Transform::scale(const glm::vec3 &v) {
		local_scale_ += v;
		setDirty();
	}

	GameObject* Transform::getGameObject() const {
		return game_object_;
	}

	void Transform::setGameObject(GameObject *game_object) {
		game_object_ = game_object;
	}

	Transform * Transform::getParent() const {
		return parent_;
	}

	void Transform::setParent(Transform *transform) {
		if (parent_ != 0) {
			parent_->removeChild(this);
		}

		parent_ = transform;
		parent_->addChild(this);

		setDirty();
	}

	void Transform::addChild(Transform *transform) {
		children_.emplace(transform);
	}

	void Transform::removeChild(Transform *transform) {
		children_.erase(transform);
	}

	glm::vec3& Transform::getPosition() {
		glm::mat4 m = getLocalToWorldMatrix();
		glm::vec4 v = glm::vec4(local_position_.x, local_position_.y, local_position_.z, 1.0f);
		glm::vec4 r = m * v;

		return glm::vec3(r.x, r.y, r.z);
	}

	glm::vec3& Transform::getRotation() {
		return local_rotation_;
	}

	glm::vec3& Transform::getScale() {
		return local_scale_;
	}

	glm::vec3 & Transform::getLocalPosition() {
		return local_position_;
	}

	glm::vec3 & Transform::getLocalRotation() {
		return local_rotation_;
	}
	
	glm::vec3 & Transform::getLocalScale() {
		return local_scale_;
	}

	glm::mat4& Transform::getLocalToWorldMatrix() {
		if (!is_dirty_) {
			return local_to_world_matrix_;
		}

		if (parent_ == 0) {
			local_to_world_matrix_ = glm::translate(local_position_) * glm::rotate(local_rotation_.z, glm::vec3(0.0f, 0.0f, 1.0f)) * glm::scale(local_scale_);
		}
		else {
			local_to_world_matrix_ = parent_->getLocalToWorldMatrix() * glm::translate(local_position_) * glm::rotate(local_rotation_.z, glm::vec3(0.0f, 0.0f, 1.0f)) * glm::scale(local_scale_);
		}

		is_dirty_ = false;

		return local_to_world_matrix_;
	}

	glm::mat4& Transform::getWorldToLocalMatrix() {
		if (!is_inverse_dirty_) {
			return world_to_local_matrix_;
		}

		world_to_local_matrix_ = glm::inverse(getLocalToWorldMatrix());
		is_inverse_dirty_ = false;

		return world_to_local_matrix_;
	}

	void Transform::setDirty() {
		if (!is_dirty_) {
			is_dirty_ = true;
			is_inverse_dirty_ = true;

			for (auto it = children_.begin(); it != children_.end(); ++it) {
				(*it)->setDirty();
			}
		}
	}
}