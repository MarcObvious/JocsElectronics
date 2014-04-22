#include "jugador.h"

Jugador::Jugador(std::string mesh_dir, std::string text_dir, bool mipmapping,
			Vector3 posinicial) :
			MovingEntity(mesh_dir, text_dir, mipmapping, posinicial) {
			_name << " i es jugador";
}

void Jugador::update(double elapsed_time){
//	if((_velocitat -= getFriction()) < min__velocitat)
//		_velocitat = min__velocitat;

	_model.traslateLocal(0,0,_velocitat*elapsed_time);
}

