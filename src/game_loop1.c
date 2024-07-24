#include "../header/main.h"
/**
 * game_loop - function wich can change dir, movement, spd
 * Return: return 1/0 for true/false for success loop
 */
int game_loop(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
					keydown_evnt(event);
			case SDL_KEYUP:
					keyup_evnt(event);
			case SDL_MOUSEMOTION:
					mousekey_evnt(event);
			case SDL_QUIT:
				return (0);
			default:
				break;
		}
	}
	return (1);
}
/**
 * mousekey_evnt - function check mouse motion direction
 * @event : SDL_event var
 * Return: return 1 for mouse motion
 */
int mousekey_evnt(SDL_Event *event)
{
if  (event.motion.xrel)
	{
	double newRotateSpeed = (double)event.motion.xrel * -rotSpeed;
	double oldDirX = dirX;

	dirX = dirX * cos(newRotateSpeed) - dirY * sin(newRotateSpeed);
	dirY = oldDirX * sin(newRotateSpeed) + dirY * cos(newRotateSpeed);
	double oldPlaneX = planeX;

	planeX = planeX * cos(newRotateSpeed) - planeY * sin(newRotateSpeed);
	planeY = oldPlaneX * sin(newRotateSpeed) + planeY * cos(newRotateSpeed);
	}
SDL_WarpMouseInWindow(gwindow, MIDDLE_X, MIDDLE_Y);

return (1);
}

