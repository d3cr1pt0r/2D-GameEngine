#pragma once
#include <glew.h>

struct Position {
	float x_;
	float y_;
};

struct Color {
	float r_;
	float g_;
	float b_;
	float a_;
};

struct Vertex {
	Position position_;
	Color color_;
};