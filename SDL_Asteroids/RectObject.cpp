#include "RectObject.h"
#include "Display.h"

RectObject::RectObject() : transform_() {
}

RectObject::RectObject(const Vector2f &position, const Vector2f &scale, const Color &color) : transform_(position, scale, 0), color_(color) {
}

RectObject::~RectObject() {
}

void RectObject::update(const float & delta_time) {

}

void RectObject::render() {
	rect_.x = transform_.position_.x_;
	rect_.y = transform_.position_.y_;
	rect_.w = transform_.scale_.x_;
	rect_.h = transform_.scale_.y_;

	SDL_SetRenderDrawColor(Display::renderer_, color_.r_, color_.g_, color_.b_, color_.a_);
	SDL_RenderFillRect(Display::renderer_, &rect_);
}
