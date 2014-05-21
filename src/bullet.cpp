#include "bullet.h"

Bullet::Bullet(Vector3 position, Vector3 last_position, Vector3 velocity ,float ttl, float power, float author_id, std::string type){

	set(position,  last_position,  velocity , ttl,  power,  author_id,  type);
}

void Bullet::set(Vector3 position, Vector3 last_position, Vector3 velocity ,float ttl, float power, float author_id, std::string type){
	_position = position;
		_last_position = last_position;
		_velocity = velocity;
		_ttl = ttl;
		_power = power;
		_author_id = author_id;
		_type = type;
	//	if (_mesh == NULL)
		_mesh = (MeshManager::getInstance())->getLine(_position, _position);
		//else _mesh->createLine(_last_position, _position);
}

bool Bullet::viva() {
	if ( _ttl <= 0 ) return false;
	return true;
}

void Bullet::update( float elapsed_time ) {

	Vector3 G = Vector3(0,-70,0);
	_last_position = _position;  ///Per fer colisions raig esfera (bounds)
	_position = _position+_velocity*elapsed_time;
	_velocity = _velocity+G*elapsed_time;
	_velocity = _velocity-_velocity*0.1*elapsed_time;

	_mesh->createLine(_position, _last_position);
	_ttl -= elapsed_time;
	if (_ttl <= 0) free(_mesh);


}

void Bullet::render() {
	_mesh->render();

}
