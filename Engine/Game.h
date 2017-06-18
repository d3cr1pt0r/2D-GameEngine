#pragma once

namespace Engine {

	class Game {

	public:
		virtual void init() = 0;
		virtual void update(const float &delta_time) = 0;
		virtual void render() = 0;
		virtual void destroy() = 0;
	};
}