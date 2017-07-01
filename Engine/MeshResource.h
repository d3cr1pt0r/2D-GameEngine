#pragma once
#include <glew.h>
#include <vector>
#include "Vertex.h"

namespace Engine {

	class MeshResource {

	public:
		MeshResource();
		~MeshResource();
	
		void init();
		void destroy();
		void bindVAO();
		void unbindVAO();
		void bindVBO();
		void unbindVBO();
		void upload(std::vector<Vertex> &vertex_data);

	private:
		GLuint ibo_;
		GLuint vao_;
		GLuint vbo_;

		bool initialized_;
	};
}