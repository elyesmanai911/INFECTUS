
/**
* @struct Text
* @brief struct for Text
*/


/**
* @struct Time
* @brief struct for Time
*/


#ifndef TEXT_H
#define TEXT_H
#define FPS 60
#define ACCELX 0
#define ACCELY 0
#define SCREEN_W 1000
#define SCREEN_H 400

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "voiture.h"
#include "background.h"


typedef struct{
        SDL_Surface *textDt; /*!< Surface. */
	SDL_Surface *text_Position; /*!< Surface. */
	SDL_Surface *text_Vitesse; /*!< Surface. */
	SDL_Surface *text_Acceleration; /*!< Surface. */
}Text;


typedef struct{
	SDL_Surface *msg; /*!< Surface. */
	TTF_Font *font; /*!< Police. */
	int temps;
	char timeString[10];
} Time;


void  initText(Text *T);
void  initTemps(Time *time);
void  loadFont(TTF_Font **police);
void  Afficher_Text(TTF_Font *police , Text *T , SDL_Surface *screen , Voiture V , Background Back , Time *time, Uint32 dt);
void  freeFont(TTF_Font **police);

#endif
