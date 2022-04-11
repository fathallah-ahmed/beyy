#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>

typedef struct
{
SDL_Surface *spritesheet;
SDL_Rect posennemi;
SDL_Rect possprite;//frame
int direction;
int posMin,posMax;
//int posMiny,posMaxy;
}Ennemi;

typedef struct
{
SDL_Surface *sprite_perso;
SDL_Rect posperso;
SDL_Rect possprite_perso;
int direction_perso;
char number[20]; 
SDL_Rect position_textee;
SDL_Rect position_number;  
int valeur_score;
} personne ;

// les fonctions associées à l'ennemi 
void init_Ennemi(Ennemi*e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi *e);
void deplacer( Ennemi *e);
int collisionBB( personne p, Ennemi e);
void deplacerIA( Ennemi * e, SDL_Rect posperso );



// les fonction associées au personnage
void init_personnage(personne* p);
void afficher_personnage(personne p, SDL_Surface * screen); 


