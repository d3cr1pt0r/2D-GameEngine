#pragma once
#include "BaseManager.h"

#include <iostream>
#include <string>
#include <glm.hpp>

namespace Engine {

	class LogManager : public BaseManager {

	public:
		LogManager();
		~LogManager();

		inline void logDebug(const std::string &tag, const char *fmt, ...) {
			printf("DEBUG: Engine<%s>: ", tag.c_str());
			printf(fmt);
			printf("\n");

		}

		inline void logWarning(const std::string &tag, const char *fmt, ...) {
			printf("WARNING: Engine<%s>: ", tag.c_str());
			printf(fmt);
			printf("\n");
		}

		inline void logError(const std::string &tag, const char *fmt, ...) {
			printf("ERROR: Engine<%s>: ", tag.c_str());
			printf(fmt);
			printf("\n");
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

	extern LogManager* pLogManager;

}