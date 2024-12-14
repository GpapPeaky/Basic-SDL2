#include "auxf/includes.aux"

int main(int argc, char* argv[]){
    /* Initialise SDL2 and OpenGL */
    SDL2_InitWin();
    OGL_InitContext(SDL2_Win);

    /* Initialise an object, vertex specification */
    OGL_VertexObject o1;
    OGL_VertexObject o2;
    OGL_TriangleVertexF(o1);
    OGL_TriangleVertex2D(o2, 0.9f, 0.9f, -0.9f, -0.5f, 0.5f, 0.5f);

    /* Graphics pipeline fro shaders */
    GLuint shaderProg;
    shaderProg = OGL_CreateGraphicsPipeline(OGLS_PeakyV, OGLS_PeakyF);

    /* Main loop */
    bool SDL2_Quit = false;
    while(!SDL2_Quit){
        SDL2_HandleEvents(SDL2_Quit); /* Creates a new event to poll per call (Might need to be optimised) */

        /* Updates to assets / sprites */

        /* OpenGL rendering functions */
        OGL_PreDraw(shaderProg);
        OGL_DrawObject(o1);
        OGL_DrawObject(o2); /* We need to call the OGL_Draw(), to specifiy what Vertex Object to draw */

        SDL_GL_SwapWindow(SDL2_Win);
    }

    /* Cleanup */
    SDL_DestroyRenderer(SDL2_Rnd);
    SDL_DestroyWindow(SDL2_Win);
    SDL_Quit();

    return SUCCESS;
}
