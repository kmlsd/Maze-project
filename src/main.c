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
	

	/*Start up SDL and create window*/
	if (!bool_init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		creat_map(worldMap);
		while (game_loop(moveLeft,  moveRight,  moveFwd, moveBck))
		{
			rend_sky_floor();
			renderWalls();
			/*Clear screen*/
			SDL_RenderClear(renderer);

			/*Update screen*/
			SDL_RenderPresent(renderer);
			/*process movement and rotation speed */
			Player_motion(posX, posY, dirX, dirY,planeX, planeY,
	moveSpeed,  rotSpeed, moveLeft,  moveRight,  moveFwd, moveBck, worldMap);
		}
	}
/*Free resources and close SDL*/
	close();

	return (0);
}

