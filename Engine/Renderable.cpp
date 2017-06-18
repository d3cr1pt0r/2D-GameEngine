#include "Renderable.h"

#include <iostream>

#include "Manager.h"
#include "ErrorLog.h"

namespace Engine {

	Renderable::Renderable() : Renderable(glm::vec3(1.0f), glm::vec3(0.0f), glm::vec3(1.0f), Color()) {

	}

	Renderable::Renderable(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale, const Color &color) :
		transform_(position, rotation, scale),
		color_(color),
		vbo_id_(0),
		shader_("../Engine/Shaders/default.vert", "../Engine/Shaders/default.frag")
	{
	}

	Renderable::~Renderable() {
		
	}

	void Renderable::init() {
		glGenBuffers(1, &vbo_id_);
		generateQuad(transform_.getScale());

		shader_.init();
		shader_.addAttribute("vertex_position");
		shader_.addAttribute("vertex_color");
	}

	void Renderable::render() {
		shader_.bind();
		
		Camera *camera = Manager::getInstance()->camera_manager_.getMainCamera();

		glm::mat4 model_matrix = transform_.getTransformMatrix();
		glm::mat4 view_matrix = camera->transform_.getTransformMatrix();
		glm::mat4 projection_matrix = camera->getProjectionMatrix();

		glm::mat4 mvp = projection_matrix * view_matrix * model_matrix;

		shader_.setUniform("MVP", mvp);

		glBindBuffer(GL_ARRAY_BUFFER, vbo_id_);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position_));
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color_));
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glDisableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		shader_.unbind();
	}

	void Renderable::destroy() {

	}

	void Renderable::generateQuad(const glm::vec2 &scale) {
		float half_scale_x = scale.x * 0.5f;
		float half_scale_y = scale.y * 0.5f;

		vertex_data_[0].position_.x_ = -half_scale_x;
		vertex_data_[0].position_.y_ = half_scale_y;

		vertex_data_[1].position_.x_ = half_scale_x;
		vertex_data_[1].position_.y_ = half_scale_x;

		vertex_data_[2].position_.x_ = half_scale_x;
		vertex_data_[2].position_.y_ = -half_scale_y;

		vertex_data_[3].position_.x_ = half_scale_x;
		vertex_data_[3].position_.y_ = -half_scale_y;

		vertex_data_[4].position_.x_ = -half_scale_x;
		vertex_data_[4].position_.y_ = -half_scale_y;

		vertex_data_[5].position_.x_ = -half_scale_x;
		vertex_data_[5].position_.y_ = half_scale_y;

		for (int i = 0; i < 6; i++) {
			vertex_data_[i].color_.r_ = color_.r_;
			vertex_data_[i].color_.g_ = color_.g_;
			vertex_data_[i].color_.b_ = color_.b_;
			vertex_data_[i].color_.a_ = color_.a_;
		}

		glBindBuffer(GL_ARRAY_BUFFER, vbo_id_);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data_), vertex_data_, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
