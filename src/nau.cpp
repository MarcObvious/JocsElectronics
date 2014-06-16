#include "nau.h"
#include "mts/MeshManager.h"
Nau::Nau() {
	_dany = 0;
	_cadencia = 0;
	_num_bales = 0;
	_vida = 0;
	_resistencia = 0;
	_name << "_nau_espacial";

}
void Nau::setParams(std::string mesh_dir, std::string text_dir, bool mipmapping, Vector3 posinicial, float resistencia,
		float vida, float num_bales, float cadencia, float dany, float opt, float aZY, float aZX, float aXY, float min,
		float max, float decc, float acc, float vel) {

	MovingEntity::setParams(mesh_dir, text_dir, mipmapping, posinicial, opt, aZY, aZX, aXY, min, max, decc, acc, vel);

	_dany = dany;
	_cadencia = cadencia;
	_vida = vida;
	_resistencia = resistencia;
}

void Nau::tocat(int dany) {
	_dany -= dany;
	glColor3f(1.0, 0.0, 0.0);

}
