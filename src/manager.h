/*  manager.h  
    Marc Mateu nia 146756 2014 UPF  cat166@gmail.com
	Prototip de Manager Estandar d'on heredaran tots els managers, 
	S'ha de currar mes.
*/

//#ifndef MANAGER_H_
//#define MANAGER_H_
//
//#include <string>
//#include <map>
//#include "includes.h"
//
//template <class T>
//
//class Manager{
//	protected:
//		static Manager* _instance;
//		std::map<std::string,T*>* _loaded;
//
//	public:
//
//		Manager(){
//				assert(_instance==NULL); //Si no es cumpleix PETA
//				_instance = this;
//				_loaded = new std::map<std::string, T*>();
//		}
//
//		~Manager(){}
//
//		Manager * getInstance(){
//			if (_instance == NULL)
//					_instance = new Manager();
//				return _instance;
//		}
//
//		T* get(std::string dir)
//		{
//			typename std::map<std::string, T*>::iterator it = _loaded->find(dir);
//
//				if (it != _loaded->end()) {    //La mesh ja existia
//					return (it->second);
//				} else {						//La mesh no existia, la carreguem
//					T* mesh_nova = new T();
//
//					if (!mesh_nova->loadASE((char*) dir.c_str())) {
//						std::cout << "ERROR AL LLEGIR MESH: " << dir.c_str()
//										<< std::endl;
//						exit(0);
//					}
//
//					_loaded->insert(
//							std::pair<std::string, Mesh*>(dir, mesh_nova));
//					return mesh_nova;
//				}
//		}
//
//};
//
//#endif
