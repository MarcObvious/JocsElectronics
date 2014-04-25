#include "entity.h"

Entity::Entity(){
	_id = _last_id;
	_last_id++;
	_name << _id << " Entity"; 
	_model = Matrix44();
}

Entity::Entity(Entity* ent){
	Entity();
	setParent(ent);
}

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

void Entity::addChild(Entity* ent){
	_children.push_back(ent);
}

void Entity::removeChid(Entity* ent){
	_children.pop_back();
}

void Entity::setParent(Entity* ent){
	_parent = ent;
}

Matrix44 Entity::getGlobalMatrix(){
	if (_parent)
			return _model * _parent->getGlobalMatrix();
	return _model;
}
