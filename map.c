#include "map.h"

void initialiser_map (map *m,SDL_Surface *screen,pers *p)
{
	m->map=IMG_Load("mini.bmp");
	m->pos_map.x = 700;
	m->pos_map.y = 100;


	m->mini_perso=IMG_Load("joueurmini.png");
	
	m->perso_pos_map.x=4;
	m->perso_pos_map.y=4;

}


void perso_map(map *m,pers *p)
{
	m->perso_pos_map.x=p->pos_perso.x/10+m->pos_map.x;
	m->perso_pos_map.y=p->pos_perso.y/10+10+m->pos_map.y;// besh l position ta" l mini perso iji kad kad maa l perso lekbir 3al axe y 
}



void affiche_map(map *m , SDL_Surface *screen,pers *p)
{
	SDL_BlitSurface(m->map, NULL, screen,&m->pos_map);
	SDL_BlitSurface(m->mini_perso, NULL, screen,&m->perso_pos_map);

}

void meilleur_scr (int score)
	{
	FILE* fichier = NULL ;
	fichier=fopen("src.txt","a+");
	fprintf(fichier,"%d \n",score);
	fclose(fichier);
	}
	void save_name (char name[20])
	{
	FILE* fichier = NULL ;
	fichier=fopen("src.txt","a+");
	fprintf(fichier,"%s ",name);
	fclose(fichier);
	}
	int best_scr ()
	{
		int scr,bscr=0;
		char nom[20];
		FILE* fichier = NULL ;
		fichier=fopen("src.txt","r");
		while(scr>bscr)
		{
			fscanf(fichier,"%s %d \n",nom,&scr);
		}
		return bscr;
	}



