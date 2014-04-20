/*  entitymesh.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*  MeshManager que conte el vector de meshs, segueix
*   un patró singleton
*/
 
 

#ifndef MESHMANAGER_H_
#define MESHMANAGER_H_

#include <map>
#include "mesh.h"
#include <string>
//#include "../manager.h"
#include "../includes.h"

class MeshManager{

private:

	static MeshManager* _instance;

	std::map<std::string, Mesh*>* _meshs_loaded; //Vector punters totes les mesh

	MeshManager();

	~MeshManager();

public:

	static MeshManager * getInstance(); 		//Retorna el Meshmanager

	Mesh* get(std::string mesh_dir);//Retorna una mesh del vector, si no hi es la crea.

};

#endif /* MESHMANAGER_H_ */