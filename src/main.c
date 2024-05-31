#include "main.h"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    int quit = 0;
    SDL_Event e;    

    while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_e){
                quit = 1;
            }
        }

        /* Updates to assets - sprites */

        SDL_RenderClear(rnd);

        /* Render functions */

        SDL_RenderPresent(rnd);
        SDL_Delay(100);
    }

    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}
