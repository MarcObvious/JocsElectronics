#include "entityboard.h"

EntityBoard::EntityBoard() {

		 _name << "board";

	}
void EntityBoard::setParams(float tamany, std::string text_dir,
		bool mipmapping, Vector3 posinicial, bool alpha){

	EntityMesh::setParams(tamany, text_dir, mipmapping, posinicial, alpha);


}

