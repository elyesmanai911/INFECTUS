
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include"dep.h"


void initial(guard *c, int x, int y){
	c->sprite = IMG_Load("guard.png");
	c->sprite2 = IMG_Load("guard2.png");
	c->x = x;
	c->y = y;
	c->dx = 0;
	c->cx = 0;
}

void aff(guard *c, SDL_Surface **screen){
	SDL_Rect r2 = {c->x, c->y};
	if(c->dx){
		c->x += 5;
		SDL_BlitSurface(c->sprite2,NULL,*screen, &r2);
	}else{
		SDL_BlitSurface(c->sprite,NULL,*screen, &r2);
		c->x -= 5;

	}

	c->cx++;
	if(c->cx % 30 == 0)
		c->dx = !c->dx;
}

int collide(SDL_Rect *position_player, guard *c)
 {
    if((position_player->x >= c->x + c->w)|| (position_player->x + position_player->w <= c->x)|| (position_player->y >= c->y + c->h)|| (position_player->y + position_player->h <= c->y))
    
        return 0;
  else
   return 1;
}


