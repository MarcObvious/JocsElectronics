/*  controller.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Falta implementarla sencera, encara que pel que fa
*   game gairebe millor deixar els controls allà...
*/

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "nau.h"

class Controller {
protected:
	Nau* _controlat;
public:
	Controller(Nau* contr);
	~Controller(){};
	//virtual void update(double elapsed_time, const Uint8* keystate);
};



#endif /* CONTROLLER_H_ */
