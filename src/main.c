#include "main.h"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    int quit = 0;
    SDL_Event e;

    while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = 1;
            }
        }

        SDL_SetRenderDrawColor(rnd, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(rnd);

        /* Render Stuff Here */

        SDL_RenderPresent(rnd);
    }

    return EXIT_SUCCESS;
}
