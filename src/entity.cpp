#include "entity.h"

Entity::Entity(Vector3 posinicial){
	_id = _last_id;
	_last_id++;
	_name << _id << " Entity"; 
	_model = Matrix44();
	setPosition(posinicial);
};

Vector3 Entity::getPosition(){
        //11-31
        //12-32
        //13-33
	return Vector3(_model.m[12],_model.m[13],_model.m[14]);
}

std::string Entity::getName() {
        return _name.str();
}

void Entity::printPosition(){
        std::cout << _name.str() << " " << _model.m[12] << " " << _model.m[13] << " " << _model.m[14] << std::endl;
}  

void Entity::setPosition(Vector3 pos){
	//_model = Matrix44::setPosition(_model, pos);
	//_model.setTranslation(pos.x,pos.y,pos.z);

	_model.setIdentity();
	_model.setTranslation(pos.x, pos.y, pos.z);

}
