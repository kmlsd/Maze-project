#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <SDL2/SDL.h>

/*constant variablels*/
#define SCRN_WIDTH 640
#define SCRN_HEIGHT 480
#define MIDDLE_X SCRN_WIDTH / 2
#define MIDDLE_Y SCRN_HEIGHT / 2

#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define false 0
#define true 1

/*Player position*/
extern double posX, posY;
/*Player vector variables*/
extern double dirX, dirY, planeX, planeY;

/*Player movement speed*/
extern double moveSpeed, rotSpeed;
/*Player movement direction vector*/
extern int moveLeft, moveRight, moveFwd, moveBck;

/*Creates a world map*/
extern int worldMap[MAP_WIDTH][MAP_HEIGHT];


/*bool SDL initialize*/
int bool_init(void);
void close(void);
/*
extern int SDL_DestroyRenderer(renderer);
extern int SDL_DestroyWindow(gWindow);
extern int SDL_Quit();
extern int SDL_Window *gWindow = NULL;
extern int SDL_ShowCursor(false);
extern int SDL_SetRelativeMouseMode(true);
*/
/*The window renderer*/
/*
extern int  SDL_Renderer  *renderer = NULL;
extern int SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
extern int SDL_RenderSetLogicalSize(renderer, SCRN_WIDTH, SCRN_HEIGHT);
*/
/*creat world map*/
void creat_map(int (*worldMap)[MAP_WIDTH]);
/*sky & floor render */
void rend_sky_floor(void);

/* wall rendering section*/
void renderWalls();
/*void calc_sidedist(double rayDirX, double rayDirY, double sideDistX, double sideDistY,
					 int mapX, int mapY, int stepX, int stepY,
					 double deltaDistX, double deltaDistY);
*/
void ray_dda(int *wallhit, int *nswall, double *sideDistX, double *sideDistY,
		double deltaDistX, double deltaDistY, int *mapX, int *mapY, int *stepX,
		int *stepY, int worldMap[][MAP_HEIGHT]);
void wall_rend(int x, int nswall, double sideDistX, double sideDistY,
				double deltaDistX, double deltaDistY);

/*game loop function with while */
extern int moveLeft, moveRight, moveFwd, moveBck;
int game_loop(void);
int mousekey_evnt(void);
int keydown_evnt(void);
int keyup_evnt(void);
void Player_motion(void);
/*SDL function*/
SDL_Window *gWindow = NULL;
SDL_Renderer  *renderer = NULL;
#endif /*_MAIN_H_*/
