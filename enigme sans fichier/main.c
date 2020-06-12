#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enig.h"

void main()
{
         SDL_Surface *screen;
         SDL_Init ( SDL_INIT_VIDEO ) ;
	 screen=SDL_SetVideoMode(1189,858,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF | SDL_FULLSCREEN );

   play_enigme(screen);
}


