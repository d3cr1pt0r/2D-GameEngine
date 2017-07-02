#pragma once
namespace Engine {

	class Object {

	public:
		Object(const char *name);
		~Object();

		virtual void init();
		virtual void deinit();

		static Object* instantiate();

		const unsigned int& getInstanceID() const;
		const char* getName() const;

	private:
		static unsigned int object_count_;
		unsigned int instance_id_;
		const char *name_;
	};
}

