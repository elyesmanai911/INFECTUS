#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "text.h"


void initText(Text *T)
{       
  T->text_Vie=NULL;
  T->text_distEH=NULL;
}


void loadFont(TTF_Font **police1,TTF_Font **police2)
{
	
        if(TTF_Init() == -1) {
	 
          printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
	
        }

	*police1 = TTF_OpenFont("police1.ttf",50);


        if(TTF_Init() == -1) {
	 
          printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
	
        }

	*police2 = TTF_OpenFont("police2.ttf",30);
	
}


void Afficher_Text(TTF_Font *police1,TTF_Font *police2,Text *T,SDL_Surface *screen,Hero H,int distEH)
{

	SDL_Color couleur =  {0, 0, 0};
	SDL_Color couleurShadow = {255,255,255};
	SDL_Color couleurRouge = {255, 180 , 0};

	SDL_Rect  pos_Text_Vie;
        SDL_Rect  pos_Text_distEH;

	pos_Text_Vie.x=10;
	pos_Text_Vie.y=50;
        
	pos_Text_distEH.x=850;
	pos_Text_distEH.y=50;

	char Vie[50];
        char Distance[50];

	//Vie Hero
	sprintf(Vie,"*** HERO VIE = %d ***",H.vie);
        
	T->text_Vie = TTF_RenderText_Shaded(police1,Vie,couleur,couleurShadow);
	SDL_SetColorKey(T->text_Vie, SDL_SRCCOLORKEY, SDL_MapRGB(T->text_Vie->format,255,255,255));


	//Distance Hero/Ennemi
        if (H.vie!=0)
        {
	sprintf(Distance,"*** DISTANCE = %d ***",distEH);
        
	T->text_distEH = TTF_RenderText_Shaded(police2,Distance,couleurRouge,couleurShadow);
	SDL_SetColorKey(T->text_distEH, SDL_SRCCOLORKEY, SDL_MapRGB(T->text_distEH->format,255,255,255));
        }else  {
	sprintf(Distance,"*** DISTANCE = %d ***",0);
        
	T->text_distEH = TTF_RenderText_Shaded(police2,Distance,couleurRouge,couleurShadow);
	SDL_SetColorKey(T->text_distEH, SDL_SRCCOLORKEY, SDL_MapRGB(T->text_distEH->format,255,255,255));
        } 

	//Blit
	SDL_BlitSurface(T->text_Vie,NULL,screen,&pos_Text_Vie);
        SDL_BlitSurface(T->text_distEH,NULL,screen,&pos_Text_distEH);

}


void freeFont(TTF_Font **police)
{

	TTF_CloseFont(*police); 
        TTF_Quit();	

}

