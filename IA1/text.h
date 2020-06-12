#ifndef TEXT_H
#define TEXT_H
#define FPS 60
#define ACCELX 0
#define ACCELY 0

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "Hero.h"


typedef struct{

 SDL_Surface *text_Vie;
 SDL_Surface *text_distEH;
}Text;


void  initText(Text *T);
void  loadFont(TTF_Font **police1,TTF_Font **police2);
void  Afficher_Text(TTF_Font *police1,TTF_Font *police2,Text *T,SDL_Surface *screen,Hero H,int distEH);
void  freeFont(TTF_Font **police);

#endif
