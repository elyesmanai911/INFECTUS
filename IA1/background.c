#include  "background.h"
#include <SDL/SDL_image.h>

#define SCREEN_W 1600
#define SCREEN_H 600

void loadBackground(Background *Back)
{
	
        // load background
	
        Back->back_Img = IMG_Load("background.png");

	if (Back->back_Img == NULL) {
           printf("Erreuer Chargement Background Images\n");
	}


}


void initBackground(Background *Back)
{

	Back->back_Pos.x=0;
	Back->back_Pos.y=0;
	Back->back_Pos.w=SCREEN_W;
	Back->back_Pos.h=SCREEN_H;

}


void freeBackground(Background *Back)
{

 SDL_FreeSurface(Back->back_Img);

}


void blitBackground(Background*Back,SDL_Surface *screen)
{

 SDL_BlitSurface(Back->back_Img, &(Back->back_Pos), screen,NULL); 

}






