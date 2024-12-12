#include "auxf/includes.aux"

int main(int argc, char* argv[]){

    SDL2_InitWin(); /* Initialise */
    OGL_InitContext(SDL2_Win);
    OGL_OpenGLInfo();

    bool quit = false;

    while(!quit){
        SDL2_HandleEvents(quit); /* Creates a new event to poll per call (Might need to be optimised) */

        /* Updates to assets / sprites */

        /* OpenGL rendering functions */
        OGL_PreDraw();
        OGL_Draw();

        SDL_GL_SwapWindow(SDL2_Win);
    }

    SDL_DestroyRenderer(SDL2_Rnd);
    SDL_DestroyWindow(SDL2_Win);
    SDL_Quit();

    return SUCCESS;
}
