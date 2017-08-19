#pragma once

namespace Engine {

	class IComponent {
	public:
		virtual void onCreate() = 0;
		virtual void onUpdate() = 0;
		virtual void onDestroy() = 0;
	};
}
