/*  movingentity.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Classe hereva de EntityMesh. Basicament defineix
*	les funcions estandar d'una mesh que es mogui
*/

#ifndef MOVINGENTITY_H_
#define MOVINGENTITY_H_

#include "entitymesh.h"
#include "utils/framework.h"
#include <string>

class MovingEntity: public EntityMesh {
protected:
	float _velocitat;
	float _acceleraccio;
	float _deceleraccio;

	float _max_velocitat;
	float _min_velocitat;

	float _angle_gir_XY;
	float _angle_gir_ZX;
	float _angle_gir_ZY;

public:
	MovingEntity(std::string mesh_dir, std::string text_dir, bool mipmapping,
			Vector3 posinicial);

	 ~MovingEntity(){};

	 bool setParams(float aZY, float aZX, float aXY, float min, float max, float decc, float acc, float vel);

	 float getVelocitat();

	 float getAcceleraccio();

	 float getDeceleraccio();

	 float getAgirXY();

	 float getAgirZX();

	 float getAgirZY();

	 void accelera(double elapsed_time);

	 void decelera(double elapsed_time);

	 void girXY(std::string dir, double elapsed_time);

	 void girZX(std::string dir, double elapsed_time);

	 void girZY(std::string dir, double elapsed_time);

	 //virtual void update(double elapsed_time){};

};

#endif /* MOVINGENTITY_H_ */
