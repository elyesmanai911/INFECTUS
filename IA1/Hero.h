#ifndef HERO_H_
#define HERO_H_

#define SCREEN_W 1600
#define SCREEN_H 600

#define Hero_WIDTH 100
#define Hero_HEIGHT 100 

#include "background.h"
#include <SDL/SDL_mixer.h>

typedef struct {
SDL_Surface *personnage;
SDL_Rect poshero;
SDL_Rect posimage;

int vie;

}Hero; 


void loadHero(Hero *H);
void initialiser_hero(Hero *H);
void blithero(Hero H,SDL_Surface *screen);
void animateheroR(Hero *H); 
void animateheroL(Hero *H); 
void MoveheroR(Hero *H,Background *back);
void MoveheroL(Hero *H,Background *back);
void Hero_Vie(Hero* H,int *collision);
void free_Hero(Hero *H);
void attackR(Hero *H);
void attackL(Hero *H);

#endif
