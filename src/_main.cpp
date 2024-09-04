#include "_includes.hpp"

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

<<<<<<< HEAD:src/_main.cpp
        /* Updates to assets / sprites */

        SDL_SetRenderDrawColor(rnd, 0, 0, 255, 255);
=======
        /* Updates to assets - sprites */
>>>>>>> 3e881380d259f070978efcbd5ecb22d3c991548f:src/main.c

        SDL_RenderClear(rnd);

        /* Render functions */

        SDL_RenderPresent(rnd);
    }

    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
