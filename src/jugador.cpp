#include "jugador.h"

Jugador::Jugador() {
	_name << " i es jugador";
}
void Jugador::setParams(std::string mesh_dir, std::string text_dir,
		bool mipmapping, Vector3 posinicial, float aZY, float aZX, float aXY, float min, float max, float decc, float acc, float vel) {

	MovingEntity::setParams(mesh_dir, text_dir,mipmapping,posinicial ,aZY ,aZX, aXY, min, max, decc, acc, vel);
}

void Jugador::update(double elapsed_time) {
//	if((_velocitat -= getFriction()) < min__velocitat)
//		_velocitat = min__velocitat;

	_model.traslateLocal(0, 0, _velocitat * elapsed_time);
}

