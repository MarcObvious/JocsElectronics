#include "entitymesh.h"

EntityMesh::EntityMesh(std::string mesh_dir, std::string text_dir,
		bool mipmapping, Vector3 posinicial) :
		Entity(posinicial) {
	_mesh = (MeshManager::getInstance())->get(mesh_dir);
	_texture = (TextureManager::getInstance())->get(text_dir, mipmapping);
}

void EntityMesh::render() {

	glPushMatrix();
	_model.set();
	//_mesh->renderBounds();

	_texture->bind();
	_mesh->render();
	_texture->unbind();

	glPopMatrix();
}

Vector3 EntityMesh::getTop(){
	return _model.topVector();
}

Vector3 EntityMesh::getCenter(){
	return _model * Vector3(0, 1, 1);
}

Matrix44 EntityMesh::getMatrix() {
	return _model;
}
