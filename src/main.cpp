#include "auxf/includes.aux"

int main(int argc, char* argv[]){
    /* Initialise SDL2 and OpenGL */
    SDL2_InitWin();
    OGL_InitContext(SDL2_Win);

    /* Initialise an object, vertex specification */
    OGL_VertexObject o1;
    OGL_TriangleVertexFC(o1);

    /* Graphics pipeline for the shader program */
    GLuint shaderProg;
    shaderProg = OGL_CreateGraphicsPipeline(OGLS_DummyV, OGLS_DummyF);

    /* Main loop */
    bool SDL2_Quit = false;
    while(!SDL2_Quit){
        SDL2_HandleEvents(SDL2_Quit); /* Creates a new event to poll per call (Might need to be optimised) */

        /* Updates to assets / sprites */

        /* OpenGL rendering functions */
        /* Rendering order matters */
        OGL_PreDraw(shaderProg);
        OGL_DrawObject(o1);

        SDL_GL_SwapWindow(SDL2_Win);
    }

    /* Cleanup */
    SDL_DestroyRenderer(SDL2_Rnd);
    SDL_DestroyWindow(SDL2_Win);
    SDL_Quit();

    return SUCCESS;
}
