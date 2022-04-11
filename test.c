#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h> 
#include<SDL/SDL_mixer.h> 
#include<SDL/SDL_ttf.h>  
#include "time.h"
#include "map.h"


void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
	clip=NULL;
	SDL_Rect offset;
	
	offset.x=x;
	offset.y=y;

	SDL_BlitSurface( source, clip, destination, &offset);
}

int main(void){


SDL_Init(SDL_INIT_EVERYTHING);


SDL_Surface* message=NULL;
TTF_Font *font=NULL;
SDL_Color textColor={255, 0, 0};
SDL_Rect* clip=NULL;

SDL_Surface *screen;
SDL_Surface *ecran,*jouer,*image,*parametre,*quitter,*personnage,*pierre,*jouer1,*parametre1,*quitter1,*logo,*L[10],*volume,*volume1;//les variables pour les images
SDL_Surface *vol,*reso,*reso1;
SDL_Rect postionimage,posjouer,posparametre,posquitter,postionjoueur,posob,poslogo,posvolume,posvolume1,posvol,posreso,posreso1,positionFond,positiontext;//les variables pour les positions des images
int avanceX = 1, avanceY = 1; 
SDL_Event event;
char pause;
int continuer=1,x=0,done=1,i=0,ta2=0,tp2=0,i1=128,done1=1,play=1;
Mix_Chunk *music,*music1;
Mix_AllocateChannels(2);


if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
music=Mix_LoadWAV("Clic De Souris.wav");
music1=Mix_LoadWAV("fond.wav");
Mix_VolumeChunk(music1,i1);


if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}


screen=SDL_SetVideoMode(1000,667,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
ecran = SDL_SetVideoMode(1000,667, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen==NULL){
printf("unable to set video mode:%s\n",SDL_GetError());
return 1;
}


vol=IMG_Load("V1.png");
reso=IMG_Load("resolution.png");
reso1=IMG_Load("reso1.png");
volume=IMG_Load("volume2.png");
volume1=IMG_Load("volume3.png");


L[0]=IMG_Load("1a.png");
L[1]=IMG_Load("2a.png");
L[2]=IMG_Load("3a.png");
L[3]=IMG_Load("4a.png");
L[4]=IMG_Load("5a.png");
L[5]=IMG_Load("6a.png");
L[6]=IMG_Load("7a.png");
L[7]=IMG_Load("8a.png");
L[8]=IMG_Load("9a.png");
L[9]=IMG_Load("10a.png");



SDL_WM_SetCaption("L'bey",NULL);

font=TTF_OpenFont("lazy.ttf", 50);
message= TTF_RenderText_Solid( font, "L'bey", textColor);


image=IMG_Load("0.jpg");

jouer=IMG_Load("12.png");
jouer1=IMG_Load("111.png");
parametre1=IMG_Load("13.png");
parametre=IMG_Load("14.png");
quitter=IMG_Load("15.png");
quitter1=IMG_Load("16.png");


postionimage.x=0;
postionimage.y=0;
posvolume.x=600;
posvolume.y=125;
posvolume1.x=882;
posvolume1.y=120;
posvol.x=200;
posvol.y=100;
posreso.x=200;
posreso.y=300;
posreso1.x=600;
posreso1.y=300;
postionimage.w=image->w;
postionimage.h=image->h;
image->w=1000;
image->h=704;
Mix_PlayChannel(2,music1,-1);

while(i!=10)
{

ta2 = SDL_GetTicks();
         

        if (ta2 - tp2 >= 500) 
        {   i++;
          
        SDL_BlitSurface(L[i],NULL,screen,&postionimage);
	
   SDL_Flip(screen);  
        tp2 = ta2; 

        }}

//initioalisation de minimap
	Time temps;

	map m;
	pers p;
	
	inittemps(&temps);
	initialiser_map (&m,screen,&p) ;
	initialiserperso(&p);
	
	SDL_Event event1;	
SDL_Surface *backg;
SDL_Rect backg_pos;	
backg = SDL_LoadBMP("backggvr.bmp");
	backg_pos.x = 0;
	backg_pos.y = 0;



SDL_BlitSurface(image,NULL,screen,&postionimage); 

posjouer.x=332;
posjouer.y=300;
posparametre.x=332;
posparametre.y=412;
posquitter.x=332;
posquitter.y=524;

positiontext.x=200;
positiontext.y=110;


SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_BlitSurface(message,NULL,screen,&positiontext);
apply_surface(200, 110, message, screen, clip);
SDL_Flip(screen);

while(continuer)
{
done=1;
done1=1;
SDL_WaitEvent(&event);

switch(event.type)
{

case SDL_QUIT:
continuer=0;
break;
case SDL_KEYUP:
        switch(event.key.keysym.sym)
        {   
            case SDLK_UP:
                if(x==0)
               { x=2;
               break;}
               if(x==2)
              {  x=1;
               break;}
             
                break;
            case SDLK_DOWN:
                
                x++;
                x=x%3;
         
                break;
            case SDLK_SPACE:
            if(x==0)
            continuer=0;
         if(x==2)
{Mix_PlayChannel(1,music,0);
while(done1)
{
SDL_PollEvent(&event);
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(volume,NULL,screen,&posvolume);
SDL_BlitSurface(volume1,NULL,screen,&posvolume1);
SDL_BlitSurface(vol,NULL,screen,&posvol);
SDL_BlitSurface(reso,NULL,screen,&posreso);
SDL_BlitSurface(reso1,NULL,screen,&posreso1);
SDL_Flip(screen);

switch(event.type)
{
case SDL_MOUSEBUTTONDOWN :
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<900&&event.button.x>600)&&(event.button.y<133&&event.button.y>125))
{posvolume1.x=event.button.x;
if(((posvolume1.x-600)/2)>22)
i1=((posvolume1.x-600)/2)-22;
if(((posvolume1.x-600)/2)<=22)
i1=-(((posvolume1.x-600)/2)-22);
}
Mix_VolumeChunk(music1,i1);
break;
case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {   case SDLK_ESCAPE:
             done1=0;
             break;}
break;
}

}
}
            if(x==1)
             {Mix_PlayChannel(1,music,0);
x=1;

}
           break;

done=1;
}  
if(x==1)
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer,NULL,screen,&posjouer);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_BlitSurface(message,NULL,screen,&positiontext);
SDL_Flip(screen);}
if(x==2)
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(parametre,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_BlitSurface(message,NULL,screen,&positiontext);
SDL_Flip(screen);}
if(x==0)
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter1,NULL,screen,&posquitter);
SDL_BlitSurface(message,NULL,screen,&positiontext);
SDL_Flip(screen);}
break;
case SDL_MOUSEMOTION:
if((event.motion.x<668&&event.motion.x>332)&&(event.motion.y<382&&event.motion.y>300))
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer,NULL,screen,&posjouer);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_BlitSurface(message,NULL,screen,&positiontext);
SDL_Flip(screen);
}
if(!(((event.motion.x<668&&event.motion.x>332)&&(event.motion.y<382&&event.motion.y>300))||(event.motion.x<668&&event.motion.x>332)&&(event.motion.y<494&&event.motion.y>412)||(event.motion.x<668&&event.motion.x>332)&&(event.motion.y<686&&event.motion.y>524)))
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_BlitSurface(message,NULL,screen,&positiontext);
SDL_Flip(screen);

}
if((event.motion.x<668&&event.motion.x>332)&&(event.motion.y<494&&event.motion.y>412))
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(parametre,NULL,screen,&posparametre);
SDL_BlitSurface(quitter,NULL,screen,&posquitter);
SDL_BlitSurface(message,NULL,screen,&positiontext);
SDL_Flip(screen);
}
if((event.motion.x<668&&event.motion.x>332)&&(event.motion.y<686&&event.motion.y>524))
{
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(jouer1,NULL,screen,&posjouer);
SDL_BlitSurface(parametre1,NULL,screen,&posparametre);
SDL_BlitSurface(quitter1,NULL,screen,&posquitter);
SDL_BlitSurface(message,NULL,screen,&positiontext);
SDL_Flip(screen);
}
break;
case SDL_MOUSEBUTTONDOWN :
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<668&&event.button.x>332)&&(event.button.y<382&&event.button.y>300))
{
Mix_PlayChannel(1,music,0);
//play
while(play){
	SDL_BlitSurface(backg, NULL, screen,&backg_pos);
	affiche_map(&m,screen,&p);
	SDL_PollEvent(&event1);
	switch(event1.type)
        {

        case SDL_QUIT:
            play=0;
            break;
	}	
		update_time(&temps);
		perso_map(&m,&p);
		
		affiche_map(&m,screen,&p);
		afficher_perso(screen,p);
		deplacer_perso(&p,event1);
		SDL_Delay(100);
		
		SDL_Flip(screen);
}
}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<668&&event.button.x>332)&&(event.button.y<494&&event.button.y>412))
{
Mix_PlayChannel(1,music,0);
while(done1)
{
SDL_PollEvent(&event);
SDL_BlitSurface(image,NULL,screen,&postionimage);
SDL_BlitSurface(volume,NULL,screen,&posvolume);
SDL_BlitSurface(volume1,NULL,screen,&posvolume1);
SDL_BlitSurface(vol,NULL,screen,&posvol);
SDL_BlitSurface(reso,NULL,screen,&posreso);
SDL_BlitSurface(reso1,NULL,screen,&posreso1);
SDL_Flip(screen);
switch(event.type)
{
case SDL_MOUSEBUTTONDOWN :
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<900&&event.button.x>600)&&(event.button.y<133&&event.button.y>125))
{posvolume1.x=event.button.x;
if(((posvolume1.x-600)/2)>22)
i1=((posvolume1.x-600)/2)-22;
if(((posvolume1.x-600)/2)<=22)
i1=-(((posvolume1.x-600)/2)-22);
}
Mix_VolumeChunk(music1,i1);
break;
case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {   case SDLK_ESCAPE:
             done1=0;
             break;}
break;
}

}
SDL_Flip(screen);
}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<668&&event.button.x>332)&&(event.button.y<686&&event.button.y>524))
{
Mix_PlayChannel(1,music,0);
continuer=0;
SDL_Flip(screen);
}}
}
return 1;
}
