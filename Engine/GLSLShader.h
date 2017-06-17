#pragma once
#include <string>
#include <glew.h>

namespace Engine {

	class GLSLShader {

	public:
		GLSLShader(const std::string &vertex_shader_file_path, const std::string &fragment_shader_file_path);
		~GLSLShader();

		bool init();
		void bind();
		void unbind();
		void addAttribute(const std::string &attribute_name);

	private:
		bool link();
		bool createProgram(GLuint &program_id);
		void deleteProgram(GLuint &program_id);
		bool createShader(GLuint &shader_id, GLenum shader_type);
		void attachShader(GLuint &shader_id);
		void deleteShader(GLuint &shader_id);
		void detachShader(GLuint &sgader_id);
		bool compileShader(const std::string &shader_file_path, GLuint &shader_id);
		std::string readFile(const std::string &file_path);

	private:
		const std::string vertex_shader_file_path_;
		const std::string fragment_shader_file_path_;

		GLuint program_id_;
		GLuint vertex_shader_id_;
		GLuint fragment_shader_id_;

		int num_attributes_;
	};
}

