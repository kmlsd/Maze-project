#include "../header/main.h"
#include <math.h>

/**
 * Player_motion - function change Player base on inPut key 
 * 
 */
void Player_motion(void)
{
	/*timing for input and FPS counter*/
	oldTime = time;
	time = SDL_GetTicks();
	/*frameTime is the time this frame has taken, in seconds*/
	double frameTime = (time - oldTime) / 1000.0; 
	/*FPS counter*/
	printf(1.0 / frameTime); 

	/*speed modifiers*/
	double moveSpeed = frameTime * 5.0; 
	double rotSpeed = frameTime * 3.0; 

	if(moveFwd)
	{
		if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == 0)
			posX += dirX * moveSpeed;
		if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == 0)
			posY += dirY * moveSpeed;
	}
	if (moveBck)
	{
		if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == 0)
			posX -= dirX * moveSpeed;
		if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == 0)
			posY -= dirY * moveSpeed;
	}
	if (moveRight)
	{
		/*both camera direction and camera plane must be rotated*/
		double oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	if (moveLeft)
	{
		/*both camera direction and camera plane must be rotated*/
		double oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
}
