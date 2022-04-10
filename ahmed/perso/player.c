#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player.h"

void init(Personne *p, int numperso)
{
	player[numperso]=(*p);
}

void initPerso(Personne *p)
{
	p->direction=1;
	p->up=0;
	p->frame=0;
	p->vitesse=1;
	p->jump=0;
	
	p->perso[0]=IMG_Load("perso0.bmp");
	SDL_SetColorKey(p->perso[0], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[0]->format, 255, 0,0));
	
	p->perso[1]=IMG_Load("perso1.bmp");
	SDL_SetColorKey(p->perso[1], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[1]->format, 255, 0,0));
	
	p->perso[2]=IMG_Load("perso2.bmp");
	SDL_SetColorKey(p->perso[2], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[2]->format, 255, 0,0));
	
	p->perso[3]=IMG_Load("perso3.bmp");
	SDL_SetColorKey(p->perso[3], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[3]->format, 255, 0,0));
	
	p->perso[4]=IMG_Load("perso4.bmp");
	SDL_SetColorKey(p->perso[4], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[4]->format, 255, 0,0));
	
	p->perso[5]=IMG_Load("perso5.bmp");
	SDL_SetColorKey(p->perso[5], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[5]->format, 255, 0,0));
	
	p->perso[6]=IMG_Load("perso6.bmp");
	SDL_SetColorKey(p->perso[6], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[6]->format, 255, 0,0));
	
	p->perso[7]=IMG_Load("perso7.bmp");
	SDL_SetColorKey(p->perso[7], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[7]->format, 255, 0,0));
	
	p->perso[8]=IMG_Load("perso8.bmp");
	SDL_SetColorKey(p->perso[8], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[8]->format, 255, 0,0));
	
	p->perso[9]=IMG_Load("perso9.bmp");
	SDL_SetColorKey(p->perso[9], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[9]->format, 255, 0,0));
	
	p->perso[10]=IMG_Load("perso10.bmp");
	SDL_SetColorKey(p->perso[10], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[10]->format, 255, 0,0));
	
	p->perso[11]=IMG_Load("perso11.bmp");
	SDL_SetColorKey(p->perso[11], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[11]->format, 255, 0,0));
	
	p->perso[12]=IMG_Load("perso12.bmp");
	SDL_SetColorKey(p->perso[12], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[12]->format, 255, 0,0));
	
	p->perso[13]=IMG_Load("perso13.bmp");
	SDL_SetColorKey(p->perso[13], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[13]->format, 255, 0,0));
	
	p->perso[14]=IMG_Load("perso14.bmp");
	SDL_SetColorKey(p->perso[14], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[14]->format, 255, 0,0));
	
	p->perso[15]=IMG_Load("perso15.bmp");
	SDL_SetColorKey(p->perso[15], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[15]->format, 255, 0,0));
	
	p->perso[16]=IMG_Load("perso16.bmp");
	SDL_SetColorKey(p->perso[16], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[16]->format, 255, 0,0));
	
	p->perso[17]=IMG_Load("perso17.bmp");
	SDL_SetColorKey(p->perso[17], SDL_SRCCOLORKEY,SDL_MapRGB(p->perso[17]->format, 255, 0,0));
	
	p->persoAbs.x=0;
	p->persoAbs.y=400;
};

void afficherPerso(Personne p, SDL_Surface *screen)
{
	SDL_BlitSurface(p.perso[p.frame], NULL, screen, &p.persoAbs);
};

void afficher_Background (Background background, SDL_Surface* screen)
{
	SDL_BlitSurface(background.imageFond, NULL, screen, &background.posback);
}

void deplacerPerso(Personne *p, SDL_Surface *ecran)
{
	if (p->mov==0)
		{
			p->persoAbs.x+=p->vitesse;
		}
		
	if (p->mov==1)
		{
			p->persoAbs.x-=p->vitesse;
		}
		
		if (p->mov==3)
		{
			p->persoAbs.y-=p->vitesse;
		}
		
	if (p->mov==4)
		{
			p->persoAbs.y+=p->vitesse;
		}
		
		
	if (p->mov==5)
		{
			p->persoAbs.x+=p->vitesse*4;
		}
		
	if (p->mov==6)
		{
			p->persoAbs.x-=p->vitesse*4;
		}
	p->frame++;
}


void animerPerso (Personne* p, SDL_Surface* ecran)
{
	if (p->direction==0)
	{
		if (p->frame<0 || p->frame>2)
			p->frame=0;
	}
	
	if (p->direction==1)
	{
		if (p->frame<3 || p->frame>5)
			p->frame=3;
	}
	
	if (p->direction==0 && p->jump==1)
	{
		if (p->frame<6 || p->frame>11)
			p->frame=6;
	}
	
	if (p->direction==1 && p->jump==1)
	{
		if (p->frame<12 || p->frame>17)
			p->frame=12;
	}
}

void saut(Personne *p, Personne p2, int dt, int player, SDL_Surface *ecran, Background background)
{
	int i;
	int posinit=0;
	p->jump=1;
	
	for (i=0;i<dt;i++)
		{
			p->persoAbs.y--;
			posinit++;
			
			if (p->direction==0)
			{
				p->persoAbs.x++;
				animerPerso(p, ecran);
				afficher_Background (background, ecran);
				afficherPerso(*p, ecran);
				if (player==1)
					afficherPerso(p2, ecran);
				SDL_Flip(ecran);
			}
			if (p->direction==1)
			{
				p->persoAbs.x--;
				animerPerso(p, ecran);
				afficher_Background (background, ecran);
				afficherPerso(*p, ecran);
				if (player==1)
					afficherPerso(p2, ecran);
				SDL_Flip(ecran);
			}
			
			
		}
	for (i=0;i<dt;i++)
		{
			p->persoAbs.y++;
			posinit++;
			
			if (p->direction==0)
			{
				p->persoAbs.x++;
				animerPerso(p, ecran);
				afficher_Background (background, ecran);
				afficherPerso(*p, ecran);
				if (player==1)
					afficherPerso(p2, ecran);
				SDL_Flip(ecran);
			}
			if (p->direction==1)
			{
				p->persoAbs.x--;
				animerPerso(p, ecran);
				afficher_Background (background, ecran);
				afficherPerso(*p, ecran);
				if (player==1)
					afficherPerso(p2, ecran);
				SDL_Flip(ecran);
			}
			
			
		}
	p->jump=0;
}

