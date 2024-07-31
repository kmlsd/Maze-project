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

/*creat world map*/
void creat_map(int (*worldMap)[MAP_WIDTH]);
/*sky & floor render */
void rend_sky_floor();

/* wall rendering section*/
void renderWalls();

void ray_dda(int *wallhit, int *nswall, double *sideDistX, double *sideDistY,
		double deltaDistX, double deltaDistY, int *mapX, int *mapY, int *stepX,
		int *stepY, int worldMap[][MAP_HEIGHT]);
void wall_rend(int x, int nswall, double sideDistX, double sideDistY,
				double deltaDistX, double deltaDistY);

/*game loop function with while */
extern int moveLeft, moveRight, moveFwd, moveBck;
int game_loop(int moveLeft, int  moveRight, int  moveFwd, int moveBck);
int mousekey_evnt(void);
int keydown_evnt(int moveLeft, int  moveRight, int moveFwd, int moveBck);
int keyup_evnt(int moveLeft, int  moveRight, int moveFwd, int moveBck);
void Player_motion(double posX, double posY, double dirX, double dirY,
	double planeX, double planeY, double moveSpeed, double rotSpeed,
	int moveLeft, int  moveRight, int moveFwd, int moveBck, int (*worldMap)[MAP_WIDTH]);
/*SDL function*/
extern SDL_Window *gWindow;
extern SDL_Renderer  *renderer;
#endif /*_MAIN_H_*/
