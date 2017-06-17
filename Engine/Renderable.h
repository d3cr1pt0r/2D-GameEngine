#pragma once
#include <glew.h>
#include "Transform.h"
#include "Color.h"
#include "GLSLShader.h"
#include "Vertex.h"

namespace Engine {

	class Renderable {

	public:
		Renderable();
		Renderable(const Engine::Vector2f &position, const Engine::Vector2f &scale, const Color &color);
		~Renderable();

		void init();
		void update();
		void render();
		void destroy();

	public:
		Transform transform_;
		Color color_;

	private:
		void generateQuad(float x, float y, float width, float height);

	private:
		GLuint vbo_id_ = 0;
		GLSLShader shader_;
		Vertex vertex_data_[6];
	};
}

