#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player.h"


int main(int argc, char *argv[])
{
	int continuer=1;
	int player=0;
	int posinit=0;
	int i;
	int dt=20;
	SDL_Event event;
	Personne p,p2;
	Background background;
	const int FPS = 30;
    Uint32 start;
	
	SDL_Surface *ecran=NULL;
	
	initPerso(&p);

	background.posback.x=0;
	background.posback.y=0;
	
	background.imageFond=IMG_Load("background.jpg");
	
	SDL_Init(SDL_INIT_VIDEO);
	
	ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("l'bey",NULL);
	
	afficher_Background (background, ecran);
	afficherPerso(p, ecran);
	SDL_Flip(ecran);

	SDL_EnableKeyRepeat(20,20);

	while(continuer)
	{
	SDL_PollEvent(&event);
	switch(event.type)
	{
	case SDL_QUIT:
		continuer=0;
		break;
	case SDL_KEYDOWN:
	switch(event.key.keysym.sym)
	{
	case SDLK_UP:
		p.mov=3;
		deplacerPerso(&p, ecran);
		animerPerso(&p, ecran);
		afficher_Background (background, ecran);
		afficherPerso(p, ecran);
		if (player==1)
			afficherPerso(p2, ecran);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		break;

	case SDLK_DOWN:
		p.mov=4;
		deplacerPerso(&p, ecran);
		animerPerso(&p, ecran);
		afficher_Background (background, ecran);
		afficherPerso(p, ecran);
		if (player==1)
			afficherPerso(p2, ecran);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		break;

	case SDLK_RIGHT:
		p.mov=0;
		p.direction=0;
		deplacerPerso(&p, ecran);
		animerPerso(&p, ecran);
		afficher_Background (background, ecran);
		afficherPerso(p, ecran);
		if (player==1)
			afficherPerso(p2, ecran);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		if ((event.key.keysym.sym)==SDLK_v)
			{
				p.mov=5;
				deplacerPerso(&p, ecran);
				animerPerso(&p, ecran);
				afficher_Background (background, ecran);
				afficherPerso(p, ecran);
				if (player==1)
					afficherPerso(p2, ecran);
				SDL_Flip(ecran);
			}
		SDL_WaitEvent(&event);
		break;

	case SDLK_LEFT:
		p.mov=1;
		p.direction=1;
		deplacerPerso(&p, ecran);
		animerPerso(&p, ecran);
		afficher_Background (background, ecran);
		afficherPerso(p, ecran);
		if (player==1)
			afficherPerso(p2, ecran);
		SDL_Flip(ecran);
		if ((event.key.keysym.sym)==SDLK_v)
			{
				p.mov=6;
				deplacerPerso(&p, ecran);
				animerPerso(&p, ecran);
				afficher_Background (background, ecran);
				afficherPerso(p, ecran);
				if (player==1)
					afficherPerso(p2, ecran);
				SDL_Flip(ecran);
			}
		SDL_WaitEvent(&event);
		break;
		
	case SDLK_j:
		saut(&p, p2, dt, player, ecran, background);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		break;
		
	case SDLK_p:
		initPerso(&p2);
		player=1;
		afficher_Background (background, ecran);
		afficherPerso(p, ecran);
		afficherPerso(p2, ecran);
		SDL_Flip(ecran);
		break;
		
	case SDLK_d:
		if (player==1)
		{
			p2.mov=0;
			p2.direction=0;
			deplacerPerso(&p2, ecran);
			animerPerso(&p2, ecran);
			afficher_Background (background, ecran);
			afficherPerso(p, ecran);
			afficherPerso(p2, ecran);
			SDL_Flip(ecran);
			SDL_WaitEvent(&event);
		if ((event.key.keysym.sym)==SDLK_e)
			{
				p2.mov=5;
				deplacerPerso(&p2, ecran);
				animerPerso(&p2, ecran);
				afficher_Background (background, ecran);
				afficherPerso(p, ecran);
				afficherPerso(p2, ecran);
				SDL_Flip(ecran);
			}
		SDL_WaitEvent(&event);
		}
		break;
		
	case SDLK_q:
		if (player==1)
		{
		p2.mov=1;
		p2.direction=1;
		deplacerPerso(&p2, ecran);
		animerPerso(&p2, ecran);
		afficher_Background (background, ecran);
		afficherPerso(p, ecran);
		afficherPerso(p2, ecran);
		SDL_Flip(ecran);
		if ((event.key.keysym.sym)==SDLK_e)
			{
				p.mov=6;
				deplacerPerso(&p2, ecran);
				animerPerso(&p2, ecran);
				afficher_Background (background, ecran);
				afficherPerso(p, ecran);
				afficherPerso(p2, ecran);
				SDL_Flip(ecran);
			}
		SDL_WaitEvent(&event);
		}
		break;
		
	case SDLK_z:
		if(player==1)
		{
		p2.mov=3;
		deplacerPerso(&p2, ecran);
		animerPerso(&p2, ecran);
		afficher_Background (background, ecran);
		afficherPerso(p, ecran);
		afficherPerso(p2, ecran);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		}
		break;
		
	case SDLK_s:
		if (player==1)
		{
		p2.mov=4;
		deplacerPerso(&p2, ecran);
		animerPerso(&p2, ecran);
		afficher_Background (background, ecran);
		afficherPerso(p, ecran);
		afficherPerso(p2, ecran);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		}
		break;
		
	case SDLK_f:
		if (player==1)
		{
		saut(&p2, p, dt, player, ecran, background);
		SDL_Flip(ecran);
		SDL_WaitEvent(&event);
		}
		break;
	
	
		
	}
	break;
	}
	SDL_Flip(ecran);
	if(1000/FPS > SDL_GetTicks()-start) 
        {
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }
	
	}
	
	for (i=0;i<6;i++)
	{
		SDL_FreeSurface(p.perso[i]);
	}
	
	SDL_FreeSurface(background.imageFond);
	SDL_Quit();
	
	return EXIT_SUCCESS;
}
