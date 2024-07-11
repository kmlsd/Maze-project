
#include "../header/raycasting.h"

/**
 * raycaster - A function to perform raycasting operations.
 *
 * @object: struct of type Vector containing all coordinates of that oject
 * @time: Time of current frame
 * @oldTime: Time of previous frame
 * @instance: struct of type SDL_Instance
 * @event: An SDL Event
 * @delay: The delay flag (true or false)
 * @keys: A boolean array to store key states
 * Return: 0 (Success)
 */
int raycaster(Vector object, double *time, double *oldTime,
			SDL_Instance *instance, SDL_Event *event, bool delay,
			const unsigned char *keys)
{
	while (!done(event, delay, keys))
		break;
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		/* x-coord in camera space */
		double cameraX = 2 * x / SCREEN_WIDTH - 1;
		/* Calculate ray direction vector */
		double rayDirX = object.dirX + object.planeX * cameraX;
		double rayDirY = object.dirY + object.planeY * cameraX;
		/* Calculate map position of ray origin */
		int mapX = floor(object.posX);
		int mapY = floor(object.posY);
		/* Calculate distance to next x and y grid lines */
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirY);
		/* Calculate initial step and side distances */
		double sideDistX, sideDistY, perpWallDist;
		int stepX, stepY, wall_height, wall_top, wall_bottom;
		int hit = 0;
		int side = 0; /* was a NS or a EW wall hit? */
		int worldMap[MAP_WIDTH][MAP_HEIGHT];
		/* World map */
		creat_map(worldMap);
		calculate_distances(object, rayDirX, rayDirY, &sideDistX,
			&sideDistY, &stepX, &stepY, mapX, mapY, deltaDistX, deltaDistY);
		int wall_code = DDA(&hit, &side, &sideDistX, &sideDistY, deltaDistX,
							deltaDistY, &mapX, &mapY, stepX, stepY, worldMap);
		if (wall_code != 0)
			projection_length(side, sideDistX, sideDistY,	deltaDistX, deltaDistY,
						&perpWallDist, &wall_height);
	}
	fps_count(time, oldTime);

	return (0);
}

