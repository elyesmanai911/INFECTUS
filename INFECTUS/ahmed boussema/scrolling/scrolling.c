#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"

void initialiser (SDL_Rect *positionFond,SDL_Rect *positioncir,SDL_Surface *imageDeFond ) 
{
  positionFond->x=0 ;
  positionFond->y=0 ;
 
   SDL_WM_SetCaption("scrolling", NULL);
    
        
    imageDeFond = IMG_Load("map.jpg");
    

}
void afficher (SDL_Rect *positionFond,SDL_Rect *positioncir,SDL_Surface *imageDeFond )
{
               SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
                
                SDL_Flip(ecran) ;
}

void scrolling_map ()
{
 
   
}