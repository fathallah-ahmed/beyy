#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string.h>



struct text {
    SDL_Surface* textSurface;
    SDL_Rect positionText;
    char txt[20];
    SDL_Color couleurTxt;
    TTF_Font* police;
};
typedef struct text Text;// structure text besh tekteb l temps 

typedef struct time
{
    int tempsdebut;
    int mm; 
    int ss;
    Text temps;
    
} Time;



void inittemps(Time *t);// initialisaton lel temps l koulo 
void Timer(int *tempsdebut);// tehseb l temps 
int initTexttime(Text* T);//initialisation du text  khw eli besh nektbo bih
int loadFonttime(Text* T, char* angelina);//tloadi l font mtaa l text
void update_time(Time* T);//mise a jour du temps 
void displaytime(Time T,SDL_Surface *screen);//afficher le temps aal back
void freeTexttime(Text T);//besh ykoun fema optimisation 


#endif
