#include "controller.h"

Controller::Controller(Nau* contr) {
	_controlat = contr;
}

Nau* Controller::getControlat() {
	return _controlat;
}
