#pragma once
#include <glew.h>

struct VertexVector {
	float x_;
	float y_;
	float z_;
};

struct VertexColor {
	float r_;
	float g_;
	float b_;
	float a_;
};

struct VertexUv {
	float x_;
	float y_;
};

struct Vertex {
	VertexVector position_;
	VertexVector normal_;
	VertexUv uv_;
	VertexColor color_;
};