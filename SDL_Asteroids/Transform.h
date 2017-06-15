#pragma once
#include "Vector2f.h"

class Transform {

public:
	Transform();
	Transform(const Vector2f &position_, const Vector2f &scale, const float &rotation);
	~Transform();

public:
	Vector2f position_;
	Vector2f scale_;
	float rotation_;
};

