/*  entitymesh.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*  MeshManager que conte el vector de meshs, segueix
*   un patró singleton
*/
 
#ifndef MESHMANAGER_H_
#define MESHMANAGER_H_

#include <string>
#include <map>
#include <cassert>

#include "mesh.h"

class MeshManager {

private:

	static MeshManager* _instance;

	std::map<std::string, Mesh*>* _meshs_loaded; //Vector punters totes les mesh

	std::map<std::string, Mesh*>* _plans_loaded; //Vector punter a tots els plans (per a billboards).

	MeshManager();

	~MeshManager();

public:

	static MeshManager * getInstance(); 		//Retorna el Meshmanager

	Mesh* get(float tamany); //retorna una mesh plana en la direccio normal.

	Mesh* get(float tamany, std::string name, Vector3 pos, Vector3 top, Vector3 right); //retorna una mesh plana en la direcció correcta.

	Mesh* get(std::string mesh_dir);//Retorna una mesh del vector, si no hi es la crea.

};

#endif /* MESHMANAGER_H_ */
