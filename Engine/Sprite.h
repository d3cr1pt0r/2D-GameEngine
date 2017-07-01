#pragma once
#include "Transform.h"
#include "Mesh.h"
#include "Color.h"
#include "Material.h"

namespace Engine {

	class Sprite {

	public:
		Sprite();
		~Sprite();

		void init();
		void render();
		void destroy();

	public:
		Transform transform_;
		Color color_;

	private:
		Mesh mesh_;
		Material material_;
	};
}

