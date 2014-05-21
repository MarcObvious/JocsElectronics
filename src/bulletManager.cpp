#include "bulletManager.h"


BulletManager::BulletManager() {
	assert(_instance == NULL); //Si no es cumpleix PETA
	_instance = this;
	_bullets = new std::vector<Bullet*>();
	_bullets->reserve(1000);
	_pos = 0;
	_init = true;

}

BulletManager::~BulletManager() {
	// _bullets->clear();
	free(_instance);
	for(unsigned int i = 0; i < _bullets->size(); i++)
		free ( _bullets->at(i));
}

BulletManager * BulletManager::getInstance() {
	if (_instance == NULL)
		_instance = new BulletManager();
	return _instance;
}

void BulletManager::render() {

	for(unsigned int i = 0; i < _bullets->size(); i++)
		if ( _bullets->at(i)->viva() ) //Dibuixa nomes les que el temps de vida sigui positiu
			_bullets->at(i)->render();

}

void BulletManager::update( float elapsed_time ){

	for(unsigned int i = 0; i < _bullets->size(); i++) {
		if ( _bullets->at(i)->viva() )
			_bullets->at(i)->update( elapsed_time );

	}
}



void BulletManager::createBullet(Vector3 position, Vector3 last_position, Vector3 velocity ,float ttl, float power, float author_id, std::string type) {
	if (!_init) { //Si el vector ja ha arribat a 1000, sobreescrivim bullets
		_bullets->at(_pos)->set(position,  last_position,  velocity , ttl,  power,  author_id,  type);
		++_pos;
	}
	//Creem nova bullet fins a 1000
	if (_pos < 1000 && _init) {
		Bullet* b = new Bullet( position,  last_position,  velocity , ttl,  power,  author_id,  type);
		_bullets->push_back(b);
		++_pos;
	}
	//Si arribem a 1000 tornem a començar el compte
	if (_pos == 1000) {
		_pos = 0;
		_init = false;
	}
	std::cout << _pos<< std::endl;

}

bool BulletManager::comprova(CollisionModel3D* collision_model) {
	for (unsigned int i = 0; i < _bullets->size(); i++) {
		if ( _bullets->at(i)->viva() )
			if (collision_model->rayCollision( _bullets->at(i)->_last_position.v, (_bullets->at(i)->_position - _bullets->at(i)->_last_position ) .v, false) == true)
				return true;
	}
	return false;
}
