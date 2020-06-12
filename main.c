/**
* @file main.c
* @brief Tester programme
* @author seif trabelsi
* @version 1.0
* @date Juin 07, 2020
*
* Tester programme pour Vitesse Acceleration
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "voiture.h"
#include "text.h"

int main (void)
{

        SDL_Surface *screen;
        Mix_Music *music;
        Mix_Chunk *son;

        int done = 0;
	int i=0;
	int keysHeld[323] = {0}; // everything will be initialized to false
	Uint32 t_prev,dt=1;

        SDL_Event event;
	TTF_Font *police = NULL;
	
        // Déclaration Structure 
        Voiture car;
	Background Back;
	Text txt;
        Time time;
         

        // INIT_VIDEO
        if(SDL_Init(SDL_INIT_VIDEO)!=0)
        {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
        }


        // Creation screen

        screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
        if(screen==NULL)
        {
                printf("Unable to set video mode : %s",SDL_GetError());
                return 1;
        }


        //music

        if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
        {printf("%s",Mix_GetError());}


        music=Mix_LoadMUS("../source/music.mp3");
        //Mix_PlayMusic(music,-1);

        //son bref
        son = Mix_LoadWAV("../source/son.wav");


        // Load
	loadVoitureImages(&car);
	loadBackground(&Back);	
	loadFont(&police);


        // Initialisation      
	initBackground(&Back);
	initVoiture(&car);
	initText(&txt);
        initTemps(&time);


	// program Game loop
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
	
            while(!done) {	
             t_prev = SDL_GetTicks(); //au début de la game loop
              if(car.vitesse>0)
                {       //when moving
			car.acceleration=-0.001; //frottement + vent
			i+=1;
			car.move=1;
		}

		if(car.vitesse <0) {
			car.acceleration=0;
			car.vitesse=0;
			car.move=0;
		}
		while (SDL_PollEvent(&event)) 
                    {
			
			switch (event.type) {
				
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				keysHeld[event.key.keysym.sym] = 1;
				break;
			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
				break;
			}
			// exit if ESCAPE is pressed
			if (keysHeld[SDLK_ESCAPE])
				done = 1;
			if(keysHeld[SDLK_RIGHT]) 
                        {
                                car.acceleration+=0.005;
				
			}
                        
                        if  (keysHeld[SDLK_LEFT])
                        {
                                car.acceleration-=0.001; //Mix_PlayChannel(-1, son, 0);
				
			}
                        

		} 

		i=i%4;
		

		//Blit Voiture et Background
		if(!car.move)
			i=0;
                blitBackground(&Back,screen);
                moveVoiture(&car,&Back,dt);
		SDL_BlitSurface(car.image[i],NULL,screen,&car.position);

                Afficher_Text(police,&txt,screen,car,Back,&time,dt);

		SDL_Flip(screen);


		dt=SDL_GetTicks()-t_prev; //à la fin de la game loop
                if(1000/FPS > dt)
                SDL_Delay(1000/FPS - dt); //pour avoir un FPS constant
		
		
	}

	                

	freeVoiture(&car);
	freeBackground(&Back);
	freeFont(&police);

	return 0;

}



