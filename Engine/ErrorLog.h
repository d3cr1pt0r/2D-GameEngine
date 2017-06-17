#pragma once
#include <iostream>

namespace Engine {

	class ErrorLog {

	public:
		inline static void log(const char *tag, const char *log) {
			std::cout << "Engine<" << tag << ">: " << log << std::endl;
		}
	};
}