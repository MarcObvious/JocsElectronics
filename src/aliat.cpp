#include "aliat.h"

Aliat::Aliat(Nau* contr) : Controller(contr){
	//_name<<" i es aliat";
}

void Aliat::update(double seconds_elapsed) {

	_controlat->girXY("DRETA", seconds_elapsed);
	_controlat->endavant(seconds_elapsed);
}
