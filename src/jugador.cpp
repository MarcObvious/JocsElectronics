#include "jugador.h"

Jugador::Jugador(MovingEntity* contr) : Controller(contr){
	//_name << " i es jugador";
}

void Jugador::update(double seconds_elapsed, const Uint8* keystate) {

	double speed = seconds_elapsed * 100;

	if (keystate[SDL_SCANCODE_LSHIFT])
		speed *= 10; //move faster with left shift

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

	_controlat->endavant(seconds_elapsed);
}

