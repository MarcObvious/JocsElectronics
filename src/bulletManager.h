/*  bulletManager.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*  Bulletmanager conte el vector de bales que hi han al mon, segueix
*   un patró singleton
*/
 
#ifndef BULLETMANAGER_H_
#define BULLETMANAGER_H_

#include <string>
#include <map>
#include <cassert>

#include "utils/framework.h"

#include "bullet.h"

class BulletManager {

private:

	static BulletManager* _instance;

	std::map<std::string, Bullet*>* _bullets; //Vector punters totes les bales

	BulletManager();

	~BulletManager();

public:

	static BulletManager * getInstance(); 		//Retorna el Bulletmanager

	Bullet* get(std::string b_id);//Retorna una Bullet del vector, si no hi es la crea.

};

#endif /* BULLETMANAGER_H_ */
