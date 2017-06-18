#pragma once
#include <glew.h>
#include <glm.hpp>
#include "Transform.h"
#include "Color.h"
#include "GLSLShader.h"
#include "Vertex.h"

namespace Engine {

	class Renderable {

	public:
		Renderable();
		Renderable(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale, const Color &color);
		~Renderable();

		void init();
		void render();
		void destroy();

	public:
		Transform transform_;
		Color color_;

	private:
		void generateQuad(const glm::vec2 &scale);

	private:
		GLuint vbo_id_ = 0;
		GLSLShader shader_;
		Vertex vertex_data_[6];
	};
}

