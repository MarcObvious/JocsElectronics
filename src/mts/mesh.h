/*  world.h  
 *   by Javi Agenjo 2013 UPF  javi.agenjo@gmail.com
 *	The Mesh contains the info about how to render a mesh
 *	and also how to parse it from a file.
 *   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
 *	Ara llegeix meshes i les guarda a .bin
 */

#ifndef MESH_H
#define MESH_H

#include <cassert>
#include <vector>
#include "../includes.h"
#include "../utils/text.h"
#include "../utils/framework.h"


class Mesh
{
public:
	std::vector< Vector3 > vertices; //here we store the vertices
	std::vector< Vector3 > normals;	 //here we store the normals
	std::vector< Vector2 > uvs;	 //here we store the texture coordinates
	std::vector< Vector2 > colors;	 //here we store the colors

	std::vector< Vector3 > bounds; //here we store the bounds

	CollisionModel3D* _collision_model; //Here we store the collision model for coldet.




	int primitive; //used to tell which primitive to use when rendering (quad, points, lines)

	Mesh();

	void clear();

	void render();

	void change_primitive(std::string prim);

	void renderdebug();

	std::vector<Vector3> getBounds();

	CollisionModel3D* getcollisionmodel();

	void setcolors(){
		colors.resize(2);
		colors.push_back(Vector2(0,0));
		colors.push_back(Vector2(255,255));
	}


	bool coldetmodel(); //Hem de carregar manualment cada cop que creem una mesh l'arbre de coldet.

	bool meshdefitxer(char *ase, char *bin); //Si el binari del ase no existeix, crea el binari

	bool loadASE(char *dir); //Carrega ase a partir d'un binari

	void renderBounds();

	void createPlane(float size);

	void createPlane(float size, Vector3 pos, Vector3 top, Vector3 right);
};

#endif
