#pragma once
class Color {
	
public:
	Color();
	Color(const float &r, const float &g, const float &b);
	Color(const float &r, const float &g, const float &b, const float &a);
	~Color();

public:
	float r_;
	float g_;
	float b_;
	float a_;
};

