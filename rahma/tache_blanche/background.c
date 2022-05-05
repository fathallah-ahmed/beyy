#include "background.h"

void initBack (background *b)
{
//load de background 1
    b->imgback=IMG_Load("background.png");
//position de background 1
    b->posback.x=0;
    b->posback.y=0;
//load de masque 1
    b->imgbackm=IMG_Load("masque.png");
//position de masque 1
    b->posbackm.x=0;
    b->posbackm.y=0;
//taille et position de camera 1
    b->camera.x=0;
    b->camera.y=0;
    b->camera.w=SCREEN_W;
    b->camera.h=SCREEN_H;
//musique
    b->son=Mix_LoadMUS("fond.wav"); //Chargement de la musique
    Mix_PlayMusic(b->son, -1); //Jouer infiniment la musique
}

void initBack1 (background *b)
{
//load de background 2
    b->imgback=IMG_Load("background.png");
//position de background 2
    b->posback1.x=SCREEN_W2;
    b->posback1.y=0;
//load de masque 2
    b->imgbackm=IMG_Load("masque.png");
//position de masque 2
    b->posbackm1.x=SCREEN_W2;
    b->posbackm1.y=0;
//taille et position de masque 2
    b->camera1.x=0;
    b->camera1.y=0;
    b->camera1.w=SCREEN_W2;
    b->camera1.h=SCREEN_H2;
}

void afficheBack (background b, SDL_Surface *ecran)
{
//affichage de background 1
    SDL_BlitSurface(b.imgback,&b.camera,ecran,&b.posback);
}

void afficheBack1 (background b, SDL_Surface *ecran)
{
//affichage de background 2
    SDL_BlitSurface(b.imgback,&b.camera1,ecran,&b.posback1);
}

void scrolling (background *b,int direction)
{
int speed=8;//vitesse de deplacement de camera
	//camera 1
    if (direction ==0)//right
    {
        b->camera.x+=speed;
    }
    else
    {
        if(direction==1)//left
        {
            b->camera.x-=speed;
        }
        else if(direction==2)//up
        {
            b->camera.y-=speed;
        }
        else if(direction==3)//down
        {
            b->camera.y+=speed;
        }
        //camera 2
        if(direction==4)//right
        {
            b->camera1.x+=speed;
        }
        else if(direction==5)//left
        {
            b->camera1.x-=speed;
        }
        else if(direction==6)//up
        {
            b->camera1.y-=speed;
        }
        if(direction==7)//down
        {
            b->camera1.y+=speed;
        }
    }
}

void liberer(background b)
{
	free(b.imgback);
	free(b.imgbackm);
	free(b.son);
}


