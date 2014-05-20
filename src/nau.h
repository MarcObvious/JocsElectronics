/*  nau.h
 *   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
 *	Classe hereva de Moving entity. Basicament defineix
 *	les funcions propies d'una estandar d'una nau espacial
 */

#ifndef NAU_H_
#define NAU_H_

#include "movingentity.h"
#include "utils/framework.h"
#include <string>

class Nau: public MovingEntity {
protected:
	float _dany;
	float _cadencia;
	float _num_bales;
	float _vida;
	float _resistencia;

public:
	Nau();
	virtual ~Nau() {};

	void setParams(std::string mesh_dir, std::string text_dir, bool mipmapping, Vector3 posinicial, float resistencia,
			float vida, float num_bales, float cadencia, float dany, float opt, float aZY, float aZX, float aXY,
			float min, float max, float decc, float acc, float vel);

	void tocat(int dany);

};

#endif /* NAU_H_ */
