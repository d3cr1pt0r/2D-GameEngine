#pragma once
#include "BaseManager.h"
#include <iostream>
#include <string>
#include <glm.hpp>

namespace Engine {

	class LogManager : public BaseManager {

	public:
		void init() override;
		void deinit() override;

		inline void logDebug(const std::string &tag, const std::string &log) {
			std::cout << "DEBUG: Engine<" << tag.c_str() << ">: " << log.c_str() << std::endl;
		}
		inline void logWarning(const std::string &tag, const std::string &log) {
			std::cout << "WARNING: Engine<" << tag.c_str() << ">: " << log.c_str() << std::endl;
		}
		inline void logError(const std::string &tag, const std::string &log) {
			std::cout << "ERROR: Engine<" << tag.c_str() << ">: " << log.c_str() << std::endl;
		}
		inline void logFloat(const std::string &tag, const float &v) {
			std::cout << "VECTOR: Engine<" << tag.c_str() << ">: " << v << std::endl;
		}
		inline void logVector(const std::string &tag, const glm::vec2 &v) {
			std::cout << "VECTOR: Engine<" << tag.c_str() << ">: " << "x:" << v.x << " y:" << v.y << std::endl;
		}
		inline void logVector(const std::string &tag, const glm::vec3 &v) {
			std::cout << "VECTOR: Engine<" << tag.c_str() << ">: " << "x:" << v.x << " y:" << v.y << " z:" << v.z << std::endl;
		}
		inline void logVector(const std::string &tag, const glm::vec4 &v) {
			std::cout << "VECTOR: Engine<" << tag.c_str() << ">: " << "x:" << v.x << " y:" << v.y << " z:" << v.z << " w:" << v.w << std::endl;
		}
		inline void logMatrix(const std::string &tag, const glm::mat4 &m) {
			std::cout << "MATRIX_BEGIN: Engine<" << tag.c_str() << ">" << std::endl;

			std::cout << m[1][0] << " " << m[1][1] << " " << m[1][2] << " " << m[1][3] << std::endl;
			std::cout << m[2][0] << " " << m[2][1] << " " << m[2][2] << " " << m[2][3] << std::endl;
			std::cout << m[3][0] << " " << m[3][1] << " " << m[3][2] << " " << m[3][3] << std::endl;
			std::cout << m[0][0] << " " << m[0][1] << " " << m[0][2] << " " << m[0][3] << std::endl;

			std::cout << "MATRIX_END: Engine<" << tag.c_str() << ">" << std::endl;
		}
	};
}