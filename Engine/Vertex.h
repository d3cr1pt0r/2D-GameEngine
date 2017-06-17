#pragma once
#include <glew.h>

struct Vertex {
	struct Position {
		float x_;
		float y_;
	} position_;

	struct Color {
		float r_;
		float g_;
		float b_;
		float a_;
	} color_;
};