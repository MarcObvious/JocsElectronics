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
#include "mts/mesh.h"
#include "mts/MeshManager.h"
#include <string>

class EntityBoard: public EntityMesh {
protected:
	int _tamany;

public:
	EntityBoard();

	void setParams(float tamany, std::string text_dir, bool mipmapping, Vector3 posinicial, bool alpha, Vector3 top,
			Vector3 right);

	virtual ~EntityBoard() {
	}
	;

	void render() {
		glPushMatrix();
		_model.set();

		glEnable(GL_BLEND);

		glDepthMask(false);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		_texture->bind();
		_mesh->render();
		_texture->unbind();
		glDepthMask(true);
		glDisable(GL_BLEND);

		glPopMatrix();
	}

	void update(Vector3 top, Vector3 right);

};

#endif /* ENTITYBOARD_H_ */
