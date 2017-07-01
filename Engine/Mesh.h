#pragma once
#include <glew.h>
#include <glm.hpp>
#include <vector>
#include "MeshResource.h"
#include "Vertex.h"

namespace Engine {

	class Mesh {

	public:
		Mesh();
		~Mesh();

		void begin();
		void end();
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
		void buildVertexData();

	private:
		MeshResource mesh_resource_;
		std::vector<Vertex> vertex_data_;
	};
}