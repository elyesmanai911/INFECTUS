#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Hero.h"
#include "ennemi.h"

void Load_ennemi(Ennemi* E)
{

E->image=IMG_Load("ennemi.png");

if(E->image==NULL)
{
printf("Unable to load on E->image: %s\n",SDL_GetError());        
}


}


void initialiserennemi(Ennemi* E)
{

E->state=WAITING;

// Deplacement
E->positionAbsolue.x=1500;
E->positionAbsolue.y=385;

// Sprite
E->pos_ennemi.x=0;
E->pos_ennemi.y=Ennemi_HEIGHT;

E->pos_ennemi.w=Ennemi_WIDTH;
E->pos_ennemi.h=Ennemi_HEIGHT;

E->direction=1; //A gauche
E->directionMOV=1;

}



void updateEnnemiState(Ennemi* E,int disEH) 
{

disEH=abs(disEH);

switch(E->state)
{
   
  
   case WAITING:    { if ((disEH>200)&&(disEH<=600))  { E->state=MOVING;}    break;}

   case MOVING:    {  if  ((disEH>0)&&(disEH<=200))    {E->state=ATTACKING;} break; }

   case ATTACKING: {  /*if  (disEH<=0) {E->state=WAITING;}
                      else*/ if ((disEH>200)&&(disEH<=600)) { E->state=MOVING;} break; }
}


}




void updateEnnemi(Ennemi* E,SDL_Rect poshero,int *distEH) 
{

*distEH=(E->positionAbsolue.x-(poshero.x+Hero_WIDTH));

if (poshero.x > E->positionAbsolue.x) {E->direction=2;}

else if (poshero.x < E->positionAbsolue.x) {E->direction=1;}


switch (E->state)
{

case WAITING:   animateEnnemi(E); moveEnnemi(E,poshero); break;

case MOVING:    animateEnnemi(E);  moveEnnemi(E, poshero);  break;

case ATTACKING: animateEnnemi(E);  moveEnnemi(E, poshero);  break;


}

updateEnnemiState(E,*distEH);

}


void animateEnnemi(Ennemi* E)
{ 

   switch(E->state)
   {
    
    case WAITING:{
    if (E->direction==1)
    {
    // Animation ennemi a gauche
    E->pos_ennemi.x+=Ennemi_WIDTH;
    E->pos_ennemi.x=E->pos_ennemi.x % (Ennemi_WIDTH *4);
    E->pos_ennemi.y=Ennemi_HEIGHT;}

    if (E->direction==2)
    {
    // Animation ennemi a droite
    E->pos_ennemi.x+=Ennemi_WIDTH;
    E->pos_ennemi.x=E->pos_ennemi.x % (Ennemi_WIDTH *4);
    E->pos_ennemi.y=0;}
    break;}

    case MOVING:{
   if (E->positionAbsolue.x<1000) 
    {
    E->pos_ennemi.x+=Ennemi_WIDTH;
    E->pos_ennemi.x=E->pos_ennemi.x % (Ennemi_WIDTH *4);
    E->pos_ennemi.y=0;
    }else if (E->positionAbsolue.x>1500)     
    {
    E->pos_ennemi.x+=Ennemi_WIDTH;
    E->pos_ennemi.x=E->pos_ennemi.x % (Ennemi_WIDTH *4);
    E->pos_ennemi.y=Ennemi_HEIGHT;
    }
   
 if (E->directionMOV==1)
    {
    // Animation ennemi a gauche
    E->pos_ennemi.x+=Ennemi_WIDTH;
    E->pos_ennemi.x=E->pos_ennemi.x % (Ennemi_WIDTH *4);
    E->pos_ennemi.y=Ennemi_HEIGHT;}

    else if (E->directionMOV==2)
    {
    // Animation ennemi a droite
    E->pos_ennemi.x+=Ennemi_WIDTH;
    E->pos_ennemi.x=E->pos_ennemi.x % (Ennemi_WIDTH *4);
    E->pos_ennemi.y=0;}
    break;}
    
    case ATTACKING:{
    if (E->direction==1)
    {
    // Animation ennemi a gauche
    E->pos_ennemi.x+=Ennemi_WIDTH;
    E->pos_ennemi.x=E->pos_ennemi.x % (Ennemi_WIDTH *4);
    E->pos_ennemi.y=300;}
  
    else if (E->direction==2)
    {
    // Animation ennemi a droite
    E->pos_ennemi.x+=Ennemi_WIDTH;
    E->pos_ennemi.x=E->pos_ennemi.x % (Ennemi_WIDTH *4);
    E->pos_ennemi.y=200;}
    break;}
    
  } 

}



void moveEnnemi(Ennemi* E,SDL_Rect poshero)
{

switch (E->state)
{
case WAITING: 
if (E->positionAbsolue.x<1500)
{
E->positionAbsolue.x+=2;
}else if (E->positionAbsolue.x>1500)
{
E->positionAbsolue.x-=2;
} 
break;

case MOVING:{
if (E->positionAbsolue.x<1000) {E->positionAbsolue.x+=2; E->directionMOV=2;}
else if(E->positionAbsolue.x>1500) {E->positionAbsolue.x-=2; E->directionMOV=1;}

  if ((1000 <= E->positionAbsolue.x)&&(E->positionAbsolue.x<1500)&&(E->directionMOV==2))
     {E->positionAbsolue.x+=2;}

  if (E->positionAbsolue.x==1500) {E->directionMOV=1;}
 
  if ((1000 < E->positionAbsolue.x)&&(E->positionAbsolue.x <= 1500)&&(E->directionMOV==1))
     {E->positionAbsolue.x-=2;}
 
  if (E->positionAbsolue.x==1000) {E->directionMOV=2;} 
 
break;}


case ATTACKING:{
 
if (E->direction==1) { E->positionAbsolue.x-=2; }

if (E->direction==2)  {E->positionAbsolue.x+=2;} 

break;}

}

}



void blit_Ennemi(Ennemi E,SDL_Surface *screen)
{

  SDL_BlitSurface(E.image,&E.pos_ennemi,screen,&E.positionAbsolue);

}


void free_Ennemi(Ennemi *E)
{

 SDL_FreeSurface(E->image);

}



