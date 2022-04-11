#include "pres.h"

void initialiserperso(pers *p)
{	
	p->image_p=IMG_Load("per.bmp");
	p->pos_perso.x=0;
	p->pos_perso.y=200;
	p->pos_perso.w=100;
	p->pos_perso.h=100;
}

void afficher_perso(SDL_Surface *screen,pers p)
{	
	SDL_BlitSurface(p.image_p,NULL,screen,&p.pos_perso);
}

void deplacer_perso(pers *p,SDL_Event event)
{	
	SDL_PollEvent(&event);
         switch(event.type)
            {
                case SDL_KEYDOWN:
                       switch(event.key.keysym.sym)
                        {
                        
                        case SDLK_UP:
                            p->pos_perso.y=p->pos_perso.y-10;
                            break;
                        case SDLK_DOWN:
                            p->pos_perso.y=p->pos_perso.y+10;
                            break;
                        case SDLK_RIGHT:
                            p->pos_perso.x=p->pos_perso.x+10;
                            break;
                        case SDLK_LEFT:
                            p->pos_perso.x=p->pos_perso.x-10;
                            break;
                        }
                 break;
             }
}
void free_perso(pers p)
{
	SDL_FreeSurface(p.image_p);
}
