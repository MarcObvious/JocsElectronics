/*  texturemanager.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*   TextureManager que conte el vector de textures, segueix
*   un patró singleton
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

    ~TextureManager();
public:

	static TextureManager * getInstance();

	Texture* get(std::string dir, bool mipmapping);
};

#endif /* TEXTUREMANAGER_H_ */

