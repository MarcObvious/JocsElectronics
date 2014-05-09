#include "bulletManager.h"


BulletManager::BulletManager() {
	assert(_instance == NULL); //Si no es cumpleix PETA
	_instance = this;
	_bullets = new std::vector<Bullet*>();
	_bullets->reserve(500);

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
		_bullets->at(i)->update( elapsed_time );

	}
}

void BulletManager::createBullet(Vector3 position, Vector3 last_position, Vector3 velocity ,float ttl, float power, float author_id, std::string type) {
	//Creem nova bullet
	Bullet* b = new Bullet( position,  last_position,  velocity , ttl,  power,  author_id,  type);
	_bullets->push_back(b);

}
