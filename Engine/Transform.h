#pragma once
#include "Component.h"
#include <glm.hpp>
#include <unordered_set>

namespace Engine {

	class GameObject;

	class Transform {

	public:
		Transform();
		Transform(const glm::vec3 &position_, const glm::vec3 &rotation, const glm::vec3 &scale);
		~Transform();

		void setLocalPosition(const glm::vec3 &position);
		void setLocalScale(const glm::vec3 &scale);
		void setLocalRotation(const glm::vec3 &rotation);

		void move(const glm::vec3 &v);
		void rotate(const glm::vec3 &v);
		void scale(const glm::vec3 &v);

		GameObject* getGameObject() const;
		void setGameObject(GameObject *game_object);

		Transform* getParent() const;
		void setParent(Transform *transform);

		void addChild(Transform *transform);
		void removeChild(Transform *transform);

		glm::vec3& getPosition();
		glm::vec3& getScale();
		glm::vec3& getRotation();

		glm::vec3& getLocalPosition();
		glm::vec3& getLocalScale();
		glm::vec3& getLocalRotation();

		glm::mat4& getLocalToWorldMatrix();
		glm::mat4& getWorldToLocalMatrix();

		void setDirty();

	private:
		GameObject *game_object_;
		Transform *parent_;

		glm::mat4 local_to_world_matrix_;
		glm::mat4 world_to_local_matrix_;

		glm::vec3 local_position_;
		glm::vec3 local_rotation_;
		glm::vec3 local_scale_;

		std::unordered_set<Transform*> children_;

		bool is_dirty_;
		bool is_inverse_dirty_;
	};
}