#pragma once
#include <string>
#include <glew.h>
#include <glm.hpp>

namespace Engine {

	class GLSLShader {

	public:
		GLSLShader();
		GLSLShader(const std::string &vertex_shader_file_path, const std::string &fragment_shader_file_path);
		~GLSLShader();

		bool init();
		void bind();
		void unbind();
		void addAttribute(const std::string &attribute_name);

		void setUniform(const std::string &uniform_name, const float &v);
		void setUniform(const std::string &uniform_name, const glm::vec2 &v);
		void setUniform(const std::string &uniform_name, const glm::vec3 &v);
		void setUniform(const std::string &uniform_name, const glm::mat4 &v);

	private:
		bool link();
		bool createProgram();
		bool createShader(GLuint &shader_id, GLenum shader_type);
		bool compileShader(const std::string &shader_file_path, GLuint &shader_id);
		std::string readFile(const std::string &file_path);

		bool getUniformLocation(const std::string &uniform_name, GLuint &location);

	private:
		const std::string vertex_shader_file_path_;
		const std::string fragment_shader_file_path_;

		GLuint program_id_;
		GLuint vertex_shader_id_;
		GLuint fragment_shader_id_;

		int num_attributes_;
	};
}

