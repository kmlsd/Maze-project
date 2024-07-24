#include "../header/main.h"
/**
 * ray_dda - Digital Differential Analysis wall hit
 * @wallhit: Integer value (1 if wall was hit else 0)
 * @nswall: Side of the wall that was hit (NS or EW)
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 * @mapX: x-coordinate of current box of the map we're in
 * @mapY: y-coordinate of current box of the map we're in
 * @stepX: What direction to step in x-axis (either +1 or -1)
 * @stepY: What direction to step in y-axis (either +1 or -1)
 * @worldMap: A 2-dimensional array of integer values
 */
void ray_dda(int *wallhit, int *nswall, double *sideDistX, double *sideDistY,
		double deltaDistX, double deltaDistY, int *mapX, int *mapY, int *stepX,
		int *stepY,  int worldMap[][MAP_HEIGHT])
{
	/* perform DDA */
	while (*wallhit == 0)
	{
	if (*sideDistX < *sideDistY)
	{
		*sideDistX += deltaDistX;
		*mapX += *stepX;
		*nswall = 0;
	}
	else
	{
		*sideDistY += deltaDistY;
		*mapY += *stepY;
		*nswall = 1;
	}
	if (worldMap[*mapX][*mapY] > 0)
		*wallhit = 1;
	}
	
}
