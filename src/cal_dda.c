#include "../header/raycasting.h"
/**
 * calculate_distances - A function to calculate direction dstance
 * @object: struct of type Vector containing all coordinates of that oject
 * @rayDirX: Ray position and direction in x-axis
 * @rayDirY: Ray position and direction in y-axis
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @stepX: What direction to step in x-axis (either +1 or -1)
 * @stepY: What direction to step in y-axis (either +1 or -1)
 * @mapX: x-coordinate of current box of the map we're in
 * @mapY: y-coordinate of current box of the map we're in
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 */
void calculate_distances(Vector object, double rayDirX, double rayDirY,
						double *sideDistX, double *sideDistY, int *stepX,
						int *stepY, int mapX, int mapY, double deltaDistX,
						double deltaDistY)
{
	*stepX, *stepY = 0;
	/* calculate step and initial sideDist */
	if (rayDirX < 0)
	{
		*stepX = -1;
		*sideDistX = (object.posX - mapX) * deltaDistX;
	}
	else
	{
		*stepX = 1;
		*sideDistX = (mapX + 1.0 - object.posX) * deltaDistX;
	}

	if (rayDirY < 0)
	{
		*stepY = -1;
		*sideDistY = (object.posY - mapY) * deltaDistY;
	} else
	{
		*stepY = 1;
		*sideDistY = (mapY + 1.0 - object.posY) * deltaDistY;
	}
}
/**
 * DDA - Digital Differential Analysis
 *
 * @hit: Integer value (1 if wall was hit else 0)
 * @side: Side of the wall that was hit (NS or EW)
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 * @mapX: x-coordinate of current box of the map we're in
 * @mapY: y-coordinate of current box of the map we're in
 * @stepX: What direction to step in x-axis (either +1 or -1)
 * @stepY: What direction to step in y-axis (either +1 or -1)
 * @worldMap: A 2-dimensional array of integer values
 * Return: Code of the wall if wall was hit else 0
 */
int DDA(int *hit, int *side, double *sideDistX, double *sideDistY,
		double deltaDistX, double deltaDistY, int *mapX, int *mapY, int stepX,
		int stepY, int (*worldMap)[MAP_WIDTH]{

	while (*hit == 0)
	{
		if (*sideDistX < *sideDistY)
		{
			*sideDistX += deltaDistX;
			*mapX += stepX;
			*side = 0;
		} else
		{
			*sideDistY += deltaDistY;
			*mapY += stepY;
			*side = 1;
		}
		if (worldMap[mapX][mapY] > 0)
			*hit = worldMap[*mapX][*mapY];
	} return (*hit);

}
