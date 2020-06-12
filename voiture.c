#include <SDL/SDL.h>
#include <stdio.h>
#include "voiture.h"
#include "background.h"
#include "text.h"

/**
* @brief Load Voiture A
* @param A la voiture
* @return Rien
*/

void loadVoitureImages (Voiture * A)
{
	int i;
	char buf[50];
	char buf0[]="../source/voiture";
	char bmp[]=".bmp";
	for(i=0; i<4; i++)
        {
		sprintf(buf,"%s%d%s",buf0,i,bmp);
		A->image[i] = SDL_LoadBMP(buf);
		if (A->image[i]== NULL) 
                {
			printf("Unable to load  Voiture bitmap: %s\n", SDL_GetError());
		}
		// set the color of Voiture background (white color) as transparent
		SDL_SetColorKey( A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 255, 255, 255) );
	}

}

/**
* @brief initialiser Voiture A.
* @param A la voiture
* @return Rien
*/

void initVoiture(Voiture *A)
{
	A->direction=0;
	A->position.x=0;
	A->position.y=SCREEN_H - A->image[0]->h;
	A->position.w=A->image[0]->w;
	A->position.h=A->image[0]->h;
	A->vitesse=5; 
	A->acceleration=0;
	A->Mass=70;
	A->move=0;
}

/**
* @brief Mouvement Voiture A.
* @param A la voiture
* @param B the background
* @param dt variation dt
* @return Rien
*/


void moveVoiture(Voiture *A,Background *B, Uint32 dt)
{
	A->vitesse+=0.5*A->acceleration*dt;
	B->back_Pos.x+=A->vitesse*dt;
}


/**
* @brief Liberer la surface 
* @param A la voiture
* @return rien
*/

void freeVoiture(Voiture *A)
{
	int i;
	for(i=0; i<4; i++)
		SDL_FreeSurface(A->image[i]);
}




