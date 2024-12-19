#include "auxf/includes.aux"

int main(int argc, char* argv[]){

    SDL2_InitWin(); /* Initialise */

    BSC_CreateEntity(PLAYER, 1);

    bool quit = false;
    while(!quit){
        SDL2_HandleEvents(quit); /* Creates a new event to poll per call (Might need to be optimised) */

        /* Updates to assets / sprites */

        SDL_SetRenderDrawColor(SDL2_Rnd, 0, 0, 255, 255);

        SDL_RenderClear(SDL2_Rnd);

        SDL_RenderCopy(SDL2_Rnd, BSC_Entities[PLAYER][0]->img.texture, NULL, &BSC_Entities[PLAYER][0]->img.position);
        /* Render functions */

        SDL_RenderPresent(SDL2_Rnd);
    }

    SDL_DestroyRenderer(SDL2_Rnd);
    SDL_DestroyWindow(SDL2_Win);
    SDL_Quit();

    return SUCCESS;
}
