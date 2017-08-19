#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Managers\CameraManager.h"

namespace Engine {

	SpriteRenderer::SpriteRenderer() : color_(), mesh_(), material_() {

	}

	SpriteRenderer::~SpriteRenderer() {

	}

	void SpriteRenderer::onCreate() {
		RenderableComponent::onCreate();

		material_.init();

		rebuildMesh();
	}

	void SpriteRenderer::onDestroy() {
		RenderableComponent::onDestroy();

		mesh_.deinit();
		material_.deinit();
	}

	void SpriteRenderer::onRender() {
		material_.bind();

		glm::mat4 model_matrix = getGameObject()->transform_.getLocalToWorldMatrix();
		glm::mat4 view_matrix = pCameraManager->getMainCamera()->getInverseTransformMatrix();
		glm::mat4 projection_matrix = pCameraManager->getMainCamera()->getProjectionMatrix();

		glm::mat4 mvp = projection_matrix * view_matrix * model_matrix;

		material_.shader_.setUniform("MVP", mvp);

		mesh_.render();

		material_.unbind();
	}

	void SpriteRenderer::setColor(const Color& color) {
		color_ = color;
		rebuildMesh();
	}

	void SpriteRenderer::rebuildMesh() {
		mesh_.begin();

		glm::vec3 half_scale(0.5f);

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
}

