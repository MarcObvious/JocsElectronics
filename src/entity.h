/*  entity.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Classe base del que heredara qualsevol objecte del
*   joc, basicament nomès te una id un nom i una posició.
*   (pot no tenir ni tan sols una mesh)
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include "utils/framework.h"
#include "includes.h"
#include <string>

class Entity {
	protected:
		int _id;
		std::string _name;
		Matrix44 _model;

	public:
		static int _last_id;
		Entity(Vector3 posinicial);

		std::string getName();
		void printPosition();
		Vector3 getPosition();
		void setPosition(Vector3 pos);
};

#endif /* ENTITY_H_ */
