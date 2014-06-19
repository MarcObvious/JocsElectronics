#include "world.h"
#include <stdlib.h>
#include<ctime>

int Entity::_last_id = 0;  //començem a 0 el cnt d'entitats
MeshManager* MeshManager::_instance = NULL; //Inicialitzem els Singletons
TextureManager* TextureManager::_instance = NULL;
BulletManager* BulletManager::_instance = NULL;
std::vector<Enemic*>_ia_enemics; //NO TINC NI PUTA IDEA DE QUE FALLA

World::World() {
	assert(_instance == NULL);
	_instance = this;

	srand(static_cast<unsigned>(time(0))); //seed per poder fer rands.

	for (int i = 0; i < 50; ++i) {
		Entity* vaux = new Entity();
		vaux->setParams(Vector3(rand() % 10000 - 5000, rand() % 2000 - 800, rand() % 10000 - 5000));
		_waypoints.push_back(vaux);
	}

	_camera = new Camera();
	_camera->setPerspective(70, WINDOW_WIDTH / (float) WINDOW_HEIGHT, 0.1, 10000); //set the projection, we want to be perspective

	if (llegeixIcarrega("mon"))
		std::cout << "Mon carregat... OK" << std::endl;
	else
		std::cout << "Mon ... NO OK" << std::endl;

	_camera->center = _jugador->getCenter();
	_camera->up = _jugador->getTop();
	_camera->eye = _jugador->getMatrix() * Vector3(0, 50, 50);




}

World::~World() {
	free(_camera);
	free(_terreny);
	free(_cel);

	for (unsigned int i = 0; i < _naus_aliades.size(); i++)
		free(_naus_aliades.at(i));

	for (unsigned int i = 0; i < _naus_enemigues.size(); i++)
		free(_naus_enemigues.at(i));

	for (unsigned int i = 0; i < _elements_fixos.size(); i++)
		free(_elements_fixos.at(i));

	for (unsigned int i = 0; i < _nuvols.size(); i++)
		free(_nuvols.at(i));

	free(_instance);
}

World* World::getInstance() {
	if (_instance == NULL)
		_instance = new World();
	return _instance;
}

bool World::llegeixIcarrega(const char *dir) {
	text my_parser;

	if (!my_parser.create(dir))
		return 0;

	//Elements necessaris, els declarema bans dels for
	std::string mesh_dir;
	std::string text_dir;
	bool mip;
	float posx, posy, posz;
	//int num = 0; //numero d'arrays que estem creant.

	Nau* enemy; //arreglar despres.

	my_parser.seek("#NUM_ELEMENTS");
	int num_elements = my_parser.getint();

	my_parser.seek("#NUM_ELEMENTS_FIXOS");
	int num_elements_fixos = my_parser.getint();

	my_parser.seek("#NUM_ALIATS");
	int num_aliats = my_parser.getint();

	my_parser.seek("#NUM_ENEMICS");
	int num_enemics = my_parser.getint();

	int num_fills = 0;

	//Primer for, TOTS ELS ELEMENTS
	for (; num_elements > 0; num_elements--) {

		my_parser.seek("#MESH");
		mesh_dir = my_parser.getword();

		my_parser.seek("#TEXTURA");
		text_dir = my_parser.getword();

		my_parser.seek("#MIPMAP");
		if (my_parser.getfloat() == 1)
			mip = true;
		else
			mip = false;

		std::transform(mesh_dir.begin(), mesh_dir.end(), mesh_dir.begin(), ::tolower);
		std::transform(text_dir.begin(), text_dir.end(), text_dir.begin(), ::tolower);

		my_parser.seek("#POSICIO");
		posx = my_parser.getfloat();
		posy = my_parser.getfloat();
		posz = my_parser.getfloat();

		//Carreguem, ELEMENTS_FIXOS
		if (num_elements_fixos != 0) {
			if (num_elements_fixos == 3) { //terreny
				_terreny = new EntityMesh();
				_terreny->setParams(mesh_dir, text_dir, mip, Vector3(posx, posy, posz), false);

			} else if (num_elements_fixos == 2) { //cel
				_cel = new EntityMesh();
				_cel->setParams(mesh_dir, text_dir, mip,
						Vector3(_camera->center.x, _camera->center.y, _camera->center.z), false);

			} else if (num_elements_fixos == 1) { //Nuvols
				for (unsigned int j = 0; j < posx; j++) {
					EntityBoard* nuvol = new EntityBoard();
					Vector3 posaux;
					posaux.random(posz);
					float t = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / posy));
					nuvol->setParams(t, text_dir, mip, posaux, true, _camera->getLocalVector(Vector3(0, 1, 0)),
							_camera->getLocalVector(Vector3(1, 0, 0)));

					_nuvols.push_back(nuvol);
				}
			}
			--num_elements_fixos;
		} else if (num_aliats != 0) {
			if (num_fills == 0) {
				my_parser.seek("##");
				_jugador = new Nau();  //MILLORAR
				_jugador->setParams(mesh_dir, text_dir, mip, Vector3(posx, posy, posz), my_parser.getfloat(),
						my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(),
						my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(),
						my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(),
						my_parser.getfloat());

				_jugador->tecolisions();
				_naus_aliades.push_back(_jugador);
				_ia_aliats.push_back(new Aliat(_jugador));

				my_parser.seek("#FILLS");
				num_fills = my_parser.getint();
				num_elements += num_fills;
				num_aliats += num_fills;
			} else {
				EntityMesh* fill = new EntityMesh();
				my_parser.seek("#PLA");
				float pla = my_parser.getfloat();
				if (pla != 0)
					fill->setParams(pla, text_dir, mip, Vector3(posx, posy, posz), true, Vector3(1, 0, 0),
							Vector3(0, 1, 0));
				else
					fill->setParams(mesh_dir, text_dir, mip, Vector3(posx, posy, posz), false);
				fill->setParent(_jugador);
				_jugador->addChild(fill);
				--num_fills;
			}
			--num_aliats;
		} else if (num_enemics != 0) {
			if (num_fills == 0) {
				my_parser.seek("##");
				enemy = new Nau();
				enemy->setParams(mesh_dir, text_dir, mip, Vector3(posx, posy, posz), my_parser.getfloat(),
						my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(),
						my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(),
						my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(),
						my_parser.getfloat());
				//_enemics.push_back(_enemy );
				enemy->tecolisions();
				_naus_enemigues.push_back(enemy);
				_ia_enemics.push_back(new Enemic(enemy));
				my_parser.seek("#FILLS");
				num_fills = my_parser.getint();
				num_elements += num_fills;
				num_enemics += num_fills;
			} else {
				EntityMesh* fill = new EntityMesh();
				my_parser.seek("#PLA");
				float pla = my_parser.getfloat();
				if (pla != 0)
					fill->setParams(pla, text_dir, mip, Vector3(posx, posy, posz), true, Vector3(1, 0, 0),
							Vector3(0, 1, 0));
				else
					fill->setParams(mesh_dir, text_dir, mip, Vector3(posx, posy, posz), false);
				fill->setParent(enemy);
				enemy->addChild(fill);
				--num_fills;
			}
			--num_enemics;
		}
	}

	//	//HAURIA DE SER FILL DE CAMERA; DEPEN NOMES DEL PUNT DE VISTA
	//	EntityMesh* punt_mira = new EntityMesh();
	//	punt_mira->setParams(2, "assets/textures/crosshair.tga", 1, Vector3(0, 0, 60), true);
	//	punt_mira->setParent(_jugador);
	//	_jugador->addChild(punt_mira);

	EntityMesh* galaxy = new EntityMesh();
	galaxy->setParams(50, "assets/textures/galaxy.tga", 1, Vector3(0, 0, 65), true, Vector3(1, 0, 0), Vector3(0, 1, 0));
	galaxy->setParent(_jugador);
	_jugador->addChild(galaxy);

	//	_aigua = new EntityMesh();
	//	_aigua->setParams(1000, "assets/textures/terreny/agua.tga", 0, Vector3(0, -1205, 0), false);
	//	Matrix44 aux = _aigua->getMatrix();
	//	aux.rotateLocal(90*DEG2RAD, Vector3(-1,0,0));
	//	_aigua->setMatrix(aux);
	//_aigua->setParams("assets/meshes/terreny/agua", "assets/textures/terreny/agua.tga", true, Vector3(0, -1200, 0), false);

	printPositions();

	return true;
}

void World::afegeixfixmon(float mida, std::string mesh_dir, std::string text_dir, bool mipmapping, Vector3 posinicial,
		bool alpha, bool board) {
	if (!board) {
		EntityMesh* nova_entitat = new EntityMesh();
		if (mida != 0)
			nova_entitat->setParams(mida, text_dir, mipmapping, posinicial, alpha, _camera->up, Vector3(0, 1, 0));
		else
			nova_entitat->setParams(mesh_dir, text_dir, mipmapping, posinicial, alpha);
		_elements_fixos.push_back(nova_entitat);

		Vector3 pos = nova_entitat->getPosition();
		std::cout << pos.x << " x " << pos.y << " y " << pos.z << " z GALAXIA" << std::endl;
	} else {
		//		EntityBoard* nuvol = new EntityBoard();
		//		nuvol->setParams(mida, text_dir, mipmapping, posinicial, true, _camera->up, );
		//		_nuvols.push_back(nuvol);
	}

}

void World::printPositions() {
	//Recorrer totes les entitats treient posicions
	_terreny->printPosition();
	_cel->printPosition();

	for (unsigned int i = 0; i < _naus_enemigues.size(); i++)
		_naus_enemigues.at(i)->printPosition();

	for (unsigned int i = 0; i < _naus_aliades.size(); i++)
		_naus_aliades.at(i)->printPosition();

	for (unsigned int i = 0; i < _elements_fixos.size(); i++)
		_elements_fixos.at(i)->printPosition();

}

void World::update(double elapsed_time) {

	_cel->setPosition(Vector3(_camera->center.x, _camera->center.y - 500, _camera->center.z));
	//_aigua->setPosition(Vector3(_camera->center.x, _camera->center.y-1205, _camera->center.z));
	for (unsigned int i = 0; i < _ia_enemics.size(); i++)
		_ia_enemics.at(i)->update(elapsed_time);
	for (unsigned int i = 0; i < _ia_aliats.size(); i++) {
		if (!_ia_aliats.at(i)->getControlat()->_lider)
			_ia_aliats.at(i)->update(elapsed_time);
	}
	//TRAMPA: NOMES COMPROVARE COLISIONS AMB TERRENY A JUGADOR
	//	for (unsigned int i = 0; i < _naus_aliades.size(); ++i) {
	//		_naus_aliades.at(i)->update(elapsed_time);
	//		_naus_aliades.at(i)->transform();
	//
	//		if ((BulletManager::getInstance())->comprova(_naus_aliades.at(i)->tecolisions()))
	//			_naus_aliades.at(i)->tocat(10);
	//
	//		//_totes_entyties.at(i)->transform();
	//		if (_naus_aliades.at(i)->tecolisions()->collision(_terreny->tecolisions(), -1, 0,
	//				_terreny->getGlobalMatrix().m)) {
	//
	//			std::cout << "EEi, Que t'estampes!!!!!" << std::endl;
	//			_naus_aliades.at(i)->tocat(10);
	//
	//		}
	//	}

	BulletManager::getInstance()->update(elapsed_time);

	for (unsigned int i = 0; i < _nuvols.size(); ++i)
		_nuvols.at(i)->update(_camera->getLocalVector(Vector3(0, 1, 0)), _camera->getLocalVector(Vector3(1, 0, 0)));
}

void World::render() {
	_camera->set();
	glDisable(GL_DEPTH_TEST); //Z buffer desactivat
	_cel->render();
	glEnable(GL_DEPTH_TEST); //Altre cop activat
	//_aigua->render();
	_terreny->render();

	for (unsigned int i = 0; i < _waypoints.size(); i++) {
		glPushMatrix();
		_waypoints.at(i)->getGlobalMatrix().set();
		glutWireSphere(10, 20, 20);
		glPopMatrix();

	}

	for (unsigned int i = 0; i < _naus_enemigues.size(); i++)
		_naus_enemigues.at(i)->render();

	for (unsigned int i = 0; i < _naus_aliades.size(); i++)
		_naus_aliades.at(i)->render();

	for (unsigned int i = 0; i < _elements_fixos.size(); i++)
		_elements_fixos.at(i)->render();

	for (unsigned int i = 0; i < _nuvols.size(); ++i)
		_nuvols.at(i)->render();

	BulletManager::getInstance()->render();
}
