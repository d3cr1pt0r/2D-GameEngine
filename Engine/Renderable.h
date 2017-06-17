#pragma once
#include <glew.h>
#include "Transform.h"

namespace Engine {

	class Renderable {

	public:
		Renderable();
		~Renderable();

		void init();
		void render();
		void destroy();

	public:
		Transform transform_;

	private:
		void generateQuad(float x, float y, float width, float height);

	private:
		GLuint vbo_id_ = 0;
		float vertex_data_[12];
	};
}

