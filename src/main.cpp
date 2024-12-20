#include "auxf/includes.aux"

int main(int argc, char* argv[]){
    SDL2_InitWin(); /* Initialise */

    BSC_CreateEntity(PLAYER, 1);
    BSC_CreateEntity(GREEN_SLIME_WARRIOR, 1);

    bool quit = false;
    Uint32 lastTime = SDL_GetTicks();
    while(!quit){
        Uint32 currentTime = SDL_GetTicks();
        float dt = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;
        SDL2_HandleEvents(quit, dt); /* Creates a new event to poll per call (Might need to be optimised) */
        SDL2_HandlePlayerMovement(BSC_Entities[PLAYER][PLAYER], dt);
        BSC_UpdateEntityFire(BSC_Entities[PLAYER][PLAYER], dt);

        SDL_RenderClear(SDL2_Rnd);

        BSC_RenderEntities();

        SDL_RenderPresent(SDL2_Rnd);
    }

    SDL_DestroyRenderer(SDL2_Rnd);
    SDL_DestroyWindow(SDL2_Win);
    SDL_Quit();

    return SUCCESS;
}
