#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Hero.h"

#define Ennemi_WIDTH 100
#define Ennemi_HEIGHT 100 

typedef enum STATE STATE;
enum STATE {WAITING,FOLLOWING,MOVING,ATTACKING};


typedef struct
{

SDL_Surface* image;
SDL_Rect pos_ennemi;  // Sprite
SDL_Rect positionAbsolue; // Depl
STATE state;
int directionMOV;
int direction;
int distEH;

}Ennemi;

void Load_ennemi(Ennemi* E);
void initialiserennemi(Ennemi* E);
void updateEnnemi(Ennemi* E,SDL_Rect poshero,int *distEH);
void updateEnnemiState(Ennemi* E,int disEH);
void animateEnnemi(Ennemi* E);
void blit_Ennemi(Ennemi E,SDL_Surface *screen);
void free_Ennemi(Ennemi* E);
void moveEnnemi(Ennemi* E, SDL_Rect poshero);
