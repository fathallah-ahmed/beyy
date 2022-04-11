#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h> 
#include"ennemi.h"


int main(int argc, char* argv[])
{
 TTF_Init();
TTF_Font *police=NULL;//déclaration
SDL_Surface *number1=NULL;
Ennemi e;
personne p;

SDL_Surface *screen=NULL,*arriere_plan=NULL;
SDL_Rect pos_arriere_plan;
pos_arriere_plan.x=0;//plein écran
pos_arriere_plan.y=0;

SDL_Event event;
int continuer = 1;

SDL_Init(SDL_INIT_VIDEO);    
screen =SDL_SetVideoMode(1024,760,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);//lancement de fenétre

arriere_plan= IMG_Load("background.png");
	
	init_Ennemi(&e);  
        init_personnage(&p); //initialiser le personnage

////--------gestion de score-----//
police = TTF_OpenFont("avocado.ttf", 35);
SDL_Color noir={0,0,0}; 
p.number[20];
p.valeur_score=2000;
sprintf(p.number, "%d",(p.valeur_score));//concersion d'un entier en chaine de caractére

number1=TTF_RenderText_Blended(police,p.number,noir);


p.position_number.x=0;
p.position_number.y=20;

  int co=0;//detéction de changement de score
   while (continuer) 
   {
   	
	//SDL_BlitSurface(arriere_plan, NULL, screen,&pos_arriere_plan);
        afficher_personnage(p,screen);
	afficherEnnemi(e,screen);
//tester la collision
         
             if(collisionBB(p,e))
             {
                if(co==0)
                {
                p.valeur_score=p.valeur_score-10;
               sprintf(p.number, "%d",(p.valeur_score));
            number1= TTF_RenderText_Blended(police,p.number,noir);
            //printf("%d",p.valeur_score);
            }
             e.posennemi.x=p.posperso.x+100;//ya7bss 9odemou 
               
         co=1;   
          }
           
         
        while (SDL_PollEvent(&event)); 
       {
         
       switch(event.type) 

        {

           case SDL_QUIT: 

               continuer = 0; //yo5rej ml fenétre

               break;

        }

      }
     deplacer(&e);
     animerEnnemi(&e);

     SDL_Delay(80);//attente
  
    SDL_BlitSurface(arriere_plan, NULL, screen,&pos_arriere_plan);
    SDL_BlitSurface(number1, NULL,screen,&p.position_number);
    SDL_Flip(screen);
   }
SDL_FreeSurface(e.spritesheet);
SDL_FreeSurface(p.sprite_perso);
SDL_FreeSurface(number1);
SDL_Flip(screen);
TTF_CloseFont(police);
TTF_Quit();
SDL_Quit(); // Arrêt de la SDL (libération de la mémoire).


 return EXIT_SUCCESS;  // Fermeture du programme
}

