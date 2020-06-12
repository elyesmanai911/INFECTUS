#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>       
#include "Hero.h"
#include "background.h"

#define Ennemi_WIDTH 100
#define Ennemi_HEIGHT 100 

void gameover(Hero h,Background *back,SDL_Surface *screen)
{
SDL_Surface *gameover;
SDL_Rect *posover;
posover->x=0;
posover->y=0;

gameover=IMG_Load("gameover.png");

if(gameover==NULL)
    {
        printf("Unable to load on gameover: %s\n",SDL_GetError());
        
    }

if (h.vie==0) {SDL_BlitSurface(gameover,&(back->back_Pos),screen,NULL); printf("met");}

} 


void loadHero(Hero *H)
{

H->personnage=IMG_Load("Hero.png");

if(H->personnage==NULL)
    {
        printf("Unable to load on H->personnage: %s\n",SDL_GetError());
        
    }


}


void initialiser_hero(Hero *H)
{

H->posimage.x=0;
H->posimage.y= 385;
H->posimage.w=Hero_WIDTH;
H->posimage.h=Hero_HEIGHT;

H->poshero.x=0;
H->poshero.y=0;
H->poshero.w=Hero_WIDTH;
H->poshero.h=Hero_HEIGHT;

H->vie=100;

}


void blithero(Hero H,SDL_Surface *screen)
{

  if (H.vie!=0)
  SDL_BlitSurface(H.personnage,&H.poshero,screen,&H.posimage);

}


void animateheroR(Hero *H)
{
H->poshero.x+=Hero_WIDTH;
H->poshero.x=H->poshero.x % (Hero_WIDTH *4);
H->poshero.y=0;
}


void animateheroL(Hero *H)
{
H->poshero.x+=Hero_WIDTH;
H->poshero.x=H->poshero.x % (Hero_WIDTH *4);
H->poshero.y=Hero_HEIGHT;
}


void attackR(Hero *H)
{
H->poshero.x+=Hero_WIDTH;
H->poshero.x=H->poshero.x % (Hero_WIDTH *4);
H->poshero.y=200;
}


void attackL(Hero *H)
{
H->poshero.x+=Hero_WIDTH;
H->poshero.x=H->poshero.x % (Hero_WIDTH *4);
H->poshero.y=300;
}

void MoveheroR(Hero *H,Background *back)
{

H->posimage.x+=25;

}


void MoveheroL(Hero *H,Background *back)
{

H->posimage.x-=25;

}


void Hero_Vie(Hero* H,int *collision)
{
	if(*collision)
	   if(H->vie > 0)
	      H->vie --;

}



void free_Hero(Hero *H)
{

 SDL_FreeSurface(H->personnage);

}
