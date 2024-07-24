#include "../header/main.h"
/**
 * keydown_evnt - function check key_down
 * Return: return 1/0 for true/false
 */
int keydown_evnt(void)
{
	SDL_Event event;

	switch (event.key.keysym.sym)
	{
	switch(SDLK_w)
	{
		case SDLK_a:
			moveLeft = 1;
			break;
		case SDLK_d:
			moveRight = 1;
			break;
		case SDLK_f:
			moveFwd = 1;
			break;
		case SDLK_s:
			moveBck = 1;
			break;
	}
	case SDLK_ESCAPE:
			return (0);
	default:
		break;
	}
	return (1);
}
/**
 * keyup_evnt - function check key_up/release
 * Return: return 1/0 for true/false
 */
int keyup_evnt(void)
{
	SDL_Event event;

	switch (event.key.keysym.sym)
	{
	switch (SDLK_w)
	{
		case SDLK_a:
			moveLeft = 0;
			break;
		
		case SDLK_d:
			moveRight = 0;
			break;
		
		case SDLK_f:
			moveFwd = 0;
			break;
		case SDLK_s:
			moveBck = 0;
			break;
	}
	default:
		break;
	}
	return (1);
}
