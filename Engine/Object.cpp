#include "Object.h"
#include "Manager.h"

namespace Engine {

	unsigned int Object::object_count_ = 0;

	Object::Object(const char *name) : name_(name) {
		instance_id_ = object_count_;
		object_count_++;
	}

	Object::~Object() {
		object_count_--;
	}

	void Object::init() {
		pObjectManager->addObject(this);
	}

	void Object::destroy() {
		pObjectManager->removeObject(this);
	}

	Object* Object::instantiate()
	{
		Object *object = new Object("Object");
		object->init();

		return object;
	}

	const unsigned int& Object::getInstanceID() const {
		return instance_id_;
	}

	const char* Object::getName() const {
		return name_;
	}
}

