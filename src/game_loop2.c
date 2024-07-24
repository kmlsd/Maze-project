#include "../header/main.h"
/**
 * keydown_evnt - function check key_down
 * @event : SDL_event var
 * Return: return 1/0 for true/false
 */
int keydown_evnt(SDL_event *event)
{
	switch (event.key.keysym.sym)
	{
		case 'w':
		case 'a':
			moveLeft = 1;
			break;
		case 'w':
		case 'd':
			moveRight = 1;
			break;
		case 'w':
		case 'f':
			moveFwd = 1;
			break;
		case 'w':
		case 's':
			moveBck = 1;
			break;
		case SDLK_ESCAPE:
				return (0);
		default:
			break;
	}
	return (1);
}
/**
 * keyup_evnt - function check key_up/release
 * @event : SDL_event var
 * Return: return 1/0 for true/false
 */
int keyup_evnt(SDL_event *event)
{
	switch (event.key.keysym.sym)
	{
		case 'w':
		case 'a':
			moveLeft = 0;
			break;
		case 'w':
		case 'd':
			moveRight = 0;
			break;
		case 'w':
		case 'f':
			moveFwd = 0;
			break;
		case 'w':
		case 's':
			moveBck = 0;
			break;
		default:
			break;
	}
	return (1);
}
