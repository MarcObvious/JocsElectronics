/*  entityboard.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Classe hereva de EntityMesh. Basicament defineix
*	les funcions que ha de tenir una classe billboard
*/

#ifndef ENTITYBOARD_H_
#define ENTITYBOARD_H_

#include "entitymesh.h"
#include "utils/utils.h"
#include "utils/framework.h"
#include <string>

class EntityBoard: public EntityMesh {
protected:


public:
	EntityBoard();

	void setParams(float tamany, std::string text_dir,
			bool mipmapping, Vector3 posinicial);

	 virtual ~EntityBoard(){};

	 void render(){
		 glPushMatrix();
		 	_model.set();

		 	//_mesh->renderBounds();

		 	glEnable(GL_BLEND);
		 	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			//glDepthMask(true);
		 	glBlendFunc(GL_SRC_ALPHA, GL_ONE); //FREAKING FIRE
		 	_texture->bind();
		 	_mesh->render();

		 	_texture->unbind();
		 	//glDepthMask(false);
		 	glDisable(GL_BLEND);

		 	glPopMatrix();
	 }




	 virtual void update(double elapsed_time){};

};

#endif /* ENTITYBOARD_H_ */
