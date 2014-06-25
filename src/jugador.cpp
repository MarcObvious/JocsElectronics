#include "jugador.h"
Jugador::Jugador(Nau* contr) :
Controller(contr) {
	_apunta = 0;
	_controlat = contr;
	_controlat->_lider = true;
	_aliats = World::getInstance()->_naus_aliades;
	_espera = 2;
	//_name << " i es jugador";
}

void Jugador::canvia_control() {
	std::cout << "Estic controlant a: " << _apunta << std::endl;
	if (_apunta >= World::getInstance()->_naus_aliades.size())
		_apunta = 0;
	_controlat->_lider = false;
	_controlat = World::getInstance()->_naus_aliades[_apunta];
	_controlat->_lider = true;
	++_apunta;


}
void Jugador::update(double seconds_elapsed, const Uint8* keystate) {

	double speed = seconds_elapsed * 100;

	if (keystate[SDL_SCANCODE_LSHIFT])
		speed *= 10; //move faster with left shift

	if (keystate[SDL_SCANCODE_T]){
		if (_espera == 2) {
			canvia_control();
			_espera = 0;
		}
		else
			++_espera;
	}


	if (keystate[SDL_SCANCODE_UP])
		World::getInstance()->_camera->move(Vector3(0, 1, 0) * speed);

	if (keystate[SDL_SCANCODE_DOWN])
		World::getInstance()->_camera->move(Vector3(0, -1, 0) * speed);

	if (keystate[SDL_SCANCODE_LEFT])
		World::getInstance()->_camera->move(Vector3(1, 0, 0) * speed);

	if (keystate[SDL_SCANCODE_RIGHT])
		World::getInstance()->_camera->move(Vector3(-1, 0, 0) * speed);

	if (keystate[SDL_SCANCODE_D])
		for(int i = 0; i< _aliats.size(); i++ )
		_aliats.at(i)->girZY("DRETA", seconds_elapsed);

	if (keystate[SDL_SCANCODE_A])
		for(int i = 0; i< _aliats.size(); i++ )
				_aliats.at(i)->girZY("ESQUERRA", seconds_elapsed);

	if (keystate[SDL_SCANCODE_W])
		for(int i = 0; i< _aliats.size(); i++ )
				_aliats.at(i)->girZX("AMUNT", seconds_elapsed);

	if (keystate[SDL_SCANCODE_S])
		for(int i = 0; i< _aliats.size(); i++ )
				_aliats.at(i)->girZX("AVALL", seconds_elapsed);

	if (keystate[SDL_SCANCODE_Q])
		for(int i = 0; i< _aliats.size(); i++ )
				_aliats.at(i)->girXY("DRETA", seconds_elapsed);

	if (keystate[SDL_SCANCODE_E])
		for(int i = 0; i< _aliats.size(); i++ )
				_aliats.at(i)->girXY("ESQUERRA", seconds_elapsed);

	if (keystate[SDL_SCANCODE_N])
		for(int i = 0; i< _aliats.size(); i++ )
				_aliats.at(i)->accelera(seconds_elapsed);

	if (keystate[SDL_SCANCODE_M])
		for(int i = 0; i< _aliats.size(); i++ )
				_aliats.at(i)->decelera(seconds_elapsed);

	if (keystate[SDL_SCANCODE_Z]) { //Forats negres. Oh shit baby
		if (_espera == 2) {
		Vector3 pos = _controlat->getPosition();
		std::cout << pos.x << " x " << pos.y << " y "<< pos.z << " z NAU"<< std::endl;
		World::getInstance()->afegeixfixmon (50, "res","assets/textures/galaxy.tga", 1, pos, true, false);
		_espera = 0;
		}
		else
			++_espera;

	}
	if (keystate[SDL_SCANCODE_X]) {
		if (_espera == 2) {
			_controlat->dispara_missil(seconds_elapsed);
			_espera = 0;
		}
		else
			++_espera;
	}


	if (keystate[SDL_SCANCODE_SPACE])
		//		BulletManager::getInstance()->createBullet(_controlat->getCenter() + Vector3(0, 0, -200),
		//				_controlat->getCenter() + Vector3(0, 0, -200),
		//				World::getInstance()->_camera->getLocalVector(Vector3(0, 0, -10 * _controlat->getVelocitat())), 10, 20,
		//				_controlat->getId(), "puta");
		BulletManager::getInstance()->createBullet(World::getInstance()->_camera->eye + World::getInstance()->_camera->getLocalVector(Vector3(0, 0, -120)),
				World::getInstance()->_camera->eye + World::getInstance()->_camera->getLocalVector(Vector3(0, 0, -100)),
				World::getInstance()->_camera->getLocalVector(Vector3(0, 0, -10 * _controlat->getVelocitat())), 10, 20,
				_controlat->getId(), "puta");

	for(int i = 0; i< _aliats.size(); i++ )
			_aliats.at(i)->endavant(seconds_elapsed);

	World::getInstance()->_camera->center = _controlat->getCenter();
	World::getInstance()->_camera->up = _controlat->getTop();
	World::getInstance()->_camera->eye =
			(World::getInstance()->_camera->eye - World::getInstance()->_camera->center).normalize()
			* _controlat->getDistOpt() + World::getInstance()->_camera->center;
	//wait();
}

