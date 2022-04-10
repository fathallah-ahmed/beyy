

typedef struct
{
	int direction,mov,up,frame,vitesse,jump;
	SDL_Surface* perso[18];
	SDL_Rect persoAbs;
	SDL_Rect persoRel;
	
}Personne;


typedef struct
{
	SDL_Surface* imageFond;
	SDL_Rect posback;
}Background;

Personne player[4];

void init(Personne *p, int numperso);
void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface *screen);
void deplacerPerso(Personne *p, SDL_Surface *ecran);
void animerPerso (Personne* p, SDL_Surface* ecran);
void saut(Personne *p, Personne p2, int dt, int player, SDL_Surface *ecran, Background background);

//--------------------Background-----------------//

void afficher_Background (Background background, SDL_Surface* screen);