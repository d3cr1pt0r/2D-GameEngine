#pragma once
namespace Engine {

	class Object {

	public:
		Object(const char *name);
		virtual ~Object();

		const unsigned int& getInstanceID() const;
		const char* getName() const;

	protected:
		static unsigned int object_count_;
		unsigned int instance_id_;
		const char *name_;
	};
}

