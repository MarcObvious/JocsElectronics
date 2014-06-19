#include "enemic.h"

Enemic::Enemic(Nau* contr) : Controller(contr){
	//_name<<" i es enemic";
	_controlat = contr;
	_objectius = World::getInstance()->_waypoints;  //Els objectius podrien no venir de mon i podrien variar.
	_proper_objectiu = 0;
}

void Enemic::update(double seconds_elapsed) {

//	_controlat->girXY("DRETA", seconds_elapsed);

	segueix(seconds_elapsed);
	_controlat->endavant(seconds_elapsed);
}

void Enemic::segueix(double seconds_elapsed) {
	Matrix44 _model_controlat = _controlat->getGlobalMatrix();
	Vector3 loc_proper_objectiu = _objectius.at(_proper_objectiu)->getGlobalMatrix() * Vector3(0,0,1) - _model_controlat*Vector3(0,0,1);

	//if((matrix_*Vector3(0,0,1)).distance(nextPoint) > (matrix_*Vector3(0,0,1)).distance( World::getInstance()->mainCharacter->getMatrix()*Vector3(0,0,1)))
	//	nextPoint = World::getInstance()->mainCharacter->getMatrix()*Vector3(0,0,1)-getMatrix()*Vector3(0,0,1);

	loc_proper_objectiu.normalize();

	float anguloa = 1 - _model_controlat.frontVector().dot(loc_proper_objectiu);
	float angulob = 1 - _model_controlat.rightVector()  .dot(loc_proper_objectiu);
	float dir = _model_controlat.rightVector().dot(loc_proper_objectiu);
	float dir2= _model_controlat.topVector()  .dot(loc_proper_objectiu);

	float h_roll = anguloa*2;
	float v_roll = angulob*2;

	if(dir < 0)
		_controlat->girXY("DRETA", seconds_elapsed);
	if(dir > 0)
		_controlat->girXY("ESQUERRA", seconds_elapsed);

	if(dir2 > 0)
		_controlat->girZX("AVALL", seconds_elapsed);
	if(dir2 < 0)
		_controlat->girZX("AMUNT", seconds_elapsed);

	float rangulo = 1 - _model_controlat.rightVector().dot(Vector3(1,0,0));
	float dir3    = _model_controlat.topVector().dot(Vector3(1,0,0));

	if(rangulo > 1)
		_controlat->girZY("ESQUERRA", seconds_elapsed);
	if(rangulo > 0.2)
		_controlat->girZY("ESQUERRA", seconds_elapsed);

	if((_model_controlat*Vector3(0,0,1)).distance(_objectius.at(_proper_objectiu)->getGlobalMatrix() * Vector3(0,0,1)) < 500){ //Si la distancia con el waypoint actual es inferior a 500
		if(_proper_objectiu < _objectius.size())
			_proper_objectiu++;
		else
			_proper_objectiu = 0;
	}
}
