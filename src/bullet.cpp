#include "bullet.h"

Bullet::Bullet(Vector3 position, Vector3 last_position, Vector3 velocity ,float ttl, float power, float author_id, std::string type){

	_position = position;
	 _last_position = last_position;
	 _velocity = velocity;
	 _ttl = ttl;
	 _power = power;
	 _author_id = author_id;
	 _type = type;
}


bool Bullet::getTTL() {
	if ( _ttl < 0 ) return false;
	return true;
}

void Bullet::update( float elapsed_time ) {

	Vector3 G = Vector3(0,-1,0);
    _last_position= _position;  ///Per fer colisions raig esfera (bounds)
    _position = _position+_velocity*elapsed_time;
    _velocity = _velocity+G*elapsed_time;
    _velocity = _velocity-_velocity*0.1*elapsed_time;
    _ttl -= elapsed_time;

}

void Bullet::render() {
	glPointSize(10);
	glColor3f(1,0,0);
	glBegin(GL_POINTS);
	glVertex3f(_position.x, _position.y, _position.z);
	//bullets_mesh.primitive(POINTS)
	//bullets_mesh.render(0, true)
	glColor3f(1,1,1);
	glEnd();
}
