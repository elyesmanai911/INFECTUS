#ifndef DEP_H_
#define DEP_H_
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>


typedef struct guard {
	SDL_Surface *sprite,*sprite2;
	int x,y;
	int dx,cx;
         int w ,h ;
} guard;
int collide(SDL_Rect *position_player, guard *c);
void initial(guard *c, int x, int y);
void aff(guard *c, SDL_Surface **screen);

#endif

