#include "../header/main.h"
/**
 *  rend_sky_floor- Draw the sky and floor with diferent color
 *
 */
void rend_sky_floor()
{
	SDL_Rect ceil;
	SDL_Rect floor;
	ceil.x = 0;
	ceil.y = 0;
	ceil.w = SCRN_WIDTH;
	ceil.h = SCRN_WIDTH;
	floor.x = 0;
	floor.y = SCRN_HEIGHT / 2;
	floor.w = SCRN_WIDTH;
	floor.h = SCRN_HEIGHT;

	renderer = SDL_CreateRenderer(gWindow, 1, SDL_RENDERER_ACCELERATED);
	/* Draw the sky BLUE COLOR*/

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);  
	SDL_RenderFillRect(renderer, &ceil);

	printf( "\n sky rendering last her");

	/* Draw the floor YELLOW COLOR*/

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &floor);

	SDL_RenderPresent(renderer);



}
