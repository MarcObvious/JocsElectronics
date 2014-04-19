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
	Mesh* _mesh;
	Texture* _texture;
public:
	EntityMesh(std::string mesh_dir, std::string text_dir, bool mipmapping, Vector3 posinicial);
	~EntityMesh() {}

	void render();
	Matrix44 getMatrix();
	Vector3 getTop();

	Vector3 getCenter();

};

#endif /* ENTITYMESH_H_ */
