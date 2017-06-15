#include "Vector2f.h"

Vector2f::Vector2f() :
	x_(0),
	y_(0) {}

Vector2f::Vector2f(const Vector2f &v) :
	x_(v.x_),
	y_(v.y_) {}

Vector2f::Vector2f(const float &x, const float &y) :
	x_(x),
	y_(y) {}


Vector2f::~Vector2f() {
}

const float Vector2f::distance(const Vector2f &v) const {
	float a = v.x_ - x_;
	float b = v.y_ - y_;

	return sqrt(a * a + b * b);
}

const float Vector2f::dot(const Vector2f &v) const {
	return x_ * v.x_ + y_ * v.y_;
}

const float Vector2f::magnitude() const {
	return sqrt(x_ * x_ + y_ * y_);
}

const float Vector2f::sqrMagnitude() const {
	return x_ * x_ + y_ * y_;
}

const Vector2f Vector2f::normalized() const {
	float magnitude = this->magnitude();
	return Vector2f(x_ / magnitude, y_ / magnitude);
}

const Vector2f Vector2f::operator+(const Vector2f &v) const {
	return Vector2f(x_ + v.x_, y_ + v.y_);
}

const Vector2f Vector2f::operator-(const Vector2f &v) const {
	return Vector2f(x_ - v.x_, y_ - v.y_);
}

const Vector2f Vector2f::operator*(const float &n) const {
	return Vector2f(x_ * n, y_ * n);
}

const Vector2f Vector2f::operator/(const float &n) const {
	return Vector2f(x_ / n, y_ / n);
}

const bool Vector2f::operator==(const Vector2f &v) const {
	return x_ == v.x_ && y_ == v.y_;
}

std::ostream& operator<<(std::ostream &os, const Vector2f &v) {
	os << "(" << v.x_ << ", " << v.y_ << ")";
	return os;
}