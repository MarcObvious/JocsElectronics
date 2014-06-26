#include "nau.h"
#include "mts/MeshManager.h"
#include "world.h"
Nau::Nau() {
	_dany = 0;
	_cadencia = 0;
	_num_bales = 0;
	_vida = 0;
	_resistencia = 0;
	_lider = false;
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
	_num_bales = num_bales;
}

void Nau::tocat(int dany) {
	if (dany == -1) {
		_vida = 0;
	}
	_vida -= dany;
	glColor3f(1.0, 0.0, 0.0);

}

float Nau::getVida() {
	return _vida;

}

void Nau::dispara_missil(float econds_elapsed) {
	if (_num_bales != -1) {
		Entity* misil = this->removeChid();
		World::getInstance()->_naus_aliades.push_back((Nau*) misil);
		if (_num_bales-1 != 0)
			--_num_bales;
		else
			_num_bales = -1;
	}
}

