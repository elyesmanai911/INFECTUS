#include "background.h"
#include  "text.h"


/**
* @brief Load Background Back.
* @param back le background
* @return Rien
*/

void loadBackground(Background *Back)
{
	
        // load background
	
        Back->back_Img = SDL_LoadBMP("../source/background.bmp");

	if (Back->back_Img == NULL) {
           printf("Erreuer Chargement Background Images\n");
	}


	Back->back_Img2 = SDL_LoadBMP("../source/background.bmp");

	if (Back->back_Img2 == NULL) {
            printf("Erreuer Chargement Background Images\n");
	}

}


/**
* @brief initialiser Background Back.
* @param back le background
* @return Rien
*/


void initBackground(Background *Back)
{

	Back->back_Pos.x=0;
	Back->back_Pos.y=0;
	Back->back_Pos.w=SCREEN_W;
	Back->back_Pos.h=SCREEN_H;

}

/**
* @brief Afficher le background back .
* @param scren the screen
* @param back the background
* @return rien
*/

void blitBackground(Background*Back,SDL_Surface *screen)
{

	if(Back->back_Pos.x>Back->back_Img->w-SCREEN_W)

		Back->back_Pos.x=0;
	
        if(Back->back_Pos.x<0)

		Back->back_Pos.x=Back->back_Img->w-SCREEN_W;

	SDL_BlitSurface(Back->back_Img, &(Back->back_Pos), screen,NULL); 


}


/**
* @brief Liberer la surface 
* @param back the background
* @return rien
*/

void freeBackground(Background *Back)
{

 SDL_FreeSurface(Back->back_Img);

}



