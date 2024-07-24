#include "../header/main.h"
/**
 * rendwalls- A function to perform raycasting operations.
 */
void renderWalls(void)
{
	double posX = 22, posY = 12, dirX = -1, dirY = 0, planeX = 0, planeY = 0.66;
	int x;
	for (x = 0; x < SCRN_WIDTH; x++)
	{
		double screenCoordinate = (2 * x) / (double)SCREEN_WIDTH - 1;
		double rayPosX = posX;
		double rayPosY = posY;
		double rayDirX = dirX + planeX * screenCoordinate;
		double rayDirY = dirY + planeY * screenCoordinate;

		/*get X, Y coordinate of map by truncating current position*/
		int mapX = (int) rayPosX;
		int mapY = (int) rayPosY;
		/* Calculate distance to next x and y grid lines */
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirY);
		/* Calculate initial step and side distances */
		double sideDistX, sideDistY, WallDist;
		int stepX, stepY, wall_height, wall_top, wall_bottom;
		/*Direction to step (+1 or -1)*/
		int stepX;
		int stepY;
		/*north south, or east west?*/
		int nswall = 0;
		int wallhit = 0;
		/*calculate sidedist from x & y  */
		calc_sidedist(rayDirX, rayDirY, &sideDistX,
			&sideDistY, &stepX, &stepY, mapX, mapY, deltaDistX, deltaDistY)
		/* World map */
		creat_map(worldMap);
		int worldMap[MAP_WIDTH][MAP_HEIGHT];
		ray_dda(&wallhit, &nswall, &sideDistX, &sideDistY, deltaDistX,
							deltaDistY, &mapX, &mapY, stepX, stepY, worldMap);
		wall_rend(nswall, sideDistX, sideDistY, deltaDistX, deltaDistY,
						&WallDist, &wall_height, &wall_top, &wall_bottom);
	}


}
