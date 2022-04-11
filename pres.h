#ifndef PERS_H_INCLUDED
#define PERS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
  	SDL_Surface *image_p;
  	SDL_Rect pos_perso;
}pers;

void initialiserperso(pers *p);
void deplacer_perso(pers *p,SDL_Event event);
void afficher_perso(SDL_Surface *screen,pers p);
void free_perso(pers p);
#endif
