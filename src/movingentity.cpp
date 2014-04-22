#include "movingentity.h"

MovingEntity::MovingEntity() {
	 _velocitat=0;
		 _acceleraccio=0;
		 _deceleraccio=0;

		 _max_velocitat=0;
		 _min_velocitat=0;

		 _angle_gir_XY=0;
		 _angle_gir_ZX=0;
		 _angle_gir_ZY=0;
		 _name << "mobil";

	}
void MovingEntity::setParams(std::string mesh_dir, std::string text_dir,
		bool mipmapping, Vector3 posinicial, float aZY, float aZX, float aXY, float min, float max, float decc, float acc, float vel){

	EntityMesh::setParams(mesh_dir, text_dir, mipmapping, posinicial);

	_velocitat = vel;
	_acceleraccio = acc;
	_deceleraccio = decc;

	_max_velocitat = max;
	_min_velocitat = min;

	_angle_gir_XY = aXY;
	_angle_gir_ZX = aZX;
	_angle_gir_ZY = aZY;

	//std::cout << vel << " " << acc  << " "<< decc << " "<< max << " "<<  min << " "<< aXY << " "<< aZX << " "<< aZY << std::endl;
}


 float MovingEntity::getVelocitat() {
	return _velocitat;
}

 float MovingEntity::getAcceleraccio() {
	return _acceleraccio;
}

 float MovingEntity::getDeceleraccio() {
	return _deceleraccio;
}

 float MovingEntity::getAgirXY() {
	return _angle_gir_XY;
}

 float MovingEntity::getAgirZX() {
	return _angle_gir_ZX;
}

 float MovingEntity::getAgirZY() {
	return _angle_gir_ZY;
}

 void MovingEntity::accelera(double elapsed_time){
	if((_velocitat += getAcceleraccio() * elapsed_time) > _max_velocitat)
		_velocitat =  _max_velocitat;
}

 void MovingEntity::decelera(double elapsed_time){
	if((_velocitat -= getDeceleraccio() * elapsed_time) < _min_velocitat){
		_velocitat = _min_velocitat;
	}
}

 void MovingEntity::girZY(std::string dir, double elapsed_time){
	if(dir.compare("DRETA") == 0)
		_model.rotateLocal(-getAgirZY()* elapsed_time, Vector3(0,0,1));
	else
		_model.rotateLocal(getAgirZY() * elapsed_time, Vector3(0,0,1));
}

 void MovingEntity::girXY(std::string dir, double elapsed_time){
	if(dir.compare("DRETA") == 0)
		_model.rotateLocal(-getAgirXY() * elapsed_time, Vector3(0,1,0));
	else
		_model.rotateLocal(getAgirXY()* elapsed_time, Vector3(0,1,0));
}

 void MovingEntity::girZX(std::string dir, double elapsed_time){
	if(dir.compare("AMUNT") == 0)
		_model.rotateLocal(-getAgirZX()* elapsed_time, Vector3(1,0,0));
	else
		_model.rotateLocal(getAgirZX() * elapsed_time, Vector3(1,0,0));
}

