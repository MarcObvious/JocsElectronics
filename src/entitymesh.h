/*  entitymesh.h
*   Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
*	Classe que defineix objectes que tenen mesh i textura, 
*   hereva de Entity.
*/
#ifndef ENTITYMESH_H_
#define ENTITYMESH_H_

#include "entity.h"
#include "mts/mesh.h"
#include "mts/texture.h"
#include "mts/MeshManager.h"
#include "mts/TextureManager.h"

class EntityMesh : public Entity {
protected:
	Mesh* _mesh = NULL;
	Texture* _texture = NULL;
	Vector3 _color ; //per saber quan disparo a algu si faig mal o no. "proves"
	std::vector<Vector3> _bounds; //bounds, el primer element es el halfsize, el segon center
public:
	EntityMesh();
	virtual ~EntityMesh() {}

	virtual void setParams(std::string mesh_dir, std::string text_dir,
			bool mipmapping, Vector3 posinicial);
	void render();
	Matrix44 getMatrix();
	Vector3 getTop();

	Vector3 getCenter();

	virtual void update(double elapsed_time){};

};

#endif /* ENTITYMESH_H_ */
