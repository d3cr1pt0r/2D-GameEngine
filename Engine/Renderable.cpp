#include "Renderable.h"

namespace Engine {

	Renderable::Renderable() {

	}

	Renderable::Renderable(const Engine::Vector2f &position, const Engine::Vector2f &scale, const Color &color) :
		transform_(position, scale, 0),
		color_(color),
		vbo_id_(0),
		shader_("../Engine/Shaders/default.vert", "../Engine/Shaders/default.frag")
	{
	}

	Renderable::~Renderable() {
		
	}

	void Renderable::init() {
		glGenBuffers(1, &vbo_id_);
		generateQuad(transform_.position_.x_, transform_.position_.y_, transform_.scale_.x_, transform_.scale_.y_);

		shader_.init();
		shader_.addAttribute("vertex_position");
		shader_.addAttribute("vertex_color");
	}

	void Renderable::update() {
		generateQuad(transform_.position_.x_, transform_.position_.y_, transform_.scale_.x_, transform_.scale_.y_);
	}

	void Renderable::render() {
		shader_.bind();

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

	void Renderable::generateQuad(float x, float y, float width, float height) {
		vertex_data_[0].position_.x_ = x + width;
		vertex_data_[0].position_.y_ = y + height;

		vertex_data_[1].position_.x_ = x;
		vertex_data_[1].position_.y_ = y + height;

		vertex_data_[2].position_.x_ = x;
		vertex_data_[2].position_.y_ = y;

		vertex_data_[3].position_.x_ = x;
		vertex_data_[3].position_.y_ = y;

		vertex_data_[4].position_.x_ = x + width;
		vertex_data_[4].position_.y_ = y;

		vertex_data_[5].position_.x_ = x + width;
		vertex_data_[5].position_.y_ = y + height;

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
