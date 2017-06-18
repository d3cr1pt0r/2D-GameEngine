#include "Mesh.h"
#include "Log.h"

namespace Engine {

	Mesh::Mesh() : ibo_(0), vao_(0), vbo_(0), initialized_(false) {
	}

	Mesh::~Mesh() {
		destroy();
	}

	void Mesh::begin() {
		if (!initialized_) {
			createVertexArrayAndBuffer();
			initialized_ = true;
		}
		clear();
	}

	void Mesh::end() {
		buildVertexData();
		uploadVertexData();
	}

	void Mesh::render() {
		glBindVertexArray(vao_);
		glDrawArrays(GL_TRIANGLES, 0, vertex_data_.size());
		glBindVertexArray(0);
	}

	void Mesh::clear() {
		vertices_.clear();
		normals_.clear();
		uvs_.clear();
		colors_.clear();
		indices_.clear();
		vertex_data_.clear();
	}

	void Mesh::destroy() {
		clear();

		if (vao_ != 0) {
			glDeleteVertexArrays(1, &vao_);
		}
		if (vbo_ != 0) {
			glDeleteBuffers(1, &vbo_);
		}
	}

	void Mesh::createVertexArrayAndBuffer() {
		if (vao_ == 0) {
			glGenVertexArrays(1, &vao_);
		}

		glBindVertexArray(vao_);

		if (vbo_ == 0) {
			glGenBuffers(1, &vbo_);
		}

		glBindBuffer(GL_ARRAY_BUFFER, vbo_);

		// position
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position_));

		// normal
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal_));

		// uv
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, uv_));

		// color
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color_));

		glBindVertexArray(0);
	}

	void Mesh::buildVertexData() {
		const unsigned int size = vertices_.size();
		bool size_check = normals_.size() == size && uvs_.size() == size && colors_.size() == size;

		if (!size_check) {
			Log::logError("Mesh", "Vertex data lengths don't match. Make sure vertices, normals, uvs and colors are the same size!");
			Log::logFloat("Mesh:vertices_size", (float) vertices_.size());
			Log::logFloat("Mesh:normals_size", (float) normals_.size());
			Log::logFloat("Mesh:uvs_size", (float) uvs_.size());
			Log::logFloat("Mesh:colors_size", (float) colors_.size());
			return;
		}

		vertex_data_.clear();
		vertex_data_.resize(size);

		for (unsigned int i = 0; i < size; i++) {
			Vertex vertex;

			vertex.position_.x_ = vertices_[i].x;
			vertex.position_.y_ = vertices_[i].y;
			vertex.position_.z_ = vertices_[i].z;

			vertex.normal_.x_ = normals_[i].x;
			vertex.normal_.y_ = normals_[i].y;
			vertex.normal_.z_ = normals_[i].z;

			vertex.uv_.x_ = uvs_[i].x;
			vertex.uv_.y_ = uvs_[i].y;

			vertex.color_.r_ = colors_[i].x;
			vertex.color_.g_ = colors_[i].y;
			vertex.color_.b_ = colors_[i].z;
			vertex.color_.a_ = colors_[i].w;

			vertex_data_.push_back(vertex);
		}
	}

	void Mesh::uploadVertexData() {
		glBindBuffer(GL_ARRAY_BUFFER, vbo_);

		glBufferData(GL_ARRAY_BUFFER, vertex_data_.size() * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, vertex_data_.size() * sizeof(Vertex), vertex_data_.data());

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}