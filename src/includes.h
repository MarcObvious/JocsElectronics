/*  by Javi Agenjo 2013 UPF  javi.agenjo@gmail.com
	This file has all the includes so the app works in different systems.
	It is a little bit low level so do not worry about the code.
*/

#ifndef INCLUDES_H
#define INCLUDES_H

//define the application window size
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_FULLSCREEN false
#define WINDOW_CAPTION "my game"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>

//used to access opengl extensions
//void* getGLProcAddress(const char*);
#define REGISTER_GLEXT(RET, FUNCNAME, ...) typedef RET (APIENTRY * FUNCNAME ## _func)(__VA_ARGS__); FUNCNAME ## _func FUNCNAME = NULL;
#define IMPORT_GLEXT(FUNCNAME) FUNCNAME = (FUNCNAME ## _func) SDL_GL_GetProcAddress(#FUNCNAME); if (FUNCNAME == NULL) { std::cout << "ERROR: This Graphics card doesnt support " << #FUNCNAME << std::endl; }

#endif
