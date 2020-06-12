
/**
* @struct Background
* @brief struct for background
*/


#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>

typedef struct {

	SDL_Surface *back_Img; /*!< Surface. */
	SDL_Surface *back_Img2; /*!< Surface. */
	SDL_Rect back_Pos; /*!< Rectangle*/

}Background;


void  loadBackground(Background *Back);
void initBackground(Background *Back);
void freeBackground(Background *Back);
void blitBackground(Background *Back,SDL_Surface *screen);

#endif
