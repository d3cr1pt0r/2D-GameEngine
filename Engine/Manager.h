#pragma once

namespace Engine {

	class Manager {

	public:
		Manager* getInstance();

	private:
		Manager();

	private:
		static Manager* instance_;
	};
}