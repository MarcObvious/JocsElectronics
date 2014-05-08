#include "bulletManager.h"


BulletManager::BulletManager() {
	assert(_instance == NULL); //Si no es cumpleix PETA
	_instance = this;
	_bullets = new std::vector<Bullet*>();

}

BulletManager::~BulletManager() {
	   // _bullets->clear();
	    free(_instance);
}

BulletManager * BulletManager::getInstance() {
	if (_instance == NULL)
		_instance = new BulletManager();
	return _instance;
}

void BulletManager::render() {

	for(unsigned int i = 0; i < _bullets->size(); i++)
			_bullets->at(i)->render();
}

void BulletManager::update( float elapsed_time ){

	for(unsigned int i = 0; i < _bullets->size(); i++)
		_bullets->at(i)->update( elapsed_time );

}

void BulletManager::createBullet(Vector3 position, Vector3 last_position, Vector3 velocity ,float ttl, float power, float author_id, std::string type) {
//	std::map<std::string, Bullet*>::iterator it = _bullets->find(b_id);
//
//	if (it != _bullets->end()) {    //La bullet ja existia
//		return (it->second);
//	} else {						//Creem nova bullet
		Bullet* b = new Bullet( position,  last_position,  velocity , ttl,  power,  author_id,  type);
		_bullets->push_back(b);
//
//		_bullets->insert(
//				std::pair<std::string, Bullet*>(b_id, b));

//	}
}
