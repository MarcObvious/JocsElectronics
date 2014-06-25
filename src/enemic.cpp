#include "enemic.h"
#include <math.h>

Enemic::Enemic(Nau* contr) : Controller(contr){
	//_name<<" i es enemic";
	_controlat = contr;
	_objectius = World::getInstance()->_waypoints;  //Els objectius podrien no venir de mon i podrien variar.
	_objectius_aliats=World::getInstance()->_naus_aliades;

	_proper_objectiu = 0;

}

void Enemic::update(double seconds_elapsed) {

	//	_controlat->girXY("DRETA", seconds_elapsed);
	_controlat->endavant(seconds_elapsed);
	actua(seconds_elapsed);


}

bool Enemic::distancia_objectiu(Entity* ent){
        
}


void Enemic::actua(double seconds_elapsed) {
	Matrix44 _model_controlat = _controlat->getGlobalMatrix();


	//Matrix44 _model_objectiu = _objectius.at(_proper_objectiu)->getGlobalMatrix();

	//Matrix44 _model_objectiu = World::getInstance()->_jugador->getGlobalMatrix();
	Vector3 pos_controlat = _controlat->getPosition();

	Vector3 pos_objectiu = _objectius.at(_proper_objectiu)->getPosition();

	//Vector3 pos_objectiu = World::getInstance()->_jugador->getPosition();


	Vector3 loc_proper_objectiu = //_objectius.at(_proper_objectiu)->getGlobalMatrix() * Vector3(0,0,1) - _model_controlat * Vector3(0,0,1);
			pos_controlat - pos_objectiu;
	//if((matrix_*Vector3(0,0,1)).distance(nextPoint) > (matrix_*Vector3(0,0,1)).distance( World::getInstance()->mainCharacter->getMatrix()*Vector3(0,0,1)))
	//	nextPoint = World::getInstance()->mainCharacter->getMatrix()*Vector3(0,0,1)-getMatrix()*Vector3(0,0,1);

	loc_proper_objectiu.normalize();


	float angleXY = _model_controlat.frontVector().normalize().dot(loc_proper_objectiu);

	float angleZX= _model_controlat.topVector() .normalize() .dot(loc_proper_objectiu);


	if(angleXY < 0)
		_controlat->girXY("DRETA", seconds_elapsed);
	else if (angleXY > 0)
		_controlat->girXY("ESQUERRA", seconds_elapsed);

	else if(angleZX < 0)
		_controlat->girZX("AVALL", seconds_elapsed);
	else if (angleZX > 0)
		_controlat->girZX("AMUNT", seconds_elapsed);


	if(pos_controlat.distance(pos_objectiu) < 500){ //Si la distancia con el waypoint actual es inferior a 500
		std::cout << "ARRIBAT!!!" << std::endl;
		std::cout << _objectius.at(_proper_objectiu)->getPosition().x << " X "<< _objectius.at(_proper_objectiu)->getPosition().y << " Y "<<  _objectius.at(_proper_objectiu)->getPosition().z << " Z" << std::endl;
		if(_proper_objectiu < _objectius.size()-1)
			_proper_objectiu++;
		else
			_proper_objectiu = 0;
	}
}
