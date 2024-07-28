#include "../header/main.h"
/**
 * keydown_evnt - function check key_down
 * Return: return 1/0 for true/false
 */
int keydown_evnt(int moveLeft,  int moveRight, int moveFwd, int moveBck)
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
	{

	if (event.key.keysym.sym == (SDLK_w && SDLK_a))
		return (moveLeft = 1);
	if (event.key.keysym.sym == (SDLK_w && SDLK_d))
		return (moveRight = 1);
	if (event.key.keysym.sym == (SDLK_w && SDLK_f))
		return (moveFwd = 1);
	if (event.key.keysym.sym == (SDLK_w && SDLK_s))
		return (moveBck = 1);
	if (event.key.keysym.sym == (SDLK_w && SDLK_ESCAPE))
		return (0);
	}

	
	return (1);
}
/**
 * keyup_evnt - function check key_up/release
 * Return: return 1/0 for true/false
 */
int keyup_evnt(int moveLeft,  int moveRight, int moveFwd, int moveBck)
{
	SDL_Event event;
		
	while (SDL_PollEvent(&event))
	{

	if (event.key.keysym.sym == (SDLK_w && SDLK_a))
		return (moveLeft = 0);
	if (event.key.keysym.sym == (SDLK_w && SDLK_d))
		return (moveRight = 0);
	if (event.key.keysym.sym == (SDLK_w && SDLK_f))
		return (moveFwd = 0);
	if (event.key.keysym.sym == (SDLK_w && SDLK_s))
		return (moveBck = 0);
	if (event.key.keysym.sym == (SDLK_w && SDLK_ESCAPE))
		return (0);
	}
	
	return (1);
}
