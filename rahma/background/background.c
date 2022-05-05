#include "background.h"

void initBack (background *b)
{
//load de limage de background
    b->imgback=IMG_Load("background.png");
//position de background
    b->posback.x=0;
    b->posback.y=0;
//load de limage de background masque
    b->imgbackm=IMG_Load("masque.png");
//position de background masque
    b->posbackm.x=0;
    b->posbackm.y=0;
//position et taille de camera
    b->camera.x=0;
    b->camera.y=0;
    b->camera.w=SCREEN_W;
    b->camera.h=SCREEN_H;
//numero de limage de lanimation 1 et 2
    b->num1=0;
    b->num1=0;
//position de l'animation 1
    b->posanim1.x = 200;
    b->posanim1.y = 270;
//position de l'animation 2
    b->posanim2.x = 800;
    b->posanim2.y = 20;
//image de l'animation 1
    b->anim1[0]=IMG_Load("img/feux1.png");
    b->anim1[1]=IMG_Load("img/feux2.png");
    b->anim1[2]=IMG_Load("img/feux3.png");
    b->anim1[3]=IMG_Load("img/feux4.png");
    b->anim1[4]=IMG_Load("img/feux5.png");
    b->anim1[5]=IMG_Load("img/feux6.png");
    b->anim1[6]=IMG_Load("img/feux7.png");
    b->anim1[7]=IMG_Load("img/feux8.png");
    b->anim1[8]=IMG_Load("img/feux9.png");
//image de l'animation 2
    b->anim2[1]=IMG_Load("img/ois1.png");
    b->anim2[2]=IMG_Load("img/ois2.png");
    b->anim2[3]=IMG_Load("img/ois3.png");
    b->anim2[4]=IMG_Load("img/ois4.png");
    b->anim2[5]=IMG_Load("img/ois5.png");
    b->anim2[6]=IMG_Load("img/ois6.png");
    b->anim2[7]=IMG_Load("img/ois7.png");
    b->anim2[8]=IMG_Load("img/ois8.png");
    b->anim2[8]=IMG_Load("img/ois9.png");
//musique
    b->son=Mix_LoadMUS("fond.wav"); //Chargement de la musique
    Mix_PlayMusic(b->son, -1); //Jouer infiniment la musique
}

void afficheBack (background b, SDL_Surface *ecran)
{
    //affichage de background
    SDL_BlitSurface(b.imgback,&b.camera,ecran,&b.posback);
}

void animerbackground (background *b,SDL_Surface *ecran)
{
    //animation 1
    if(b->num1 == 8)//ken wsel el ekher image fel animation i3awed melowel
    {
        b->num1 = 0;
    }
    else
    {
    b->num1++;
    }
    //animation 2
    if(b->num2 == 8)
    {
        b->num2 = 0;
    }
    else
    {
        b->num2++;
    }

    //affichage de l'animation
    SDL_BlitSurface(b->anim1[b->num1],NULL,ecran,&b->posanim1);
    SDL_BlitSurface(b->anim2[b->num2],NULL,ecran,&b->posanim2);
}


void scrolling (background *b,int direction)
{
int speed=6;//vitesse de lavancement de camera
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
    }
}

//traja3lek l couleur taa lpixel eli fiha l personnage
SDL_Color getpixel(SDL_Surface *pSurface,int x,int y)
{
    SDL_Color color;
    Uint32 col=0;
    char* pPosition=(char* ) pSurface->pixels;
    pPosition+= (pSurface->pitch * y);
    pPosition+= (pSurface->format->BytesPerPixel *x);
    memcpy(&col,pPosition,pSurface->format->BytesPerPixel);
    SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
    return (color);
}
/*
//zid perso maa khedmtek bech tnajem ettasti el collision
int  collisionpp(SDL_Surface *psurface,personnage p)
{
    int i,collision=0;
    SDL_Color color1,color;
    //couleur de collision a detecte
    color1.r = 0;
    color1.g = 0;
    color1.b = 0;
    //tableau de limite de joueur
    SDL_Rect tab[8];
    tab[0].x=p.pos_perso.x;
    tab[1].x=(p.pos_perso.x)+((p.pos_perso.w)/2);
    tab[2].x=(p.pos_perso.x+p.pos_perso.w);
    tab[3].x=p.pos_perso.x;
    tab[4].x=p.pos_perso.x;
    tab[5].x=(p.pos_perso.x)+((p.pos_perso.w)/2);
    tab[6].x=(p.pos_perso.x+p.pos_perso.w);
    tab[7].x=(p.pos_perso.x+p.pos_perso.w);
    tab[0].y=p.pos_perso.y;
    tab[1].y=p.pos_perso.y;
    tab[2].y=p.pos_perso.y;
    tab[3].y=(p.pos_perso.y)+((p.pos_perso.h)/2);
    tab[4].y=(p.pos_perso.y+p.pos_perso.h);
    tab[5].y=(p.pos_perso.y+p.pos_perso.h);
    tab[6].y=(p.pos_perso.y+p.pos_perso.h);
    tab[7].y=(p.pos_perso.y)+((p.pos_perso.h)/2);

    //idour wi9aren fel couleur ken famma collision iraja3lek 1 sinon 0
    for(i=0; i<8 && collision==0; i++)
    {
        color=getpixel(psurface,tab[i].x,tab[i].y);
        if(color.r==color1.r && color.g==color1.g && color.b==color1.b)
        {
            collision=1;
        }
    }
    return collision;
}
*/

void liberer(background b)
{
	free(b.imgback);
	free(b.imgbackm);
	free(b.anim1[0]);
	free(b.anim1[1]);
	free(b.anim1[2]);
	free(b.anim1[3]);
	free(b.anim2[0]);
	free(b.anim2[1]);
	free(b.anim2[2]);
	free(b.anim2[3]);
	free(b.anim2[4]);
	free(b.son);
}


