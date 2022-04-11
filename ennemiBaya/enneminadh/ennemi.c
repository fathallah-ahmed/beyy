#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<time.h> 
#include"ennemi.h"
#include <math.h> 
 

const int LARGEUR_SPRITE= 400;
const int HAUTEUR_SPRITE= 400;

void init_Ennemi(Ennemi*e)
{
const int A=60,B=700,C=200,D=400;
e->posMin=60;
e->posMax=700;//identification de la ligne de déplacement horizontale
// e->posMiny=200;//identification de la ligne de déplacement verticale
// e->posMaxy=400;

/*srand(time(NULL));//initialiser le générateur pseudo-aléatoire
e->posennemi.x=(rand() % (B - A )) +A ;//Borner les x et les y(mur qui détermine le champs de mouvement)
e->posennemi.x=(rand() % (D- C)) +C;*/


e->spritesheet = IMG_Load("spritesheet ennemi.png"); //chargement du sprite sheet

//les posisiton de l'ennemi sur l'écran
e->posennemi.y=50;
e->posennemi.x=300;

//le clip initial
e->possprite.x=0;
e->possprite.y=200;//ligne droite
e->possprite.w=100;//atelier animation
e->possprite.h=100;

//la direction initial
e->direction=2;//initialement direction droite

}

void afficherEnnemi(Ennemi e, SDL_Surface* screen)
{
SDL_BlitSurface( e.spritesheet , &e.possprite , screen , &e.posennemi );//tlasa9 surface 3l écran
SDL_Flip(screen);//mise à jour
}
void animerEnnemi( Ennemi * e)
{
e->possprite.y=e->direction*100;//se positionner dans la ligne qui correspond à la direction

if(e->possprite.x == LARGEUR_SPRITE-100) 
   e->possprite.x=0; //animation continue(first frame)
else
   e->possprite.x += 100; //passage interframes
}

void deplacer( Ennemi * e)
{
int i;
if( e->posennemi.x > e->posMax)//s'il atteint la posmax il revient à gauche
 e->direction = 1;//gouche
if( e->posennemi.x < e->posMin)//s'il atteint la posmax il revient à droite
 e->direction = 2;//droite

/*
if( e->posennemi.y > e->posMaxy )//s'il atteint la posmaxy il revient en haut
 e->direction = 3;//haut
if( e->posennemi.y < e->posMiny )//s'il atteint la posmax il revient en bas
 e->direction = 0;//bas
*/
//for (i=0;i<4;i++)
//{
/*if( e->direction == 0)//bas
  e->posennemi.y+=10; //mouvement avec vitesse
else if ( e->direction == 3)//haut
  e->posennemi.y-=10;*/
 if( e->direction == 2)//droite
  e->posennemi.x+=10; //mouvement avec vitesse
else
  e->posennemi.x-=10;//gauche
//}
}
int collisionBB( personne p, Ennemi e) 
{
if(( (p.posperso.x + p.possprite_perso.w)< e.posennemi.x ) || (e.posennemi.x + e.possprite.w < p.posperso.x ) ||((p.posperso.y + p.possprite_perso.h)< e.posennemi.y) || (e.posennemi.y + e.possprite.h < p.posperso.y ) )
return 0;
else
return 1;

} 

void init_personnage(personne* p)
{ 

p->sprite_perso = IMG_Load("perso.png"); 

p->posperso.x=150;
p->posperso.y= 50;

//le clip à afficher
p->possprite_perso.x=0;
p->possprite_perso.y=0;
p->possprite_perso.w=100;
p->possprite_perso.h=100;

p->direction_perso=0;


}


void afficher_personnage(personne p, SDL_Surface * screen)
{
SDL_BlitSurface( p.sprite_perso , &p.possprite_perso , screen , &p.posperso );
SDL_Flip(screen);
}




// --- artificial intelegence deplacement 
void deplacerIA( Ennemi * e, SDL_Rect posperso )
{
  float distance;
  
  // calculer la distance entre deux points  d(u⃗ ,v⃗ )=∥u⃗ −v⃗ ∥= √ ( ((u1−v1)2+(u2−v2)2...(un−vn)2) ).
  distance= sqrt((( e->posennemi.x -posperso.x)*( e->posennemi.x - posperso.x))+(( e->posennemi.y- posperso.y)*( e->posennemi.y - posperso.y)) );
  
  
  if(distance <= 500 && (posperso.x + posperso.w) < e->posennemi.x )
  {
     e->posennemi.x -= 10;
      e->direction=1; // face left while moving left
      
       
      
  }
  else if ( distance <= 500 && (posperso.x + posperso.w) > (e->posennemi.x  ) )
  {
    e->posennemi.x += 10 ; 
    e->direction=2;  // face right while looking right
       
  }
  else if ( distance > 500 && (posperso.x + posperso.w) < (e->posennemi.x + e->posennemi.w ) )
  {
    e->posennemi.x = e->posennemi.x;
    e->direction=1; // face left while perso is far away in your left side
  }
    else if ( distance > 500 && (posperso.x + posperso.w) > (e->posennemi.x + e->posennemi.w ) )
  {
    e->posennemi.x = e->posennemi.x;
    e->direction=2; // face rightwhile perso is far away in your right side
  }
  


        
        // !!!! e->direction values depends on the sprite sheet photo
        
}
