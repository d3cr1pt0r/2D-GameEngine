#include "Color.h"

Color::Color() : Color(255, 255, 255, 255) {
}

Color::Color(const float & r, const float & g, const float & b) : Color(r, g, b, 255) {
}

Color::Color(const float & r, const float & g, const float & b, const float & a) : r_(r), g_(g), b_(b), a_(a) {
}

Color::~Color() {
}
