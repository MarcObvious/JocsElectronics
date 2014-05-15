#include "entityboard.h"

EntityBoard::EntityBoard() {

		 _name << "board";

	}
void EntityBoard::setParams(std::string mesh_dir, std::string text_dir,
		bool mipmapping, Vector3 posinicial, float opt, float aZY, float aZX, float aXY, float min, float max, float decc, float acc, float vel){

	EntityMesh::setParams(mesh_dir, text_dir, mipmapping, posinicial);


}

