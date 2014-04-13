/*
 * MeshManager.h
 *  Meshmanager Estatic seguint patro Singleton
 *  Created on: 13/04/2014
 *      Author: marc
 */

#ifndef MESHMANAGER_H_
#define MESHMANAGER_H_

#include <map>
#include "mesh.h"
#include <string>
#include "includes.h"

class MeshManager {
private:
	std::map<std::string, Mesh*>* _meshs_loaded; //Vector punters totes les mesh

	MeshManager(); 								//Constructor
	MeshManager(MeshManager const&);
	void operator=(MeshManager const&);	//Forçar singleton s'exectuti nomes un cop

public:

	static MeshManager & getInstance(); 		//Retorna el Meshmanager

	Mesh* get(std::string mesh_dir);//Retorna una mesh del vector, si no hi es la crea.

};

#endif /* MESHMANAGER_H_ */
