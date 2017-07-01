#include "MeshResource.h"
#include "Vertex.h"
#include "Manager.h"

#include <cstddef>

namespace Engine {

	MeshResource::MeshResource() : ibo_(0), vao_(0), vbo_(0), initialized_(false) {
	}

	MeshResource::~MeshResource() {
	}

	void MeshResource::init() {
		if (initialized_) {
			return;
		}

		if (vao_ == 0) {
			glGenVertexArrays(1, &vao_);
		}
		bindVAO();

		if (vbo_ == 0) {
			glGenBuffers(1, &vbo_);
		}
		bindVBO();

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


		// unbind vao
		unbindVAO();

		// disable vertex attrib arrays
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glDisableVertexAttribArray(3);

		// unbind vbo
		unbindVBO();

		initialized_ = true;
	}

	void MeshResource::destroy() {
		if (vbo_ == 0) {
			pLogManager->logError("MeshResource", "Failed to delete vertex buffer object.");
			return;
		}

		if (vao_ == 0) {
			pLogManager->logError("MeshResource", "Failed to delete vertex array object.");
			return;
		}

		unbindVBO();
		glDeleteBuffers(1, &vbo_);
		vbo_ = 0;
		
		unbindVAO();
		glDeleteVertexArrays(1, &vao_);
		vao_ = 0;
	}

	void MeshResource::bindVAO() {
		glBindVertexArray(vao_);
	}

	void MeshResource::unbindVAO() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void MeshResource::bindVBO() {
		glBindBuffer(GL_ARRAY_BUFFER, vbo_);
	}

	void MeshResource::unbindVBO() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void MeshResource::upload(std::vector<Vertex>& vertex_data) {
		bindVBO();

		glBufferData(GL_ARRAY_BUFFER, vertex_data.size() * sizeof(Vertex), nullptr, GL_STATIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, vertex_data.size() * sizeof(Vertex), vertex_data.data());

		unbindVBO();
	}
}