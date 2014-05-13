/*  bullet.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Bala!!!
*/

#ifndef BULLET_H_
#define BULLET_H_

#include <string>
#include "utils/framework.h"

class Bullet
{

private:

	Vector3 _position;
	Vector3 _last_position;
	Vector3 _velocity;
	float _ttl;
	float _power;
	float _author_id;
	std::string _type;

public:
	
	Bullet(Vector3 position, Vector3 last_position, Vector3 velocity ,float ttl, float power, float author_id, std::string type);

	bool viva(); //Si es false, la bullet no es dibuixara

	void update( float elapsed_time );

	void render ();
};

#endif  /* BULLET_H_ */
