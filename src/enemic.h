/*  movingentity.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Classe hereva de EntityMesh. Basicament defineix
*	les funcions estandar d'una mesh que es mogui
*/

#ifndef ENEMIC_H_
#define ENEMIC_H_

#include "movingentity.h"
#include "utils/framework.h"
#include <string>

class Enemic: public MovingEntity {
protected:
	
public:
	Enemic();

	 ~Enemic(){};

	 virtual void setParams(std::string mesh_dir, std::string text_dir,
				bool mipmapping, Vector3 posinicial, float aZY, float aZX, float aXY, float min, float max, float decc, float acc, float vel);

	 void update(double elapsed_time);

};

#endif /* ENEMIC_H_ */

