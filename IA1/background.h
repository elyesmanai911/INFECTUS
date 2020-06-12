#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>

typedef struct {

	SDL_Surface *back_Img;
	SDL_Rect back_Pos;

}Background;


void  loadBackground(Background *Back);
void  initBackground(Background *Back);
void  freeBackground(Background *Back);
void  blitBackground(Background *Back,SDL_Surface *screen);

#endif
