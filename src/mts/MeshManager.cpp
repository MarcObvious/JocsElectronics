#include "MeshManager.h"

MeshManager::MeshManager() {
	assert(_instance == NULL); //Si no es cumpleix PETA
	_instance = this;
	_meshs_loaded = new std::map<std::string, Mesh*>();

}

MeshManager::~MeshManager() {
	_meshs_loaded->clear();
	free(_instance);
}

MeshManager * MeshManager::getInstance() {
	if (_instance == NULL)
		_instance = new MeshManager();
	return _instance;
}

//FOTUDAMENT MALAMENT. MILLORAR ELS PLANS!!!!!!!!!!!!!!!!!!
Mesh* MeshManager::get(float tamany, Vector3 pos, Vector3 top, Vector3 right) {
	Mesh* mesh_nova = new Mesh();
	mesh_nova->createPlane(tamany,  pos,  top,  right);
	_meshs_loaded->insert(
			std::pair<std::string, Mesh*>("pla", mesh_nova));
	return mesh_nova;
}

Mesh* MeshManager::get(std::string mesh_dir) {
	std::map<std::string, Mesh*>::iterator it = _meshs_loaded->find(mesh_dir);

	if (it != _meshs_loaded->end()) {    //La mesh ja existia
		return (it->second);
	} else {						//La mesh no existia, la carreguem
		Mesh* mesh_nova = new Mesh();

		if (!mesh_nova->loadASE((char*) mesh_dir.c_str())) {
			std::cout << "ERROR AL LLEGIR MESH: " << mesh_dir.c_str()
									<< std::endl;
			exit(0);
		}

		_meshs_loaded->insert(
				std::pair<std::string, Mesh*>(mesh_dir, mesh_nova));
		return mesh_nova;
	}
}
