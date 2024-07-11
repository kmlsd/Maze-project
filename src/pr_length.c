#include "../header/raycasting.h"
/**
 * projection_length - A function that calculates the values necessary for
 * @side: Side of the wall that was hit (NS or EW)
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 * @perpWallDist: Perpendicular distance from ray to wall
 * @wall_height: Height of the wall
 * Return: struct of type Projection
 */
Projection_length(int side, double sideDistX, double sideDistY,
						double deltaDistX, double deltaDistY,
						double *perpWallDist, int *wall_height)
{
	

	/*
	* Calculate distance projected on camera direction
	* (Euclidean distance would give fisheye effect!)
	*/
	if (side == 0)
		*perpWallDist = (sideDistX - deltaDistX);
	else
		*perpWallDist = (sideDistY - deltaDistY);

	/* Calculate height of line to draw on screen */
	int lineHeight = (int)(SCREEN_HEIGHT / *perpWallDist);

	/* calculate lowest and highest pixel to fill in current stripe */
	int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
	int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;

	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT - 1;
	ColorRGB color;
	if (side == 0) 
		color = RGB_Green;
	else
		color = RGB_Red;

	verLine(x, drawStart, drawEnd, color);
}
