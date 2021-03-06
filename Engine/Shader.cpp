#include "Shader.h"

#include <fstream>
#include <vector>

#include "Managers\LogManager.h"
#include "Managers\IOManager.h"

namespace Engine {

	Shader::Shader(const char *vertex_shader_file_path, const char *fragment_shader_file_path) :
		vertex_shader_file_path_(vertex_shader_file_path),
		fragment_shader_file_path_(fragment_shader_file_path),
		program_id_(0),
		vertex_shader_id_(0),
		fragment_shader_id_(0),
		num_attributes_(0)
	{}

	Shader::~Shader() {
	}

	bool Shader::init() {
		bool error = false;

		bool program_created = createProgram();
		if (!program_created) {
			pLogManager->logError("GLSLShader", "Failed to create shader program!");
			error = true;
		}

		bool vertex_shader_created = createShader(vertex_shader_id_, GL_VERTEX_SHADER);
		if (!vertex_shader_created) {
			pLogManager->logError("GLSLShader", "Failed to create vertex shader!");
			error = true;
		}

		bool fragment_shader_created = createShader(fragment_shader_id_, GL_FRAGMENT_SHADER);
		if (!fragment_shader_created) {
			pLogManager->logError("GLSLShader", "Failed to create fragment shader!");
			error = true;
		}

		bool vertex_shader_compiled = compileShader(vertex_shader_file_path_, vertex_shader_id_);
		if (!vertex_shader_compiled) {
			pLogManager->logError("GLSLShader", "Failed to compile vertex shader!");
			error = true;
		}

		bool fragment_shader_compiled = compileShader(fragment_shader_file_path_, fragment_shader_id_);
		if (!fragment_shader_compiled) {
			pLogManager->logError("GLSLShader", "Failed to compile fragment shader!");
			error = true;
		}

		if (error) {
			glDeleteProgram(program_id_);
			return false;
		}

		return link();
	}

	void Shader::deinit() {
		if (program_id_ == 0) {
			pLogManager->logError("Shader", "Failed to destroy shader, program ID is 0");
			return;
		}

		if (vertex_shader_id_ == 0) {
			pLogManager->logError("Shader", "Failed to destroy shader, vertex shader ID is 0");
			return;
		}

		if (fragment_shader_id_ == 0) {
			pLogManager->logError("Shader", "Failed to destroy shader, fragment shader ID is 0");
			return;
		}

		unbind();

		glDeleteProgram(program_id_);
		glDeleteShader(vertex_shader_id_);
		glDeleteShader(fragment_shader_id_);
	}

	void Shader::bind() {
		glUseProgram(program_id_);

		for (int i = 0; i < num_attributes_; i++) {
			glEnableVertexAttribArray(i);
		}
	}

	void Shader::unbind() {
		glUseProgram(0);

		for (int i = 0; i < num_attributes_; i++) {
			glDisableVertexAttribArray(i);
		}
	}

	bool Shader::link() {
		glAttachShader(program_id_, vertex_shader_id_);
		glAttachShader(program_id_, fragment_shader_id_);
		
		glLinkProgram(program_id_);

		GLuint success = 0;
		glGetProgramiv(program_id_, GL_LINK_STATUS, (int *)&success);

		if (success == GL_FALSE) {
			GLint max_length = 0;
			glGetProgramiv(program_id_, GL_INFO_LOG_LENGTH, &max_length);

			std::vector<char> error_log(max_length);
			glGetProgramInfoLog(program_id_, max_length, &max_length, &error_log[0]);

			glDeleteProgram(program_id_);
			glDeleteShader(vertex_shader_id_);
			glDeleteShader(fragment_shader_id_);

			pLogManager->logError("GLSLShader", &error_log[0]);
			return false;
		}

		glDetachShader(program_id_, vertex_shader_id_);
		glDetachShader(program_id_, fragment_shader_id_);

		glDeleteShader(vertex_shader_id_);
		glDeleteShader(fragment_shader_id_);

		return true;
	}

	void Shader::addAttribute(const std::string & attribute_name) {
		glBindAttribLocation(program_id_, num_attributes_, attribute_name.c_str());
		num_attributes_++;
	}

	void Shader::setUniform(const std::string &uniform_name, const float &v) {
		GLuint location;

		if (!getUniformLocation(uniform_name, location)) {
			pLogManager->logError("GLSLShader", "Failed to get uniform location: %s", uniform_name);
			return;
		}

		glUniform1f(location, v);
	}

	void Shader::setUniform(const std::string &uniform_name, const glm::vec2 &v) {
		GLuint location;

		if (!getUniformLocation(uniform_name, location)) {
			pLogManager->logError("GLSLShader", "Failed to get uniform location: %s", uniform_name);
			return;
		}

		glUniform2fv(location, 1, &(v[0]));
	}

	void Shader::setUniform(const std::string &uniform_name, const glm::vec3 &v) {
		GLuint location;

		if (!getUniformLocation(uniform_name, location)) {
			pLogManager->logError("GLSLShader", "Failed to get uniform location: %s", uniform_name);
			return;
		}

		glUniform3fv(location, 1, &(v[0]));
	}

	void Shader::setUniform(const std::string &uniform_name, const glm::mat4 &v) {
		GLuint location;

		if (!getUniformLocation(uniform_name, location)) {
			pLogManager->logError("GLSLShader", "Failed to get uniform location: %s", uniform_name);
			return;
		}

		glUniformMatrix4fv(location, 1, GL_FALSE, &(v[0][0]));
	}

	bool Shader::getUniformLocation(const std::string &uniform_name, GLuint &location) {
		location = glGetUniformLocation(program_id_, uniform_name.c_str());
		return location != GL_INVALID_INDEX;
	}

	bool Shader::createProgram() {
		if (program_id_ != 0) {
			glDeleteProgram(program_id_);
		}

		program_id_ = glCreateProgram();

		return program_id_ != 0;
	}

	bool Shader::createShader(GLuint &shader_id, GLenum shader_type) {
		if (shader_id != 0) {
			glDeleteShader(shader_id);
		}

		shader_id = glCreateShader(shader_type);

		return shader_id != 0;
	}

	bool Shader::compileShader(const char *shader_file_path, GLuint &shader_id) {
		std::string shader_contetns = IOManager::readFile(shader_file_path);
		const char* shader_contetns_ptr = shader_contetns.c_str();

		glShaderSource(shader_id, 1, &shader_contetns_ptr, nullptr);
		glCompileShader(shader_id);

		GLint success = 0;
		glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);

		if (success == GL_FALSE) {
			GLint max_length = 0;
			glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &max_length);

			std::vector<char> error_log(max_length);
			glGetShaderInfoLog(shader_id, max_length, &max_length, &error_log[0]);

			glDeleteShader(shader_id);

			pLogManager->logError("GLSLShader", &error_log[0]);
			return false;
		}

		return true;
	}
}
