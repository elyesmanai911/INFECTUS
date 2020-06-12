#include "text.h"

/**
* @brief initialiser Text T.
* @param T le Text
* @return Rien
*/


void initText(Text *T)
{       
        T->textDt=NULL;
	T->text_Position=NULL;
	T->text_Vitesse=NULL;
	T->text_Acceleration=NULL;
}

/**
* @brief initialiser Time time.
* @param time le Time
* @return Rien
*/

void initTemps(Time *time){
	
        time->msg=NULL;
        time->font = TTF_OpenFont("../source/font_temps.ttf",32);
	time->temps = 0;
	sprintf(time->timeString,"00:00");
	SDL_Color color = {0,0,0};
	time->msg = TTF_RenderText_Blended(time->font,time->timeString,color);
}

/**
* @brief Load Font
* @param police le font
* @return Rien
*/

void loadFont(TTF_Font **police)
{
	
        if(TTF_Init() == -1) {
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
	}

	*police = TTF_OpenFont("../source/police.ttf",22);
	
}

/**
* @brief Afficher tout les text .
* @param scren the screen
* @param back the background
* @param time le Time
* @param police le font
* @param T le Text
* @param dt variation dt
* @return rien
*/

void Afficher_Text(TTF_Font *police , Text *T , SDL_Surface *screen , Voiture V , Background Back , Time *time, Uint32 dt)
{

	SDL_Color couleurRouge = {255, 0, 0};
	SDL_Color couleurNoir = {0,0,0};
	
        SDL_Rect  pos_Text_Pos;
	SDL_Rect  pos_Text_Vitesse;
	SDL_Rect  pos_Text_Acceleration;
        SDL_Rect  pos_Text_Dt;
         
	pos_Text_Pos.x=SCREEN_W-280;
	pos_Text_Vitesse.x=SCREEN_W-280;
	pos_Text_Acceleration.x=SCREEN_W-280;
        pos_Text_Dt.x=SCREEN_W-280;

	pos_Text_Pos.y=50;
	pos_Text_Vitesse.y=80;
	pos_Text_Acceleration.y=110;
        pos_Text_Dt.y=20;
        
        char DT[50];
	char vitesse[50];
	char acceleration[50];
	char position[50];

        //Temps
        time->temps++;
	if(time->temps % 60 == 0){

	sprintf(time->timeString,"%02d:%02d\n",time->temps/60/60,(time->temps/60)%60);
	time->msg = TTF_RenderText_Blended(time->font,time->timeString,couleurNoir);
	SDL_SetColorKey(time->msg, SDL_SRCCOLORKEY, SDL_MapRGB(time->msg->format, 255, 255, 255));}

	//dt
	sprintf(DT,"dt= %d ms",dt);
	T->textDt = TTF_RenderText_Blended(police,DT,couleurRouge);
	SDL_SetColorKey(T->textDt, SDL_SRCCOLORKEY, SDL_MapRGB(T->textDt->format, 255, 255, 255));


	//position
	sprintf(position,"Pos x=%d pixels",Back.back_Pos.x);
	T->text_Position = TTF_RenderText_Blended(police,position,couleurRouge);
	SDL_SetColorKey(T->text_Position, SDL_SRCCOLORKEY, SDL_MapRGB(T->text_Position->format, 255, 255, 255));
	
        //vitesse
	sprintf(vitesse,"vitesse= %.6f km/h",V.vitesse);
	T->text_Vitesse = TTF_RenderText_Blended(police,vitesse,couleurRouge);
	SDL_SetColorKey(T->text_Vitesse, SDL_SRCCOLORKEY, SDL_MapRGB(T->text_Vitesse->format, 255, 255, 255));


	//acceleration
	sprintf(acceleration,"Acceleration= %.6f m/s/s",V.acceleration);
	T->text_Acceleration = TTF_RenderText_Blended(police,acceleration,couleurRouge);
	SDL_SetColorKey(T->text_Acceleration, SDL_SRCCOLORKEY, SDL_MapRGB(T->text_Acceleration->format, 255, 255, 255));
        

	//Blit
        SDL_BlitSurface(time->msg,NULL,screen,NULL);
        SDL_BlitSurface(T->textDt,NULL,screen,&pos_Text_Dt);
	SDL_BlitSurface(T->text_Position,NULL,screen,&pos_Text_Pos);
	SDL_BlitSurface(T->text_Vitesse,NULL,screen,&pos_Text_Vitesse);
	SDL_BlitSurface(T->text_Acceleration,NULL,screen,&pos_Text_Acceleration);

}

/**
* @brief Liberer la surface 
* @param police le font
* @return rien
*/

void freeFont(TTF_Font **police)
{

	TTF_CloseFont(*police); 
        TTF_Quit();	

}

