#include "entity.h"

Entity::Entity(){
	_id = _last_id;
	_last_id++;
	_name << _id << " Entity"; 
	_model = Matrix44();
};

void Entity::setParams(Vector3 posinicial) {
	setPosition(posinicial);

}
Vector3 Entity::getPosition(){

	//return Vector3(_model._11 - _model._31,_model._12 - _model._32,_model._13 - _model._33);
	return Vector3(_model.m[12], _model.m[13], _model.m[14]);
}

std::string Entity::getName() {
        return _name.str();
}

void Entity::printPosition(){
        std::cout << _name.str() << " " << _model.m[12] << " " << _model.m[13] << " " << _model.m[14] << std::endl;
}  

void Entity::setPosition(Vector3 pos){//posicio global! ens PETEM el que hi havia i ho trasladem a aquella posicio
	_model.setIdentity();
	_model.traslate(pos.x, pos.y, pos.z);

}
