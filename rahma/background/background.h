#ifndef background_h
#define background_h
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
//taille de l'encran
#define SCREEN_W 1166
#define SCREEN_H 425

typedef struct{
	SDL_Surface *imgback; 		//image de background
	SDL_Surface *imgbackm; 	//image de background masque
	SDL_Surface *anim1[10]; 	//tableau des image de l'animation 1
	SDL_Surface *anim2[10];	//tableau des image de l'animation 2
	SDL_Rect posback; 		//position de background
	SDL_Rect posbackm; 		//position de background masque
	SDL_Rect posanim1; 		//position de l'animation 1
	SDL_Rect posanim2; 		//position de l'animation 2
	int num1; 			//numero de l'image de l'animation 1
	int num2; 			//numero de l'image de l'animation 2
	SDL_Rect camera; 		//position de camera
	Mix_Music *son; 		//le son a jouer
}background;

void initBack (background *b); 
void afficheBack (background b,SDL_Surface *ecran); 
void scrolling (background *b,int direction); 
void animerbackground(background *b,SDL_Surface *ecran); 
SDL_Color getpixel(SDL_Surface *pSurface,int x,int y); 
//int  collisionpp(SDL_Surface *psurface,personnage p);
void liberer(background b);
#endif
