/*  movingentity.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Classe hereva de EntityMesh. Basicament defineix
*	les funcions estandar d'una mesh que es mogui
*/

#ifndef ENEMIC_H_
#define ENEMIC_H_

#include "nau.h"
#include "controller.h"
#include "utils/framework.h"
#include "world.h"
#include <string>

class Enemic: public Controller {
protected:
	std::vector<Entity*> _objectius;
	unsigned int _proper_objectiu;
public:
	Enemic(Nau* contr);

	 ~Enemic(){};

	 void update(double elapsed_time);
	 void segueix(double elapsed_time);

};

#endif /* ENEMIC_H_ */

