#include "world.h"

int Entity::_last_id = 0;
MeshManager* MeshManager::_instance = NULL; //Definirla fora de la classe
TextureManager* TextureManager::_instance = NULL;

World::World() {
	assert(_instance == NULL);
	_instance = this;

	_camera = new Camera();
	_camera->setPerspective(70, WINDOW_WIDTH / (float) WINDOW_HEIGHT, 0.1,	10000); //set the projection, we want to be perspective

	if (llegeixIcarrega("mon"))
		std::cout << "Mon carregat... OK" << std::endl;
	else
		std::cout << "Mon ... NO OK" << std::endl;

	_camera->center = _jugador->getCenter();
	_camera->up = _jugador->getTop();
	_camera->eye = _jugador->getMatrix() * Vector3(0, 50, 50);

}

World::~World() {
	free (_camera);
	free (_terreny);
	free (_cel);
	free (_jugador);
	for (unsigned int i = 0; i < _enemics.size(); i++)
		free (_enemics.at(i));
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
		if (my_parser.getfloat() == 1 )
			mip = true;
		else
			mip = false;

		std::transform(mesh_dir.begin(), mesh_dir.end(), mesh_dir.begin(), ::tolower);
		std::transform(text_dir.begin(), text_dir.end(), text_dir.begin(), ::tolower);

		my_parser.seek("#POSICIO");
		float posx = my_parser.getfloat();
		float posy = my_parser.getfloat();
		float posz = my_parser.getfloat();

		std::cout << mesh_dir << " " << text_dir << " X " << posx  << " Y " << posy << " Z " << posz << std::endl;



		if (i == 0) //terreny
			_terreny = new EntityMesh( mesh_dir, text_dir, mip, Vector3(posx, posy, posz));

		else if (i == 1) //cel
			_cel = new EntityMesh(mesh_dir, text_dir, mip, Vector3(_camera->center.x,_camera->center.y, _camera->center.z));

		else if (i == 2){ //elements mobils començant per jugador principal
			my_parser.seek("##");
			_jugador = new Jugador(mesh_dir, text_dir, mip, Vector3(posx, posy, posz));
			_jugador->setParams(my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat());
		}
		else {
			my_parser.seek("##");
			Enemic* _enemy = new Enemic( mesh_dir, text_dir, mip, Vector3(posx, posy, posz));
			_enemy->setParams(my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat(), my_parser.getfloat());
			_enemics.push_back(_enemy);
		}

	}


	return true;
}
void World::update(double elapsed_time) {
	_jugador->update(elapsed_time);

	Vector3 cel = _cel->getPosition();


	_cel->setPosition(Vector3( (_camera->center.x*0.05 + cel.x*0.95) ,(_camera->center.y*0.05 + cel.y*0.95)-500 , (_camera->center.z*0.05 + cel.z*0.95)));
	for(unsigned int i = 0; i < _enemics.size(); ++i)
		_enemics.at(i)-> update(elapsed_time);

	//No faig un lookAt, pk aixi, fem el set quan interessa, al render.
	_camera->center = _jugador->getCenter();
	_camera->up = _jugador->getTop();
	_camera->eye = (_camera->eye - _camera->center).normalize() * 50 + _camera->center;

}
void World::render() {
	_camera->set();

	glDisable(GL_DEPTH_TEST); //Z buffer desactivat
	_cel->render();
	glEnable(GL_DEPTH_TEST);  //Altre cop activat

	_terreny->render();

	_jugador->render();

	for(unsigned int i = 0; i < _enemics.size(); ++i)
		_enemics.at(i)-> render();


}