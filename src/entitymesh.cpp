#include "entitymesh.h"

EntityMesh::EntityMesh() {
	_name << "Mesh";
}

void EntityMesh::setParams(std::string mesh_dir, std::string text_dir,
		bool mipmapping, Vector3 posinicial) {

		Entity::setParams(posinicial);
		_mesh = (MeshManager::getInstance())->get(mesh_dir);
		_texture = (TextureManager::getInstance())->get(text_dir, mipmapping);
		_bounds.resize(2);
		_bounds = (MeshManager::getInstance())->get(mesh_dir)->getBounds();
}


void EntityMesh::render() {

	glPushMatrix();
	_model.set();

	//_mesh->renderBounds();

	_texture->bind();
	_mesh->render();

	for (unsigned int i = 0; i < _children.size(); i++)
		_children[i]->render();

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
