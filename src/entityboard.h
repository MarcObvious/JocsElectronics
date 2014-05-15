/*  entityboard.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Classe hereva de EntityMesh. Basicament defineix
*	les funcions que ha de tenir una classe billboard
*/

#ifndef ENTITYBOARD_H_
#define ENTITYBOARD_H_

#include "entitymesh.h"
#include "utils/framework.h"
#include <string>

class EntityBoard: public EntityMesh {
protected:


public:
	EntityBoard();

	virtual void setParams(std::string mesh_dir, std::string text_dir,
			bool mipmapping, Vector3 posinicial, float opt, float aZY, float aZX, float aXY, float min, float max, float decc, float acc, float vel);

	 virtual ~EntityBoard(){};



	 virtual void update(double elapsed_time){};

};

#endif /* ENTITYBOARD_H_ */
