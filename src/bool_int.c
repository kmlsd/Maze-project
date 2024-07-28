#include "../header/main.h"
/**
* bool_init - function initialized SDL
* Return: int value of bool(true / false)
*/
int bool_init(void)
{
	SDL_Window *gWindow = NULL;
	SDL_Renderer  *renderer =  NULL;
	/*_Bool success = 1;Initialize SDL*/
	int success = 1;
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = 0;
	}
	else
	{					
		/*Create window*/
		gWindow = SDL_CreateWindow("Maze project ", 0, 0, SCRN_WIDTH, SCRN_HEIGHT,
				SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = 0;
		}
		else
		{
			/*Create renderer for window*/
			renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
			SDL_RenderSetLogicalSize(renderer, SCRN_WIDTH, SCRN_HEIGHT);
			SDL_RenderClear(renderer);	

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
