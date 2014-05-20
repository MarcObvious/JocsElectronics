#include "world.h"
#include <stdlib.h>
#include<ctime>
int Entity::_last_id = 0;  //començem a 0 el cnt d'entitats
MeshManager* MeshManager::_instance = NULL; //Inicialitzem els Singletons
TextureManager* TextureManager::_instance = NULL;
BulletManager* BulletManager::_instance = NULL;

World::World() {
	assert(_instance == NULL);
	_instance = this;

	srand(static_cast<unsigned>(time(0))); //seed per poder fer rands.

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
	for (unsigned int i = 0; i < _totes_entyties.size(); i++)
		free(_totes_entyties.at(i));
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

	int fills = 0;
	my_parser.seek("#NUM_ELEMENTS");
	int n = my_parser.getint();

	for (int i = 0; i < n; i++) {
		std::string mesh_dir;
		std::string text_dir;
		bool mip;
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
		float posx = my_parser.getfloat();
		float posy = my_parser.getfloat();
		float posz = my_parser.getfloat();

		if (i == 0) { //terreny
			_terreny = new EntityMesh();
			_terreny->setParams(mesh_dir, text_dir, mip, Vector3(posx, posy, posz), false);
		} else if (i == 1) { //cel
			_cel = new EntityMesh();
			_cel->setParams(mesh_dir, text_dir, mip, Vector3(_camera->center.x, _camera->center.y, _camera->center.z),
					false);
		} else if (i == 2) {
			for (unsigned int j = 0; j < posx; j++) {
				EntityBoard* nuvol = new EntityBoard();
				float t = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / posy));
				float nx = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (posz - (-1 * posz))));
				float ny = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (posz - (-1 * posz))));
				float nz = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (posz - (-1 * posz))));
				nuvol->setParams(t, text_dir, mip, Vector3(nx, ny, nz), true, _camera->getLocalVector(Vector3(0, 1, 0)),
						_camera->getLocalVector(Vector3(1, 0, 0)));
				_nuvols.push_back(nuvol);
			}
		} else if (i == 3) { //elements mobils començant per jugador principal
			my_parser.seek("##");
			_jugador = new Nau();
			_jugador->setParams(mesh_dir, text_dir, mip, Vector3(posx, posy, posz), my_parser.getfloat(),
					my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(),
					my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(),
					my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(),
					my_parser.getfloat());

			_jugador->tecolisions();
			_totes_entyties.push_back(_jugador);

			my_parser.seek("#FILLS");
			fills = my_parser.getint();
			n += fills;
		} else if (i + 1 < n - fills) {
			EntityMesh* fill = new EntityMesh();
			fill->setParams(mesh_dir, text_dir, mip, Vector3(posx, posy, posz), false);
			//Matrix44 mat = fill->getMatrix(); WTF era això??¿?¿?¿
			//fill->setMatrix(mat);
			fill->setParent(_jugador);
			_jugador->addChild(fill);
		} else {
			my_parser.seek("##");
			Nau* enemy = new Nau();
			enemy->setParams(mesh_dir, text_dir, mip, Vector3(posx, posy, posz), my_parser.getfloat(),
					my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(),
					my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(),
					my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(),
					my_parser.getfloat());
			//_enemics.push_back(_enemy );
			enemy->tecolisions();
			_totes_entyties.push_back(enemy);
		}

	}
	//HA DE SER UN BILLBOARD!!! IGUAL QUE ELS NUVOLS!!!!!!!!!!!!

	//HAURIA DE SER FILL DE CAMERA; DEPEN NOMES DEL PUNT DE VISTA
	EntityMesh* punt_mira = new EntityMesh();
	punt_mira->setParams(2, "assets/textures/crosshair.tga", 1, Vector3(0, 0, 60), true);
	punt_mira->setParent(_jugador);
	_jugador->addChild(punt_mira);

	EntityMesh* foc = new EntityMesh();
	foc->setParams(2, "assets/textures/rainbow.tga", 1, Vector3(0, -1, -20), true);
	foc->setParent(_jugador);
	_jugador->addChild(foc);

	EntityMesh* foc2 = new EntityMesh();
	foc2->setParams(1, "assets/textures/rainbow.tga", 1, Vector3(0, -1, -22), true);
	foc2->setParent(_jugador);
	_jugador->addChild(foc2);

	EntityMesh* foc3 = new EntityMesh();
	foc3->setParams(0.5, "assets/textures/rainbow.tga", 1, Vector3(0, -1, -24), true);
	foc3->setParent(_jugador);
	_jugador->addChild(foc3);

	printPositions();

	return true;
}

void World::printPositions() {
	//Recorrer totes les entitats treient posicions
	_terreny->printPosition();
	_cel->printPosition();
	for (unsigned int i = 0; i < _totes_entyties.size(); ++i)
		_totes_entyties.at(i)->printPosition();

}

void World::update(double elapsed_time) {

	_cel->setPosition(Vector3(_camera->center.x, _camera->center.y - 500, _camera->center.z));
	//Vector3 cel = _cel->getPosition(); //Hauria de ser mes suau, per alguna rao no acaba de funcionar ok.
	//_cel->setPosition(Vector3( (_camera->center.x*0.05 + cel.x*0.95) ,( (_camera->center.y-500 )*0.05 + cel.y*0.95) , (_camera->center.z*0.05 + cel.z*0.95)));

	for (unsigned int i = 0; i < _totes_entyties.size(); ++i) {
		_totes_entyties.at(i)->update(elapsed_time);
		if ( BulletManager::getInstance()->comprova(_totes_entyties.at(i)->tecolisions() ) )
			_totes_entyties.at(i)->tocat(10);
	}

	BulletManager::getInstance()->update(elapsed_time);
	//std::cout << "MERDA" << std::endl;
	_jugador->transform();

	bool test = _jugador->tecolisions()->collision(_terreny->tecolisions(), -1, 0, _terreny->getGlobalMatrix().m);

	//bool test = _jugador->tecolisions()->collision(  _totes_entyties.at(4)->tecolisions(), -1,0,_totes_entyties.at(5)->getGlobalMatrix().m );
	if (test) {
		std::cout << "EEi, Que t'estampes!!!!!" << std::endl;
		_jugador->tocat(10);

	}




	for (unsigned int i = 0; i < _nuvols.size(); ++i)
		_nuvols.at(i)->update(_camera->getLocalVector(Vector3(0, 1, 0)), _camera->getLocalVector(Vector3(1, 0, 0)));
}

void World::render() {
	_camera->set();

	glDisable(GL_DEPTH_TEST); //Z buffer desactivat
	_cel->render();
	glEnable(GL_DEPTH_TEST);  //Altre cop activat

	_terreny->render();

	for (unsigned int i = 0; i < _totes_entyties.size(); ++i)
		_totes_entyties.at(i)->render();

	for (unsigned int i = 0; i < _nuvols.size(); ++i)
		_nuvols.at(i)->render();

	BulletManager::getInstance()->render();
}
