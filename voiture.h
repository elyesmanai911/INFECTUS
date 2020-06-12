/**
* @struct Voiture
* @brief struct for Voiture
*/

#ifndef Voiture_H
#define Voiture_H
#include "background.h"

typedef struct {

	SDL_Rect position; /*!< Rectangle*/
	SDL_Surface * image[5]; /*!< Surface. */
	
	int direction; //0:right 1:left 2:up
	int move; //0:not moving 1:moving
	float Mass;

	double vitesse;
	double acceleration;

}Voiture;

void loadVoitureImages(Voiture * A);

void initVoiture(Voiture *A);

void moveVoiture(Voiture *A,Background *B,Uint32 dt);

void freeVoiture(Voiture *A);

#endif
