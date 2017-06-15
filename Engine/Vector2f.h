#pragma once
#include <iostream>

namespace Engine {

	class Vector2f {

	public:
		Vector2f();
		Vector2f(const Vector2f &v);
		Vector2f(const float &x, const float &y);
		~Vector2f();

		const float distance(const Vector2f &v) const;
		const float dot(const Vector2f &v) const;
		const float magnitude() const;
		const float sqrMagnitude() const;
		const Vector2f normalized() const;

		const Vector2f operator+(const Vector2f &v) const;
		const Vector2f operator-(const Vector2f &v) const;
		const Vector2f operator*(const float &n) const;
		const Vector2f operator/(const float &n) const;
		const bool operator==(const Vector2f &v) const;

		friend std::ostream& operator<<(std::ostream &os, const Vector2f &v);

	public:
		float x_;
		float y_;
	};
}