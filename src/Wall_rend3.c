#include "../header/main.h"

/**
 * wall_rend - A function that calculates the values necessary for
 * camera projection.
 * @nswall: Side of the wall that was hit (NS or EW)
 * @sideDistX: Length of ray from current position to next position on x-axis
 * @sideDistY: Length of ray from current position to next position on y-axis
 * @deltaDistX: Length of ray from one point to another on x-axis
 * @deltaDistY: Length of ray from one point to another on y-axis
 * @x: is x from for loop
 */
void wall_rend(int x, int nswall, double sideDistX, double sideDistY,
						double deltaDistX, double deltaDistY)
{
	int screen_h = SCRN_HEIGHT;
	double WallDist;
	int wallHeight, drawStart, drawEnd;

	if (nswall == 0)
		WallDist = (sideDistX - deltaDistX);
	else
		WallDist = (sideDistY - deltaDistY);

	/* Calculate height of line to draw on screen */
	wallHeight = (int)(screen_h / WallDist);

	/* calculate lowest and highest pixel to fill in current stripe */
	drawStart = -wallHeight / 2 + screen_h / 2;
	drawEnd = wallHeight / 2 + screen_h / 2;

	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= SCRN_HEIGHT)
		drawEnd = SCRN_HEIGHT - 1;
	/*Choose color for the wall based wall direction */
	if (nswall == 0)
		SDL_SetRenderDrawColor(renderer,  255, 0, 0, 255);
	else
		SDL_SetRenderDrawColor(renderer,  255, 128, 0, 255);
	/* Draw the wall on the screen*/
	 SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);

}
