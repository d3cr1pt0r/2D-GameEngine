#include "Sprite.h"
#include "Manager.h"
#include <glm.hpp>

namespace Engine {

	Sprite::Sprite() :
		transform_(),
		mesh_(),
		shader_("../Engine/Shaders/default.vert", "../Engine/Shaders/default.frag")
	{}

	Sprite::~Sprite() {
		destroy();
	}

	void Sprite::init() {
		shader_.init();

		shader_.addAttribute("vertex_position");
		shader_.addAttribute("vertex_normal");
		shader_.addAttribute("vertex_uv");
		shader_.addAttribute("vertex_color");

		mesh_.begin();

		glm::vec3 half_scale = transform_.getScale() * 0.5f;

		// triangle 1
		mesh_.vertices_.push_back(glm::vec3(-half_scale.x, half_scale.y, 0.0f));
		mesh_.vertices_.push_back(glm::vec3(half_scale.x, half_scale.y, 0.0f));
		mesh_.vertices_.push_back(glm::vec3(half_scale.x, -half_scale.y, 0.0f));

		mesh_.normals_.push_back(glm::vec3(0.0f));
		mesh_.normals_.push_back(glm::vec3(0.0f));
		mesh_.normals_.push_back(glm::vec3(0.0f));

		mesh_.uvs_.push_back(glm::vec2(0.0f, 1.0f));
		mesh_.uvs_.push_back(glm::vec2(1.0f, 1.0f));
		mesh_.uvs_.push_back(glm::vec2(1.0f, 0.0f));

		mesh_.colors_.push_back(glm::vec4(color_.r_, color_.g_, color_.b_, color_.a_));
		mesh_.colors_.push_back(glm::vec4(color_.r_, color_.g_, color_.b_, color_.a_));
		mesh_.colors_.push_back(glm::vec4(color_.r_, color_.g_, color_.b_, color_.a_));

		// triangle 2
		mesh_.vertices_.push_back(glm::vec3(half_scale.x, -half_scale.y, 0.0f));
		mesh_.vertices_.push_back(glm::vec3(-half_scale.x, -half_scale.y, 0.0f));
		mesh_.vertices_.push_back(glm::vec3(-half_scale.x, half_scale.y, 0.0f));

		mesh_.normals_.push_back(glm::vec3(0.0f));
		mesh_.normals_.push_back(glm::vec3(0.0f));
		mesh_.normals_.push_back(glm::vec3(0.0f));

		mesh_.uvs_.push_back(glm::vec2(1.0f, 0.0f));
		mesh_.uvs_.push_back(glm::vec2(0.0f, 0.0f));
		mesh_.uvs_.push_back(glm::vec2(0.0f, 1.0f));

		mesh_.colors_.push_back(glm::vec4(color_.r_, color_.g_, color_.b_, color_.a_));
		mesh_.colors_.push_back(glm::vec4(color_.r_, color_.g_, color_.b_, color_.a_));
		mesh_.colors_.push_back(glm::vec4(color_.r_, color_.g_, color_.b_, color_.a_));

		mesh_.end();
	}

	void Sprite::render() {
		shader_.bind();

		glm::mat4 model_matrix = transform_.getModelMatrix();
		glm::mat4 view_matrix = pCameraManager->getMainCamera()->getInverseTransformMatrix();
		glm::mat4 projection_matrix = pCameraManager->getMainCamera()->getProjectionMatrix();

		glm::mat4 mvp = projection_matrix * view_matrix * model_matrix;

		shader_.setUniform("MVP", mvp);

		mesh_.render();

		shader_.unbind();
	}

	void Sprite::destroy() {
		mesh_.destroy();
	}
}