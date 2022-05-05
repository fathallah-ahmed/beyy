#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"

int main (void)
{
    int continuer=1;
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
    
    initBack(&b);//initialisation de background 1
    initBack1(&b);//initialisation de background 2
	
    while (continuer)
    {
    afficheBack(b,ecran);//affichage de background 1
    afficheBack1(b,ecran);//affichage de background 2
    
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
                //camera 1
                case SDLK_d:
                    scrolling(&b,0);//d
                    break;
                case SDLK_q:
                    scrolling(&b,1);//q
                    break;
                case SDLK_z:
                    scrolling(&b,2);//z
                    break;
                case SDLK_s:
                    scrolling(&b,3);//s
                    break;
                //camera 2
                case SDLK_RIGHT:
                    scrolling(&b,4);//right
                    break;
                case SDLK_LEFT:
                    scrolling(&b,5);//left
                    break;
                case SDLK_UP:
                    scrolling(&b,6);//up
                    break;
                case SDLK_DOWN:
                    scrolling(&b,7);//down
                    break;
                }              
                break;
            }
        }
        SDL_Flip(ecran);//mise a jour de l'ecran
    }
    //liberation de memoire
    liberer(b);
    Mix_CloseAudio();
    SDL_Quit();
    return EXIT_SUCCESS;
}

