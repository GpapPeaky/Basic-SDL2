#include "_includes.hpp"

int main(int argc, char* argv[]){

    init_win(); /* Initialise */

    int quit = 0;
    SDL_Event e;    

    while(!quit){
        handle_events(quit, e);

        /* Updates to assets / sprites */

        SDL_SetRenderDrawColor(rnd, 0, 0, 255, 255);

        SDL_RenderClear(rnd);

        /* Render functions */

        SDL_RenderPresent(rnd);
    }

    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
