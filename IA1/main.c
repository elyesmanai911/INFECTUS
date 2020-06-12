#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_image.h"
#include "background.h"
#include "Hero.h"
#include "ennemi.h"
#include "text.h"

int main (void)
{
        
        SDL_Surface *screen;
        SDL_Surface *over;
        SDL_Rect position_over;
   

        int done = 0; 
        int coll;
        int distEH;
	int i=0;
	int keysHeld[323] = {0}; // everything will be initialized to false
  
        SDL_Event event;
        TTF_Font *police1 = NULL;
        TTF_Font *police2 = NULL;
        

        // Déclaration Structure ;
        Hero H; 
        Background Back;
        Ennemi E;
        Text txt;

        // Load
        loadHero(&H);
        loadBackground(&Back);
        Load_ennemi(&E);
        loadFont(&police1,&police2);

        // Initialisation      
        initBackground(&Back);
        initialiser_hero(&H);
        initialiserennemi(&E);
        initText(&txt);

        // INIT_VIDEO
        if(SDL_Init(SDL_INIT_VIDEO)!=0)
        {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
        }


        // Creation screen

        screen=SDL_SetVideoMode(1600,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
        if(screen==NULL)
        {
                printf("Unable to set video mode : %s",SDL_GetError());
                return 1;
        }
        
        // game over
     
        over=IMG_Load("gameover.png");
        if(over==NULL)
        {
        printf("Unable to load over: %s\n",SDL_GetError());
        return 1;
        }
        position_over.x=500;
        position_over.y=40;

        // program Game loop
	 SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
	   
            while(!done) {

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
    
                             MoveheroR(&H,&Back); // Move Right
                             animateheroR(&H);
			}
                        
                        if  (keysHeld[SDLK_LEFT])
                        {    

                             MoveheroL(&H,&Back); // Move Left
                             animateheroL(&H);
                             
			}

               
                        if(keysHeld[SDLK_a]) 
                        {    
    
                             MoveheroR(&H,&Back); // attack right
                             attackR(&H);
			}
                        
                        if  (keysHeld[SDLK_z])
                        {    

                             MoveheroL(&H,&Back); // attack Left
                             attackL(&H);
                             
			}               

		}

                //update l'etat de collision hero/ennemi
                coll=((H.posimage.x+Hero_WIDTH) >= E.positionAbsolue.x) &&(H.posimage.x <= (E.positionAbsolue.x +Ennemi_WIDTH));

                Hero_Vie(&H,&coll);
                updateEnnemi(&E,H.posimage,&distEH);                        
		//Blit Hero et Background et Ennemi et Text
                
                blitBackground(&Back,screen);
                if (H.vie==0) {SDL_BlitSurface(over, &(Back.back_Pos), screen,&position_over);}
                blithero(H,screen);
                if (H.vie!=0) {blit_Ennemi(E,screen);}
                Afficher_Text(police1,police2,&txt,screen,H,distEH); 
		SDL_Flip(screen);
		

	}

	// Liberation memoire
      
	freeBackground(&Back);
        free_Hero(&H);
        free_Ennemi(&E);
        freeFont(&police1);
        freeFont(&police2);

	return 0;

}



