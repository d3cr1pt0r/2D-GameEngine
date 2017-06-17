#include "Renderable.h"

namespace Engine {

	Renderable::Renderable() {
	}

	Renderable::~Renderable() {
		
	}

	void Renderable::init() {
		glGenBuffers(1, &vbo_id_);
		generateQuad(transform_.position_.x_, transform_.position_.y_, transform_.scale_.x_, transform_.scale_.y_);
	}

	void Renderable::render() {
		glBindBuffer(GL_ARRAY_BUFFER, vbo_id_);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glDisableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Renderable::destroy() {

	}

	void Renderable::generateQuad(float x, float y, float width, float height) {
		vertex_data_[0] = x + width;
		vertex_data_[1] = y + height;

		vertex_data_[2] = x;
		vertex_data_[3] = y + height;

		vertex_data_[4] = x;
		vertex_data_[5] = y;

		vertex_data_[6] = x;
		vertex_data_[7] = y;

		vertex_data_[8] = x + width;
		vertex_data_[9] = y;

		vertex_data_[10] = x + width;
		vertex_data_[11] = y + height;

		glBindBuffer(GL_ARRAY_BUFFER, vbo_id_);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data_), vertex_data_, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
