/*  jugador.h
 *   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
 *	Classe hereva de EntityMesh. Basicament defineix
 *	les funcions estandar d'una mesh que es mogui
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "controller.h"
#include "utils/framework.h"
#include "movingentity.h"
#include "world.h"
#include "bulletManager.h"

#include <string>

class Jugador : public Controller {
protected:
	unsigned int _apunta;
public:
	Jugador(MovingEntity* contr);

	~Jugador(){};

	void canvia_control();

	void update(double elapsed_time, const Uint8* keystate);

};

#endif /* JUGADOR_H_ */
