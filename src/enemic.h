/*  movingentity.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Classe hereva de EntityMesh. Basicament defineix
*	les funcions estandar d'una mesh que es mogui
*/

#ifndef ENEMIC_H_
#define ENEMIC_H_

#include "nau.h"
#include "entity.h"
#include "controller.h"
#include "utils/framework.h"
#include "world.h"
#include <string>

class Enemic: public Controller {
protected:
	Entity* _objectiu;
	std::vector<Nau*> _objectius_aliats;
	unsigned int _proper_objectiu;
public:
	Enemic(Nau* contr, Entity* waypoint);

	 ~Enemic(){};

	 void update(double elapsed_time);
	 void actua(double elapsed_time);
	 bool distancia_objectiu();

};

#endif /* ENEMIC_H_ */

