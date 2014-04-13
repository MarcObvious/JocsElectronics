/*
 * TextureManager.h
 *
 *  Created on: 13/04/2014
 *      Author: marc
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <string>
#include <map>
#include "texture.h"

class TextureManager{
private:
	std::map<std::string, Texture*>* _textures_loaded; //vector textures carregades

	TextureManager(); 								//Constructor
	TextureManager(TextureManager const&);
	void operator=(TextureManager const&);			//Forçar singleton s'exectuti nomes un cop

public:


	static TextureManager & getInstance();

	Texture* get(std::string dir, bool mipmapping);
};

#endif /* TEXTUREMANAGER_H_ */

