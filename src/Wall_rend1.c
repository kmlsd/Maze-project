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
		double screenCoordinate = (2 * x) / (double)SCRN_WIDTH - 1;
		double rayPosX = posX;
		double rayPosY = posY;
		double rayDirX = dirX + planeX * screenCoordinate;
		double rayDirY = dirY + planeY * screenCoordinate;
		int mapX = (int) rayPosX;
		int mapY = (int) rayPosY;
		/* Calculate distance to next x and y grid lines */
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirY);
		/* Calculate initial step and side distances */
		double sideDistX = 0, sideDistY = 0;
		int stepX = 0, stepY = 0;
		int nswall = 0, wallhit = 0;
		if (rayDirX < 0)
		{
		stepX = -1;
		sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
		stepX = 1;
		sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
                {
		stepY = -1;
		sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
		stepY = 1;
		sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		ray_dda(&wallhit, &nswall, &sideDistX, &sideDistY, deltaDistX,
							deltaDistY, &mapX, &mapY, &stepX, &stepY, worldMap);
		wall_rend(x, nswall, sideDistX, sideDistY, deltaDistX, deltaDistY);
	}
}
