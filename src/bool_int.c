#include "../header/main.h"
/**
* bool_init - function initialized SDL
* Return: int value of bool(true / false)
*/
int bool_init(void)
{
	SDL_Window *gWindow = NULL;
	SDL_Renderer  *renderer =  NULL;
	int success = 1; 

	setenv("SDL_VIDEO_EGL", "0", 1);
	/*_Bool success = 1;Initialize SDL*/
	if (SDL_Init(SDL_INIT_VIDEO  | SDL_INIT_JOYSTICK) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = 0;
	}
	else
	{					
		/*Create window*/
		gWindow = SDL_CreateWindow("Maze project ", 0, 0, SCRN_WIDTH, SCRN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = 0;
		}
		else
		{
			/*Create renderer for window*/
			renderer = SDL_CreateRenderer(gWindow, 0, SDL_RENDERER_ACCELERATED);
			/*SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");*/
			/*SDL_RenderSetLogicalSize(renderer, SCRN_WIDTH, SCRN_HEIGHT);*/
			/*SDL_RenderClear(renderer);*/

			if (renderer == NULL)
			{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			success = 0;
			}
		}
	}
	/*Hide cursor*/
	SDL_ShowCursor(false);
	SDL_SetRelativeMouseMode(true);

	return (success);
}
/**
 * close - closed all
 */
void close(void)
{
	/*Destroy window*/
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	renderer = NULL;

	/*Quit SDL subsyste*/
	SDL_Quit();
}
