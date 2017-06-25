#include "IOManager.h"
#include <fstream>
#include <string>
#include <iostream>

const std::string Engine::IOManager::readFile(const char * filename) {
	std::ifstream file(filename);

	if (file.fail()) {
		perror(filename);
		return nullptr;
	}
	
	std::string contents;
	std::string line;

	while (std::getline(file, line)) {
		contents += line;
		contents.push_back('\n');
	}

	return contents;
}

