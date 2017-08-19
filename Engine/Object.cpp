#include "Object.h"
#include "Managers\ManagerSystem.h"

namespace Engine {

	unsigned int Object::object_count_ = 0;

	Object::Object(const char *name) : name_(name) {
		instance_id_ = object_count_;
		object_count_++;

		init();
	}

	Object::~Object() {
		object_count_--;

		deinit();
	}

	void Object::init() {

	}

	void Object::deinit() {

	}

	const unsigned int& Object::getInstanceID() const {
		return instance_id_;
	}

	const char* Object::getName() const {
		return name_;
	}
}

