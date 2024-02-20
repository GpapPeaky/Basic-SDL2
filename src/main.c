#include "main.h"

int main(int argc, char* argv[]){
    // init_win(); /* Initialise */

    /* BUG: MAIN IS NOT ACCESSED */

    printf("DBG");

    int quit = 0;
    SDL_Event e;    

    while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.key.keysym.sym == SDLK_ESCAPE){
                quit = 1;
            }
        }
        SDL_SetRenderDrawColor(rnd, 0, 0, 255, 255);
        SDL_RenderClear(rnd);
        SDL_RenderPresent(rnd);
        SDL_Delay(100);
    }

    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}
