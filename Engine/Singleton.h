#pragma once
#include "INonCopyable.h"

namespace Engine {

	template <class T>
	class Singleton : INonCopyable {
		
	public:
		static T& getInstance() {
			static T instance;
			return instance;
		}

		virtual void onCreate() = 0;
		virtual void onDestroy() = 0;

	protected:
		explicit Singleton<T>() { }
	};
}