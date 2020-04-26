#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include"dep.h"


int main(){
	SDL_Surface *screen;
	SDL_Event e;
SDL_Rect position_player;
	screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
//background
      SDL_Surface* backg = NULL;
       backg = IMG_Load("background.png");
SDL_BlitSurface(backg, NULL, screen, NULL);
SDL_Flip(screen);
//
	guard c;
	initial(&c,350,380);
	

	int running = 1;

	while(running){
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE){
				running = 0;
			}
		}

		SDL_FillRect(screen,NULL,0x000000);
                      collide(&position_player,&c);
                   SDL_BlitSurface(backg, NULL, screen, NULL);//background
		aff(&c,&screen);

		SDL_Delay(16);
		SDL_Flip(screen);
	}	
	SDL_Quit();
}
