/*
 * TextureManager.h
 *
 *  Created on: 13/04/2014
 *      Author: marc
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <string>
#include "texture.h"

class TextureManager{
private:

	static TextureManager* _instance;
	std::map<std::string, Texture*>* _textures_loaded; //Vector textures carregades

	TextureManager(); 								//Constructor

public:

	static TextureManager * getInstance();

	Texture* get(std::string dir, bool mipmapping);
};

#endif /* TEXTUREMANAGER_H_ */

