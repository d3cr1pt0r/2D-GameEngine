#pragma once
#include <glm.hpp>

namespace Engine {

	class Transform {

	public:
		Transform();
		Transform(const glm::vec3 &position_, const glm::vec3 &rotation, const glm::vec3 &scale);
		~Transform();

		void setPosition(const glm::vec3 &position);
		void setScale(const glm::vec3 &scale);
		void setRotation(const glm::vec3 &rotation);

		void move(const glm::vec3 &v);
		void rotate(const glm::vec3 &v);
		void scale(const glm::vec3 &v);

		glm::vec3& getPosition();
		glm::vec3& getScale();
		glm::vec3& getRotation();

		glm::mat4& getTransformMatrix();

	private:
		void recalculateTRS();

	private:
		glm::mat4 trs_matrix_;

		glm::vec3 position_;
		glm::vec3 rotation_;
		glm::vec3 scale_;
	};
}