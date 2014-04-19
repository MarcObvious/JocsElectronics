#include "entity.h"

Entity::Entity(Vector3 posinicial){
	_id = _last_id;
	_last_id++;
//	_name = "Entity " + _id;
	_model = Matrix44();
	setPosition(posinicial);
};

Vector3 Entity::getPosition(){

	return Vector3(_model.m[12],_model.m[13],_model.m[14]);
}

void Entity::setPosition(Vector3 pos){
	//_model = Matrix44::setPosition(_model, pos);
	//_model.setTranslation(pos.x,pos.y,pos.z);

	_model.setIdentity();
	_model.traslate(pos.x, pos.y, pos.z);

}
