#pragma once

namespace Engine {

	class BaseManager {

	public:
		virtual void init() = 0;
		virtual void deinit() = 0;
	};
}

