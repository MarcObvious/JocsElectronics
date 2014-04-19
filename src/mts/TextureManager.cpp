#include "TextureManager.h"

TextureManager::TextureManager() {
	assert(_instance==NULL); //Si no es cumpleix PETA
	_instance = this;
	_textures_loaded = new std::map<std::string, Texture*>();
}

TextureManager::~TextureManager() {
    _textures_loaded->clear();
    free(_instance);
}

TextureManager * TextureManager::getInstance() {
		if (_instance == NULL)
			_instance = new TextureManager();
		return _instance;
}

Texture* TextureManager::get(std::string text_dir, bool mipmapping) {
	std::map<std::string, Texture*>::iterator it = _textures_loaded->find(
			text_dir);

	if (it != _textures_loaded->end())  //La textura ja existia
		return (it->second);
	
	else {						 //La texture no existia, la carreguem
		Texture* textura_nova = new Texture();
		if (!textura_nova->load(text_dir.c_str(), mipmapping)) {
			std::cout << "ERROR AL LLEGIR TEXTURA: " << text_dir.c_str()
							<< std::endl;
			exit(0);
		}
		_textures_loaded->insert(
				std::pair<std::string, Texture*>(text_dir, textura_nova));//Y la desem per tenir-la en el futur
		return textura_nova;
	}
}
