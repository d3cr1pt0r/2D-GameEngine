#include "GLSLShader.h"

#include <fstream>
#include <vector>

#include "ErrorLog.h"

namespace Engine {

	GLSLShader::GLSLShader(const std::string &vertex_shader_file_path, const std::string &fragment_shader_file_path) :
		vertex_shader_file_path_(vertex_shader_file_path),
		fragment_shader_file_path_(fragment_shader_file_path),
		program_id_(0),
		vertex_shader_id_(0),
		fragment_shader_id_(0),
		num_attributes_(0)
	{}

	GLSLShader::~GLSLShader() {
	}

	bool GLSLShader::init() {
		bool error = false;

		bool program_created = createProgram(program_id_);
		if (!program_created) {
			ErrorLog::log("GLSLShader", "Failed to create shader program!");
			error = true;
		}

		bool vertex_shader_created = createShader(vertex_shader_id_, GL_VERTEX_SHADER);
		if (!vertex_shader_created) {
			ErrorLog::log("GLSLShader", "Failed to create vertex shader!");
			error = true;
		}

		bool fragment_shader_created = createShader(fragment_shader_id_, GL_FRAGMENT_SHADER);
		if (!fragment_shader_created) {
			ErrorLog::log("GLSLShader", "Failed to create fragment shader!");
			error = true;
		}

		bool vertex_shader_compiled = compileShader(vertex_shader_file_path_, vertex_shader_id_);
		if (!vertex_shader_compiled) {
			ErrorLog::log("GLSLShader", "Failed to compile vertex shader!");
			error = true;
		}

		bool fragment_shader_compiled = compileShader(fragment_shader_file_path_, fragment_shader_id_);
		if (!fragment_shader_compiled) {
			ErrorLog::log("GLSLShader", "Failed to compile fragment shader!");
			error = true;
		}

		if (error) {
			deleteProgram(program_id_);
			return false;
		}

		return link();
	}

	void GLSLShader::bind() {
		glUseProgram(program_id_);

		for (int i = 0; i < num_attributes_; i++) {
			glEnableVertexAttribArray(i);
		}
	}

	void GLSLShader::unbind() {
		glUseProgram(0);

		for (int i = 0; i < num_attributes_; i++) {
			glDisableVertexAttribArray(i);
		}
	}

	bool GLSLShader::link() {
		attachShader(vertex_shader_id_);
		attachShader(fragment_shader_id_);

		glLinkProgram(program_id_);

		GLuint success = 0;
		glGetProgramiv(program_id_, GL_LINK_STATUS, (int *)&success);

		if (success == GL_FALSE) {
			GLint max_length = 0;
			glGetProgramiv(program_id_, GL_INFO_LOG_LENGTH, &max_length);

			std::vector<char> error_log(max_length);
			glGetProgramInfoLog(program_id_, max_length, &max_length, &error_log[0]);

			deleteProgram(program_id_);
			deleteShader(vertex_shader_id_);
			deleteShader(fragment_shader_id_);

			ErrorLog::log("GLSLShader", &error_log[0]);
			return false;
		}

		detachShader(vertex_shader_id_);
		detachShader(fragment_shader_id_);

		deleteShader(vertex_shader_id_);
		deleteShader(fragment_shader_id_);

		return true;
	}

	void GLSLShader::addAttribute(const std::string & attribute_name) {
		glBindAttribLocation(program_id_, num_attributes_, attribute_name.c_str());
		num_attributes_++;
	}

	bool GLSLShader::createProgram(GLuint &program_id) {
		if (program_id != 0) {
			deleteProgram(program_id);
		}

		program_id_ = glCreateProgram();

		return program_id_ != 0;
	}

	void GLSLShader::deleteProgram(GLuint &program_id) {
		glDeleteProgram(program_id);
	}

	bool GLSLShader::createShader(GLuint &shader_id, GLenum shader_type) {
		if (shader_id != 0) {
			deleteShader(shader_id);
		}

		shader_id = glCreateShader(shader_type);

		return shader_id != 0;
	}

	void GLSLShader::attachShader(GLuint & shader_id) {
		glAttachShader(program_id_, shader_id);
	}

	void GLSLShader::deleteShader(GLuint &shader_id) {
		glDeleteShader(shader_id);
	}

	void GLSLShader::detachShader(GLuint & shader_id) {
		glDetachShader(program_id_, shader_id);
	}

	bool GLSLShader::compileShader(const std::string &shader_file_path, GLuint &shader_id) {
		std::string shader_contetns = readFile(shader_file_path);
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

			deleteShader(shader_id);

			ErrorLog::log("GLSLShader", &error_log[0]);
			return false;
		}

		return true;
	}

	std::string GLSLShader::readFile(const std::string & file_path) {
		std::ifstream file(file_path);

		if (file.fail()) {
			perror(file_path.c_str());
			ErrorLog::log("GLSLShader", "Failed to create ifstream");

			return "";
		}

		std::string file_contents = "";
		std::string line;

		while (std::getline(file, line)) {
			file_contents += line + "\n";
		}

		file.close();

		return file_contents;
	}
}
