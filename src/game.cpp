#include "game.h"

//some globals

World* World::_instance = NULL; //Mon

Shader* shader = NULL;

Game::Game(SDL_Window* window) {
	this->window = window;
	// initialize attributes
	// Warning: DO NOT CREATE STUFF HERE, USE THE INIT 
	// things create here cannot access opengl
	window_width = WINDOW_WIDTH;
	window_height = WINDOW_HEIGHT;

	keystate = NULL;
	mouse_state = true;
	mouse_locked = true;
}

Game::~Game(){
    free (shader);
	
}

//Here we have already GL working, so we can create meshes and textures
void Game::init(void) {
	std::cout << "initiating game..." << std::endl;

	//OpenGL flags
	glEnable( GL_CULL_FACE); //render both sides of every triangle
	glEnable( GL_DEPTH_TEST); //check the occlusions using the Z buffer

	//create our camera


	shader = new Shader();
	shader->load("assets/shaders/simple.vs", "assets/shaders/simple.ps");

	//hide the cursor
	SDL_ShowCursor(!mouse_locked); //hide or show the mouse
}

//what to do when the image has to be draw
void Game::render(void) {
	//set the clear color (the background color)
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Clear the window and the depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Put the camera matrices on the stack of OpenGL (only for fixed rendering)
	//camera->set();

	//Draw out world
	//drawGrid(500); //background grid

	//draw the plane
	glColor3f(1, 1, 1);
	World::getInstance()->render();

	//swap between front buffer and back buffer

	SDL_GL_SwapWindow(this->window);
}

void Game::update(double seconds_elapsed) {
	//to navigate with the mouse fixed in the middle
	if (mouse_locked) {
		SDL_WarpMouseInWindow(this->window, window_width * 0.5,
				window_height * 0.5); //put the mouse back in the middle of the screen
		this->mouse_position.x = window_width * 0.5;
		this->mouse_position.y = window_height * 0.5;
	}

	double speed = seconds_elapsed * 100; //the speed is defined by the seconds_elapsed so it goes constant

//	//mouse input to rotate the cam
//	if ((mouse_state & SDL_BUTTON_LEFT) || mouse_locked) //is left button pressed?
//			{
//		camera->rotate(speed * mouse_delta.x * 0.0005, Vector3(0, -1, 0));
//		camera->rotate(speed * mouse_delta.y * 0.0005,
//				camera->getLocalVector(Vector3(-1, 0, 0)));
//	}

//	async input to move the camera around
	
	
	if (keystate[SDL_SCANCODE_LSHIFT])
		speed *= 10; //move faster with left shift

	if (keystate[SDL_SCANCODE_UP])
		World::getInstance()->_camera->move(Vector3(0, 0, 1) * speed);

	if (keystate[SDL_SCANCODE_DOWN])
		World::getInstance()->_camera->move(Vector3(0, 0, -1) * speed);

	if (keystate[SDL_SCANCODE_LEFT])
		World::getInstance()->_camera->move(Vector3(1, 0, 0) * speed);

	if (keystate[SDL_SCANCODE_RIGHT])
		World::getInstance()->_camera->move(Vector3(-1, 0, 0) * speed);

	if (keystate[SDL_SCANCODE_D]) 
		World::getInstance()->_jugador->girZY("DRETA", seconds_elapsed);
	
	if (keystate[SDL_SCANCODE_A]) 
		World::getInstance()->_jugador->girZY("ESQUERRA", seconds_elapsed);

	if (keystate[SDL_SCANCODE_W]) 
		World::getInstance()->_jugador->girZX("AMUNT", seconds_elapsed);
	
	if (keystate[SDL_SCANCODE_S]) 
		World::getInstance()->_jugador->girZX("AVALL", seconds_elapsed);
	

	if (keystate[SDL_SCANCODE_N]) 
		World::getInstance()->_jugador->girXY("DRETA", seconds_elapsed);
	
	if (keystate[SDL_SCANCODE_M]) 
		World::getInstance()->_jugador->girXY("ESQUERRA", seconds_elapsed);
	
	
	if (keystate[SDL_SCANCODE_Q]) 
		World::getInstance()->_jugador->accelera(seconds_elapsed);
	
	if (keystate[SDL_SCANCODE_E]) 
		World::getInstance()->_jugador->decelera(seconds_elapsed);
	
	
	World::getInstance()->update(seconds_elapsed);
}

//Keyboard event handler (sync input)
void Game::onKeyPressed(SDL_KeyboardEvent event) {
	switch (event.keysym.sym) {
	case SDLK_ESCAPE:
		exit(0); //ESC key, kill the app
	}
}

void Game::onMouseButton(SDL_MouseButtonEvent event) {
	if (event.button == SDL_BUTTON_MIDDLE) //middle mouse
	{
		mouse_locked = !mouse_locked;
		SDL_ShowCursor(!mouse_locked);
	}
}

void Game::setWindowSize(int width, int height) {
	glViewport(0, 0, width, height);
	window_width = width;
	window_height = height;
}

