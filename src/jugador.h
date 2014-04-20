/*  jugador.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Classe hereva de EntityMesh. Basicament defineix
*	les funcions estandar d'una mesh que es mogui
*/

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "movingentity.h"
#include "utils/framework.h"
#include <string>

class Jugador: public MovingEntity {
protected:
	
public:
	Jugador(std::string mesh_dir, std::string text_dir, bool mipmapping,
			Vector3 posinicial);

	 ~Jugador(){};

	 void update(double elapsed_time);

};

#endif /* JUGADOR_H_ */
