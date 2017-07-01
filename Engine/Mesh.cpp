#include "Mesh.h"
#include "Manager.h"

namespace Engine {

	Mesh::Mesh() : mesh_resource_() {

	}

	Mesh::~Mesh() {
		destroy();
	}

	void Mesh::begin() {
		clear();
		mesh_resource_.init();
	}

	void Mesh::end() {
		buildVertexData();
		mesh_resource_.upload(vertex_data_);
	}

	void Mesh::render() {
		mesh_resource_.bindVAO();

		glDrawArrays(GL_TRIANGLES, 0, vertex_data_.size());
		
		mesh_resource_.unbindVAO();
	}

	void Mesh::clear() {
		vertices_.clear();
		normals_.clear();
		uvs_.clear();
		colors_.clear();
		indices_.clear();
		vertex_data_.clear();
	}

	void Mesh::destroy() {
		clear();
		mesh_resource_.destroy();
	}

	void Mesh::buildVertexData() {
		const unsigned int size = vertices_.size();
		bool size_check = normals_.size() == size && uvs_.size() == size && colors_.size() == size;

		if (!size_check) {
			pLogManager->logError("Mesh", "Vertex data lengths don't match. Make sure vertices, normals, uvs and colors are the same size!");
			pLogManager->logFloat("Mesh:vertices_size", (float) vertices_.size());
			pLogManager->logFloat("Mesh:normals_size", (float) normals_.size());
			pLogManager->logFloat("Mesh:uvs_size", (float) uvs_.size());
			pLogManager->logFloat("Mesh:colors_size", (float) colors_.size());
			return;
		}

		vertex_data_.clear();
		vertex_data_.resize(size);

		for (unsigned int i = 0; i < size; i++) {
			Vertex vertex;

			vertex.position_.x_ = vertices_[i].x;
			vertex.position_.y_ = vertices_[i].y;
			vertex.position_.z_ = vertices_[i].z;

			vertex.normal_.x_ = normals_[i].x;
			vertex.normal_.y_ = normals_[i].y;
			vertex.normal_.z_ = normals_[i].z;

			vertex.uv_.x_ = uvs_[i].x;
			vertex.uv_.y_ = uvs_[i].y;

			vertex.color_.r_ = colors_[i].x;
			vertex.color_.g_ = colors_[i].y;
			vertex.color_.b_ = colors_[i].z;
			vertex.color_.a_ = colors_[i].w;

			vertex_data_.push_back(vertex);
		}
	}
}