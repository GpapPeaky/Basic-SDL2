#include "init_window.h"

SDL_Window * win = NULL;
SDL_Renderer * rnd = NULL;

INITIALISER init_win(){
    SDL_Init(SDL_INIT_EVERYTHING);
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
        printf("SDL Could Not Initialise, Error: %s\n",SDL_GetError());
        return;
    }

    IMG_Init(IMG_INIT_PNG);
    if(IMG_Init(IMG_INIT_PNG) == 0){
        printf("Failed To Initialise PNGs, Error: %s\n",SDL_GetError());
        return;
    }

    /* Initialising window and renderer */

    win = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 800, SDL_WINDOW_SHOWN);
    if(win == NULL){
        printf("Failed To Create Window: %s\n", SDL_GetError());
        return;
    }

    rnd = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(rnd == NULL){
        printf("Failed To Create Renderer: %s\n", SDL_GetError());
        return;
    }

    SDL_RenderClear(rnd);
}
