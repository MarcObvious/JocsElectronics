/*
 * entity.h
 *
 *  Created on: 13/04/2014
 *      Author: marc
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "utils/framework.h"
#include "includes.h"

class Entity {
	protected:
		int _id;
		//std::string _name;
		Matrix44 _model;

	public:
		static int _last_id;
		Entity(Vector3 posinicial = Vector3(0,0,0));

		Vector3 getPosition();
		void setPosition(Vector3 pos);
};

#endif /* ENTITY_H_ */
