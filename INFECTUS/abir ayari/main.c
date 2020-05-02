#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<stdio.h>
#include<SDL/SDL_image.h>
#include<stdlib.h>
#include<time.h>
#include"quiz.h"

const char* getQuestion(Question *t,int q){
	// this fucntion return the answer for the selected qurstion based on the choice
	//example: getQuestion(&q.questions[qid],choices[0]), q is the quiz, t = &q.questions[qid], choices[0]: the choice
	if(q==0)
		return t->reponse1;
	if(q==1)
		return t->reponse2;
	return t->reponse3;
} 

int main(int argc, char *argv[]) {


	int running = 1;

	int currentChoice = 0;
	srand(time(NULL));
	int qid = (int)(random()%5);
	int choices[3] = {0,1,2};
	for(int i = 0; i<10; i++){
		int t = random()%3; //2
		int t2 = random()%3; //0
		int t3 = choices[t]; //t3 = 2 
		choices[t] = choices[t2];// choices : 0,1,0
		choices[t2] = t3; // choices : 2,1,0
	}
	
	printf("%d %d %d\n",choices[0],choices[1],choices[2]);
	
	Quiz q;
	QUIZ_Init(&q,"./questions.txt");//fill quiz with 5 questions

	SDL_Surface *screen=NULL, *background=NULL , *msg, *arrow;
	TTF_Font *font = NULL;
        SDL_Rect positionbackground;
        positionbackground.x=0;
        positionbackground.y=0;
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	
	screen = SDL_SetVideoMode(1200,600,32,SDL_HWSURFACE);
        SDL_WM_SetCaption("chargement en cours",NULL);
	SDL_Event event;
        
        background=SDL_LoadBMP("moon.bmp");
        SDL_BlitSurface(background,NULL,screen,&positionbackground);



	font = TTF_OpenFont("font.ttf", 24);

	SDL_Color color = {243,114,32};
        SDL_Color color1 = {0,255,0};
        SDL_Color color2 = {255,0,0};
        
	SDL_Rect rect;
	SDL_Rect choice;
        
	choice.x = 150;
	choice.y = 50;

	arrow = SDL_CreateRGBSurface(0,16,16,32,0,0,0,0);
	SDL_FillRect(arrow,NULL,SDL_MapRGB(arrow->format,255,255,255));

	SDL_EnableKeyRepeat(0,0); //0 disables key repeating completely
	
	while(running) {
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
					running = 0;
			}
			if(event.type == SDL_KEYDOWN){
				if(event.key.keysym.sym == SDLK_ESCAPE){
					running = 0;
				}
				if(event.key.keysym.sym == SDLK_DOWN){
					if(currentChoice != 2)
						currentChoice++;
					else 
						currentChoice = 0;	
				}
				if(event.key.keysym.sym == SDLK_UP){
					if(currentChoice != 0)
						currentChoice--;
					else 
						currentChoice = 2;	
				}
				if(event.key.keysym.sym == SDLK_RETURN){
					if(choices[currentChoice] == 0){
						running = 0;
						SDL_Rect t;
						t.x = 300;
						t.y = 400;
						msg = TTF_RenderText_Solid(font, "GOOD JOB, your answer is right ^_^ " , color1);
						SDL_BlitSurface(msg,NULL,screen,&t);
						SDL_Flip(screen);
						SDL_Delay(1000);
					}
					else {
						running = 0;
						SDL_Rect t;
						t.x = 300;
						t.y = 400;
						msg = TTF_RenderText_Solid(font, "OUPS! your answer is incorrect x_x !  " , color2);
						SDL_BlitSurface(msg,NULL,screen,&t);
						SDL_Flip(screen);
						SDL_Delay(1000);
					}
				}
			}
		}

	SDL_FillRect(screen,&screen->clip_rect,0x000000);
			
	rect.x = 200;
	rect.y =100;
        SDL_BlitSurface(background,NULL,screen,&positionbackground);
	msg = TTF_RenderText_Solid(font, q.questions[qid].question , color);//qid is the id of the question (randomly chosen)
	//q.questions[qid] : gets the Question from the list of 5 question in Quiz q  
	//q.questions[qid].question: gets the question statement by its id
	SDL_BlitSurface(msg,NULL,screen,&rect);

	rect.y = 200+50*0;
	msg = TTF_RenderText_Solid(font, getQuestion(&q.questions[qid],choices[0]) , color);
	SDL_BlitSurface(msg,NULL,screen,&rect);
	
	rect.y = 200+50*1;
	msg = TTF_RenderText_Solid(font, getQuestion(&q.questions[qid],choices[1]) , color);
	SDL_BlitSurface(msg,NULL,screen,&rect);

	rect.y = 200+50*2;
	msg = TTF_RenderText_Solid(font, getQuestion(&q.questions[qid],choices[2]), color);
	SDL_BlitSurface(msg,NULL,screen,&rect);
	choice.y =200+currentChoice*50;
        
	SDL_BlitSurface(arrow,NULL,screen,&choice);
               


	SDL_Flip(screen);
		SDL_Delay(16);
	}


	SDL_FreeSurface(screen);
        SDL_FreeSurface(background);
	SDL_FreeSurface(msg);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();

}
