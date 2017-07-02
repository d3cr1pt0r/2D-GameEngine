#pragma once
#include "RenderableComponent.h"
#include "Color.h"
#include "Mesh.h"
#include "Material.h"

namespace Engine {

	class SpriteRenderer : public RenderableComponent {
	public:
		SpriteRenderer(const Color &color);
		~SpriteRenderer();
		
		void init() override;
		void deinit() override;
		void render() override;

	public:
		Color color_;

	private:
		Mesh mesh_;
		Material material_;
	};
}