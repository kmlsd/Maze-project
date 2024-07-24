#include "../header/main.h"
#include <SDL2/SDL.h>

/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
	

	/*Start up SDL and create window*/
	if (!bool_init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		creat_map(worldMap);
		while (game_loop())
		{
			rend_sky_floor();
			renderWalls();
			/*Clear screen*/
			SDL_RenderClear(renderer);

			/*Update screen*/
			SDL_RenderPresent(renderer);
			/*process movement and rotation speed */
			Player_motion();
		}
	}
/*Free resources and close SDL*/
	close();

	return (0);
}

