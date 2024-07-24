#include "../header/main.h"
/**
 *  rend_sky_floor- Draw the sky and floor with diferent color
 *
 **/
void rend_sky_floor(void)
{
	/* Draw the sky*/
	SDL_SetRenderDrawColor(instance.renderer, 0, 0, 255, 255);
	for (x = 0; x <= SCRN_WIDTH; x++)
	{
	SDL_RenderDrawLine(renderer, x, 0, x, SCRN_HEIGHT / 2);
	}

	/* Draw the floor*/
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	for (x = 0; x <= SCRN_WIDTH; x++)
	{
	SDL_RenderDrawLine(renderer, x, SCRN_HEIGHT / 2,  x, SCRN_HEIGHT);
	}
}
