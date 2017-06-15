#pragma once
#include <SDL.h>
#include "Transform.h"
#include "Color.h"

class RectObject {

public:
	RectObject();
	RectObject(const Vector2f &position, const Vector2f &scale, const Color &color);
	~RectObject();

	void update(const float &delta_time);
	void render();

public:
	SDL_Rect rect_;
	Transform transform_;
	Color color_;
};

