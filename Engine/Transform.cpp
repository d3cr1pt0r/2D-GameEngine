#include "Transform.h"

namespace Engine {

	Transform::Transform() :
		position_(),
		scale_(),
		rotation_(0) {}

	Transform::Transform(const Vector2f &position, const Vector2f &scale, const float &rotation) :
		position_(position),
		scale_(scale),
		rotation_(rotation) {}


	Transform::~Transform() {
	}
}