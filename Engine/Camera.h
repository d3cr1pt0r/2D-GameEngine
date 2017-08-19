#pragma once
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

#include "Component.h"
#include "Color.h"

namespace Engine {

	class Camera : public Component {

	public:
		Camera();
		~Camera();

		void onCreate() override;
		void onUpdate() override;
		void onDestroy() override;

		void clear();

		void setToOrtographic(const float &width, const float &height, const float &near_plane, const float &far_plane, const float &scale);
		void setToPerspective(const float &width, const float &height, const float &fov, const float &near_plane, const float &far_plane);

		void setClearColor(const Color &color);
		void setClearColor(const float &r, const float &g, const float &b, const float &a);

		const Color& getClearColor() const;

		glm::mat4& getProjectionMatrix();
		glm::mat4& getInverseTransformMatrix();

	private:
		Color clear_color_;
		glm::mat4 matrix_;

		float width_;
		float height_;
		float fov_;
		float near_plane_;
		float far_plane_;
		float scale_;
	};
}

