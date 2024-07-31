#include "../header/main.h"
#include <SDL2/SDL.h>

/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */
int moveLeft,  moveRight,  moveFwd, moveBck;
double posX, posY, dirX, dirY, planeX, planeY,  moveSpeed,  rotSpeed;
SDL_Window* gWindow;
SDL_Renderer* renderer;
int worldMap[MAP_WIDTH][MAP_HEIGHT];
int main()
{
	SDL_Event event;
	int i = 0;
	

	/*Start up SDL and create window*/
	if (!bool_init())
	{
		printf("Failed to initialize!\n");
	}
	else 
	{

		creat_map(worldMap);

		while (!i)
		{
		SDL_RenderClear(renderer);
                rend_sky_floor(renderer);

			while( SDL_PollEvent( &event ) != 0 )
			{
			i = game_loop( moveLeft,  moveRight,  moveFwd, moveBck);
			/*process movement and rotation speed */
			Player_motion(posX, posY, dirX, dirY,planeX, planeY, moveSpeed, rotSpeed, 
					moveLeft,  moveRight,  moveFwd, moveBck, worldMap);
			}
		renderWalls();
			
			/*Update screen*/
		SDL_RenderPresent(renderer);
		
		}
	}
/*Free resources and close SDL*/
	close();

	return (0);
}

