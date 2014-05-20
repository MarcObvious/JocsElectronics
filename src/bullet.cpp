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
		_mesh = (MeshManager::getInstance())->getLine(_position, _position);
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
	_ttl -= elapsed_time;
	_mesh = (MeshManager::getInstance())->getLine(_last_position, _position);

}

void Bullet::render() {

	_mesh->render();
//	Matrix44 maux = matrix_;
//		aux = maux*Vector3(0,0,1);
//		maux.traslateLocal(0,0,5);
//		auxb= maux*Vector3(0,0,1);
//		glBegin(GL_LINE_STRIP);
//			glColor3f(255,255,255);
//			glVertex3f (_position.x,  _position.y,  _position.z);
//			_position.
//			glColor3f(190,190,0);
//			glVertex3f (auxb.x, auxb.y, auxb.z);
//		glEnd();

//	glLineWidth(6.5);
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_LINES);
//	glVertex3f(_position.x, _position.y, _position.z);
//	glVertex3f(_position.x, _position.y,_last_position.z + 40);
//	glColor3f(1,1,1);
//	glEnd();

//	glPointSize(5);
//	glColor3f(1,0,0);
//
//	glBegin(GL_POINTS);
//	glVertex3f(_position.x, _position.y, _position.z);
//	glColor3f(1,1,1);
//	glEnd();
}
