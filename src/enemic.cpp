#include "enemic.h"

Enemic::Enemic() {
			_name<<" i es enemic";
}

void Enemic::setParams(std::string mesh_dir, std::string text_dir,
		bool mipmapping, Vector3 posinicial, float aZY, float aZX, float aXY, float min, float max, float decc, float acc, float vel) {

	MovingEntity::setParams(mesh_dir, text_dir,mipmapping,posinicial ,aZY ,aZX, aXY, min, max, decc, acc, vel);
}

 void Enemic::update(double elapsed_time){

	girXY("DRETA", elapsed_time);
	_model.traslateLocal(0,0,_velocitat*elapsed_time);
}
