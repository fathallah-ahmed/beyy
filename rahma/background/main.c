#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"

int main (void)
{
    int continuer=1,collision;
    background b;
    SDL_Surface *ecran=NULL;
    SDL_Event event;
    SDL_Init(SDL_INIT_EVERYTHING);
    //initialisation de lecran
    ecran= SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

//Initialisation de l'API Mixer
    if(Mix_OpenAudio(1366, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 678) == -1)
    {
        printf("%s", Mix_GetError());
    }

//nom du jeux
    SDL_WM_SetCaption("nom de jeux",NULL);

//Enables or disables the keyboard repeat rate
//delay specifies how long the key must be pressed before it begins repeating, it then repeats at the speed specified by interval
    SDL_EnableKeyRepeat(10,10);

    initBack(&b);//initialisation de background
	
    while (continuer)
    {
    afficheBack(b,ecran);//affichage de background
    animerbackground(&b,ecran);//animation de background
    
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    scrolling(&b,0);//0 right
                    break;
                case SDLK_LEFT:
                    scrolling(&b,1);//1 left
                    break;
                case SDLK_UP:
                    scrolling(&b,2);//2 up
                    break;
                case SDLK_DOWN:
                    scrolling(&b,3);//3 down
                    break;
                }
                break;
            }
        }
        //itha famma collision ikharejlek fel console message collision sinon yabÇa ikharej pas collision
        /*
        if(collisionpp(b.imgbackm,p)==1)
        {
               printf("collision \n");
        }else{
        printf("pas collision\n");
        }
        */
        SDL_Delay(20);
        SDL_Flip(ecran);//mise a jour de lecran
    }
    //liberation de memoire
    liberer(b);
    Mix_CloseAudio();
    SDL_Quit();
    return EXIT_SUCCESS;
}

