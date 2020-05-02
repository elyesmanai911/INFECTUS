#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED


#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
typedef struct Vie {
	int hp;
	int score;
	SDL_Surface *bar, *msg;
	SDL_Rect r;
} Vie;

void VIE_Init(Vie *v);
void VIE_ReduireHp(Vie *v, int degat);
void VIE_AjouterHp(Vie *v, int degat);
void VIE_AjouterScore(Vie *v, int score);
void VIE_Render(Vie *v,SDL_Surface **screen);
void VIE_RenderFont(Vie *vie, int x, int y, const char* text);
typedef struct Time {
	SDL_Surface *msg,*txt;
	TTF_Font *font;
	int time,score;
	SDL_Rect r;
	char timeString[10],scoreString[10];

} Time;

void initializerTemps(Time *time);
void afficherTemps(Time *time,SDL_Surface **screen);
#endif // JEU_H_INCLUDED
