#pragma once
#include "RenderableComponent.h"
#include "Color.h"
#include "Mesh.h"
#include "Material.h"

namespace Engine {

	class SpriteRenderer : public RenderableComponent {
	public:
		SpriteRenderer();
		~SpriteRenderer();
		
		void onCreate() override;
		void onDestroy() override;
		void onRender() override;

		void setColor(const Color& color);
		void rebuildMesh();

	public:
		Color color_;

	private:
		Mesh mesh_;
		Material material_;
	};
}