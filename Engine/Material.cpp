#include "Material.h"

namespace Engine {

	Material::Material() :
		Material("../Engine/Shaders/default.vert", "../Engine/Shaders/default.frag") {}

	Material::Material(const char *vertex_shader_file_path, const char *fragment_shader_file_path) :
		shader_(vertex_shader_file_path, fragment_shader_file_path) {}

	Material::~Material() {
	}

	void Material::init() {
		shader_.init();

		shader_.addAttribute("vertex_position");
		shader_.addAttribute("vertex_normal");
		shader_.addAttribute("vertex_uv");
		shader_.addAttribute("vertex_color");
	}

	void Material::destroy() {
		shader_.destroy();
	}

	void Material::bind() {
		shader_.bind();
	}

	void Material::unbind() {
		shader_.unbind();
	}
}
