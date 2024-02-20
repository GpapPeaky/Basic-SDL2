#include "init_window.h"

SDL_Window * win = NULL;
SDL_Renderer * rnd = NULL;

INITIALISER init_win(){
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1){
        printf("SDL Could Not Initialise, Error: %s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if(IMG_Init(IMG_INIT_PNG) == 0){
        printf("Failed To Initialise PNGs, Error: %s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

    /* Initialising window and renderer */

    win = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(win == NULL){
        printf("Failed To Create Window: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    rnd = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(rnd == NULL){
        printf("Failed To Create Renderer: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    return;
}
