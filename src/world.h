/*  world.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Classe on es defineixen tots els elements i 
*    parametres del joc falta tenir un vector general.
*   Ja llegeix la configuració d'un fitxer
*/

#ifndef WORLD_H_
#define WORLD_H_

#include "includes.h"
#include <assert.h>
#include <vector>
#include <algorithm>

#include "jugador.h"
#include "enemic.h"

#include "entityboard.h"
#include "nau.h"
#include "movingentity.h"
#include "entitymesh.h"
#include "entity.h"

#include "camera.h"

#include "mts/TextureManager.h"
#include "mts/MeshManager.h"

#include "mts/mesh.h"
#include "bulletManager.h"
#include "bullet.h"

#include "utils/text.h"
#include <string>

class World{

private:

	static World* _instance;

	EntityMesh* _terreny;

	EntityMesh* _cel;

	EntityMesh* _aigua;

	World();

	~World();

	bool llegeixIcarrega(const char *dir);

public:

	Camera* _camera;
	
	std::vector<Nau*> _totes_entyties;

	std::vector<EntityBoard*> _nuvols;

	void printPositions();

	std::vector<Controller*> _enemics;

	Nau* _jugador;

	static World* getInstance();

	void update(double elapsed_time);

	void render();

};



#endif /* WORLD_H_ */
