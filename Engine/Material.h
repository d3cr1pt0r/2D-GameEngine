#pragma once
#include "Shader.h"

namespace Engine {

	class Material {
	
	public:
		Material();
		Material(const char *vertex_shader_file_path, const char *fragment_shader_file_path);
		~Material();

		void init();
		void deinit();

		void bind();
		void unbind();

	public:
		Shader shader_;
	};
}

