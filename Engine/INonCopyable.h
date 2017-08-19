#pragma once

namespace Engine {

	class INonCopyable {
	public:
		INonCopyable() {}
		~INonCopyable() {}
	private:
		INonCopyable(const INonCopyable& other);
		const INonCopyable& operator= (const INonCopyable& other);
	};
}