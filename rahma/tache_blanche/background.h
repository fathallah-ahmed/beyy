#ifndef background_h
#define background_h
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
//taille de camera 1
#define SCREEN_W 1166
#define SCREEN_H 425
//taille de camera 2
#define SCREEN_W2 583
#define SCREEN_H2 425

typedef struct{
	SDL_Surface *imgback; 		//image de background
	SDL_Surface *imgbackm; 	//image de background masque
	SDL_Rect posback; 		//position de background 1
	SDL_Rect posbackm; 		//position de background masque 1
	SDL_Rect posback1;		//position de background 2
	SDL_Rect posbackm1;		//position de background masque 2
	SDL_Rect camera; 		//position de camera
	SDL_Rect camera1; 		//position de camera
	Mix_Music *son; 		//le son a jouer
}background;

void initBack (background *b);
void initBack1 (background *b);
void afficheBack (background b,SDL_Surface *ecran);
void afficheBack1 (background b,SDL_Surface *ecran);
void scrolling (background *b,int direction);
SDL_Color getpixel(SDL_Surface *pSurface,int x,int y);
//int  collisionpp(SDL_Surface *psurface,personnage p);
void liberer(background b);
#endif
