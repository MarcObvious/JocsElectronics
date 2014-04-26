#include "enemic.h"

Enemic::Enemic(MovingEntity* contr) : Controller(contr){
	//_name<<" i es enemic";
}

void Enemic::update(double seconds_elapsed) {

	_controlat->girXY("DRETA", seconds_elapsed);
	_controlat->endavant(seconds_elapsed);
}
