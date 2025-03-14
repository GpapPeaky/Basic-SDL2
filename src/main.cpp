#include "auxf/includes.aux"

int main(int argc, char* argv[]){
    /* Initialise SDL2 and OpenGL */
    SDL2_InitWin();
    OGL_InitContext(SDL2_Win);

    /* Initialise an object, vertex specification */
    OGL_VertexObject quad;
    OGL_VertexObject triangle;
    OGL_QuadVertexFC(quad);
    OGL_TriangleVertexFC(triangle);

    /* Graphics pipeline for the shader program */
    GLuint sp1;
    GLuint sp2;
    sp1 = OGL_CreateGraphicsPipeline(OGLS_DummyV, OGLS_DummyF);
    sp2 = OGL_CreateGraphicsPipeline(OGLS_PeakyV, OGLS_PeakyF);

    /* Main loop */
    bool SDL2_Quit = false;
    while(!SDL2_Quit){
        SDL2_HandleEvents(SDL2_Quit); /* Creates a new event to poll per call (Might need to be optimised) */

        /* Updates to assets / sprites */

        /* OpenGL rendering functions */
        OGL_SetScreenBackground(1.f, 1.f, 0.f, 1.f);

        /* Rendering order matters */
        OGL_PreDraw(sp2);
        OGL_DrawObject(quad);
        OGL_PreDraw(sp1);
        OGL_DrawObject(triangle);

        SDL_GL_SwapWindow(SDL2_Win);
    }

    /* Cleanup */
    SDL_DestroyRenderer(SDL2_Rnd);
    SDL_DestroyWindow(SDL2_Win);
    SDL_Quit();

    return SUCCESS;
}
