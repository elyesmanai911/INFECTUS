#include"time.h"
#include"vie.h"
/////////////////TIME//////////////////////
void initializerTemps(Time *time){
	time->font = TTF_OpenFont("theme.ttf", 32);

	sprintf(time->timeString,"TIME: 00:00:00");
	sprintf(time->scoreString,"SCORE: 0000");
	SDL_Color color = {255,255,255};
	SDL_Color color2 = {255,255,255};
	time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
	time->txt = TTF_RenderText_Solid(time->font,time->scoreString,color);
}

void afficherTemps(Time *time, SDL_Surface **screen){
	SDL_Color color = {255,255,255};
	SDL_Color color2 = {255,208,119};
	SDL_Rect r,r1;
	r.x=580;
	r.y=5;
	r1.x=1100;
	r1.y=5;
	time->time+=100;
	time->score+=2;
	if(time->time % 60 == 0){
		sprintf(time->timeString,"TIME: %02d:%02d:%02d\n",time->time/60/60/60,time->time/60/60,(time->time/60)%100);
		time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
		if((time->time /60/60 %5)==0)
		{

			sprintf(time->scoreString,"SCORE: %02d%02d\n",time->score/100,time->score%100);
		time->txt = TTF_RenderText_Solid(time->font,time->scoreString,color2);
	}}
	SDL_BlitSurface(time->msg,NULL,*screen,&r);
	SDL_BlitSurface(time->txt,NULL,*screen,&r1);
}

/////////////////VIE///////////////////
void VIE_Init(Vie *v){
	v->hp = 200;
	v->r.x = 25;
	v->r.y = 15;
	v->r.w = 225;
	v->r.h = 30;

	v->bar = SDL_CreateRGBSurface(0,225,30,32,0,0,0,0);
	SDL_FillRect(v->bar, NULL, 0x00ff00);
}

void VIE_ReduireHp(Vie *v, int degat){
	v->hp -= degat;
	v->r.w = v->hp;
}

void VIE_AjouterHp(Vie *v, int degat){
	v->hp += degat;
	if(v->hp > 200){
		v->hp = 200;
	}
	v->r.w = v->hp;
}

void VIE_Render(Vie *v, SDL_Surface **screen){
	SDL_BlitSurface(v->bar,&v->r,*screen,&v->r);
}
