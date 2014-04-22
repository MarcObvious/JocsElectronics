#include "enemic.h"

Enemic::Enemic(std::string mesh_dir, std::string text_dir, bool mipmapping,
			Vector3 posinicial) :
			MovingEntity(mesh_dir, text_dir, mipmapping, posinicial) {
			_name<<" i es enemic";
}

 void Enemic::update(double elapsed_time){
//	if((_velocitat -= getFriction()) < min__velocitat)
//		_velocitat = min__velocitat;
	girXY("DRETA", elapsed_time);
	_model.traslateLocal(0,0,_velocitat*elapsed_time);
}
