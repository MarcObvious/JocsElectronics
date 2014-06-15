#include "jugador.h"
Jugador::Jugador(MovingEntity* contr) :
		Controller(contr) {
	_apunta = 0;
	_controlat = contr;
	//_name << " i es jugador";
}

void Jugador::canvia_control() {
	std::cout << "Estic controlant a: " << _apunta << std::endl;
	if (_apunta >= World::getInstance()->_naus_aliades.size())
		_apunta = 0;
	else {
		_controlat = World::getInstance()->_naus_aliades[_apunta];
		++_apunta;
	}
}
void Jugador::update(double seconds_elapsed, const Uint8* keystate) {

	double speed = seconds_elapsed * 100;

	if (keystate[SDL_SCANCODE_LSHIFT])
		speed *= 10; //move faster with left shift

	if (keystate[SDL_SCANCODE_T])
		canvia_control();

	if (keystate[SDL_SCANCODE_UP])
		World::getInstance()->_camera->move(Vector3(0, 1, 0) * speed);

	if (keystate[SDL_SCANCODE_DOWN])
		World::getInstance()->_camera->move(Vector3(0, -1, 0) * speed);

	if (keystate[SDL_SCANCODE_LEFT])
		World::getInstance()->_camera->move(Vector3(1, 0, 0) * speed);

	if (keystate[SDL_SCANCODE_RIGHT])
		World::getInstance()->_camera->move(Vector3(-1, 0, 0) * speed);

	if (keystate[SDL_SCANCODE_D])
		_controlat->girZY("DRETA", seconds_elapsed);

	if (keystate[SDL_SCANCODE_A])
		_controlat->girZY("ESQUERRA", seconds_elapsed);

	if (keystate[SDL_SCANCODE_W])
		_controlat->girZX("AMUNT", seconds_elapsed);

	if (keystate[SDL_SCANCODE_S])
		_controlat->girZX("AVALL", seconds_elapsed);

	if (keystate[SDL_SCANCODE_Q])
		_controlat->girXY("DRETA", seconds_elapsed);

	if (keystate[SDL_SCANCODE_E])
		_controlat->girXY("ESQUERRA", seconds_elapsed);

	if (keystate[SDL_SCANCODE_N])
		_controlat->accelera(seconds_elapsed);

	if (keystate[SDL_SCANCODE_M])
		_controlat->decelera(seconds_elapsed);

	//if (keystate[SDL_SCANCODE_Z]) //Forats negres. Oh shit baby


	if (keystate[SDL_SCANCODE_SPACE])
//		BulletManager::getInstance()->createBullet(_controlat->getCenter() + Vector3(0, 0, -200),
//				_controlat->getCenter() + Vector3(0, 0, -200),
//				World::getInstance()->_camera->getLocalVector(Vector3(0, 0, -10 * _controlat->getVelocitat())), 10, 20,
//				_controlat->getId(), "puta");
		BulletManager::getInstance()->createBullet(World::getInstance()->_camera->eye + World::getInstance()->_camera->getLocalVector(Vector3(0, 0, -120)),
				World::getInstance()->_camera->eye + World::getInstance()->_camera->getLocalVector(Vector3(0, 0, -100)),
						World::getInstance()->_camera->getLocalVector(Vector3(0, 0, -10 * _controlat->getVelocitat())), 10, 20,
						_controlat->getId(), "puta");

	_controlat->endavant(seconds_elapsed);

	World::getInstance()->_camera->center = _controlat->getCenter();
	World::getInstance()->_camera->up = _controlat->getTop();
	World::getInstance()->_camera->eye =
			(World::getInstance()->_camera->eye - World::getInstance()->_camera->center).normalize()
					* _controlat->getDistOpt() + World::getInstance()->_camera->center;
}

