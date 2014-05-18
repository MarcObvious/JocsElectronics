#include "entityboard.h"

EntityBoard::EntityBoard() {

		 _name << "board";
		 _tamany = 0;

	}
void EntityBoard::setParamss(float tamany, std::string text_dir,
		bool mipmapping, Vector3 posinicial, bool alpha, Vector3 top, Vector3 right){
	_tamany = tamany;
	EntityMesh::setParams("NULL", text_dir, mipmapping, posinicial, alpha);
	_mesh = (MeshManager::getInstance())->get(tamany,posinicial,top,right);


}

void EntityBoard::update(Vector3 top, Vector3 right) {
	_mesh = (MeshManager::getInstance())->get(_tamany,getPosition(),top,right);
}

