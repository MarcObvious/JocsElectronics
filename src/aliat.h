/*  Aliat.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Classe hereva de EntityMesh. Basicament defineix
*	les funcions estandar d'una mesh que es mogui
*/

#ifndef ALIAT_H_
#define ALIAT_H_

#include "nau.h"
#include "controller.h"
#include "utils/framework.h"
#include <string>

class Aliat: public Controller {
protected:

public:
	Aliat(Nau* contr);

	 ~Aliat(){};

	 void update(double elapsed_time);

};

#endif /* ALIAT_H_ */

