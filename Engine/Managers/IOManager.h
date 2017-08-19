#pragma once
#include <string>

namespace Engine {

	class IOManager {

	public:
		static const std::string readFile(const char *filename);
	};
}

