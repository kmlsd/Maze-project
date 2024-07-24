#include "../header/main.h"
#include <math.h>

/**
 * Player_motion - function change Player base on inPut key 
 * 
 */
void Player_motion(void)
{
	/*timing for input and FPS counter*/
	double oldTime = 0;
	double time = 0;
	double frameTime = 0;
	double oldDirX = 0, oldPlaneX = 0;

	oldTime = time;

	time = SDL_GetTicks();
	/*frameTime is the time this frame has taken, in seconds*/
	frameTime = (time - oldTime) / 1000.0; 
	/*FPS counter*/
	printf("%f\n", 1.0 / frameTime); 

	/*speed modifiers*/
	moveSpeed = frameTime * 5.0; 
	rotSpeed = frameTime * 3.0;

	if(moveFwd)
	{
		if(worldMap[(int)(posX + dirX * moveSpeed)][(int)(posY)] == 0)
			posX += dirX * moveSpeed;
		if(worldMap[(int)(posX)][(int)(posY + dirY * moveSpeed)] == 0)
			posY += dirY * moveSpeed;
	}
	if (moveBck)
	{
		if(worldMap[(int)(posX - dirX * moveSpeed)][(int)(posY)] == 0)
			posX -= dirX * moveSpeed;
		if(worldMap[(int)(posX)][(int)(posY - dirY * moveSpeed)] == 0)
			posY -= dirY * moveSpeed;
	}
	if (moveRight)
	{
		/*both camera direction and camera plane must be rotated*/

		oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	if (moveLeft)
	{
		/*both camera direction and camera plane must be rotated*/

		oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
}
