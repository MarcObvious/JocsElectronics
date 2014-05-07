#include "bulletManager.h"


BulletManager::BulletManager() {
	assert(_instance == NULL); //Si no es cumpleix PETA
	_instance = this;
	_bullets = new std::map<std::string, Bullet*>();

}

BulletManager::~BulletManager() {
	    _bullets->clear();
	    free(_instance);
}

BulletManager * BulletManager::getInstance() {
	if (_instance == NULL)
		_instance = new BulletManager();
	return _instance;
}

Bullet* BulletManager::get(std::string b_id) {
	std::map<std::string, Bullet*>::iterator it = _bullets->find(b_id);

	if (it != _bullets->end()) {    //La bullet ja existia
		return (it->second);
	} else {						//Creem nova bullet
		Bullet* b = new Bullet();

		_bullets->insert(
				std::pair<std::string, Bullet*>(b_id, b));
		return b;
	}
}
