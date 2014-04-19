/*  world.h  
*   by Javi Agenjo 2013 UPF  javi.agenjo@gmail.com
*	The Mesh contains the info about how to render a mesh 
*	and also how to parse it from a file.
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Ara llegeix meshes i les guarda a .bin
*/

#ifndef MESH_H
#define MESH_H

#include <vector>
#include "../utils/text.h"
#include "../utils/framework.h"

class Mesh
{
public:
	std::vector< Vector3 > vertices; //here we store the vertices
	std::vector< Vector3 > normals;	 //here we store the normals
	std::vector< Vector2 > uvs;	 //here we store the texture coordinates

	std::vector< Vector3 > bounds; //here we store the bounds, it will be usefull later 

	

	int primitive; //used to tell which primitive to use when rendering (quad, points, lines)

	Mesh();
	void clear();
	void render();
	void renderdebug();
	bool meshdefitxer(char *ase, char *bin); //Si el binari del ase no existeix, crea el binari
	bool loadASE(char *dir); //Carrega ase a partir d'un binari

	void createPlane(float size);
};

#endif
