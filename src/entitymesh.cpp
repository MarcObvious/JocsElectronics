#include "entitymesh.h"

EntityMesh::EntityMesh() {
	_name << "Mesh";
}

void EntityMesh::setParams(std::string mesh_dir, std::string text_dir,
		bool mipmapping, Vector3 posinicial, bool alpha) {

	Entity::setParams(posinicial);
	_mesh = (MeshManager::getInstance())->get(mesh_dir);
	_texture = (TextureManager::getInstance())->get(text_dir, mipmapping);
	_bounds.resize(2);
	_bounds = (MeshManager::getInstance())->get(mesh_dir)->getBounds();
	_alpha = false;
}

void EntityMesh::setParams(float tamany, std::string text_dir,
		bool mipmapping, Vector3 posinicial, bool alpha) {

	Entity::setParams(posinicial);
	_mesh = (MeshManager::getInstance())->get(tamany);
	_texture = (TextureManager::getInstance())->get(text_dir, mipmapping);
	_alpha = alpha;
}

void EntityMesh::render() {
	glPushMatrix();
	_model.set();

	//_mesh->renderBounds();
	if (_alpha ) {


		glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//glDepthMask(true);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE); //FREAKING FIRE
		_texture->bind();
		_mesh->render();
		_texture->unbind();
		//glDepthMask(false);
		glDisable(GL_BLEND);

	}
	else {

		_texture->bind();
		_mesh->render();

		for (unsigned int i = 0; i < _children.size(); i++)
			_children[i]->render();

		_texture->unbind();

	}
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
