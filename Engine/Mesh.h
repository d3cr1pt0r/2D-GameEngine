#pragma once
#include <glew.h>
#include <glm.hpp>
#include <vector>
#include "Vertex.h"

namespace Engine {

	class Mesh {

	public:
		Mesh();
		~Mesh();

		void init();
		void build();
		void render();
		void clear();
		void destroy();

	public:
		std::vector<glm::vec3> vertices_;
		std::vector<glm::vec3> normals_;
		std::vector<glm::vec2> uvs_;
		std::vector<glm::vec4> colors_;
		std::vector<unsigned int> indices_;

	private:
		void createVertexArrayAndBuffer();
		void buildVertexData();
		void uploadVertexData();

	private:
		GLuint ibo_;
		GLuint vao_;
		GLuint vbo_;

		std::vector<Vertex> vertex_data_;
	};
}