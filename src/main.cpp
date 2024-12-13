#include "auxf/includes.aux"

int main(int argc, char* argv[]){

    SDL2_InitWin(); /* Initialise */
    OGL_InitContext(SDL2_Win);

    /* Initialise an object */
    GLuint vao1, vbo1;
    GLuint vao2, vbo2;
    OGL_TriangleVertexF(vao1, vbo1);
    OGL_TriangleVertex2D(vao2, vbo2, 0.9f, 0.9f, -0.9f, -0.5f, 0.5f, 0.5f);

    GLuint shaderProg;
    shaderProg = OGL_CreateGraphicsPipeline(OGLS_PeakyV, OGLS_PeakyF);

    bool SDL2_Quit = false;
    while(!SDL2_Quit){
        SDL2_HandleEvents(SDL2_Quit); /* Creates a new event to poll per call (Might need to be optimised) */

        /* Updates to assets / sprites */

        /* OpenGL rendering functions */
        OGL_PreDraw(shaderProg);
        OGL_Draw(vao1, vbo1);
        OGL_Draw(vao2, vbo2);

        SDL_GL_SwapWindow(SDL2_Win);
    }

    SDL_DestroyRenderer(SDL2_Rnd);
    SDL_DestroyWindow(SDL2_Win);
    SDL_Quit();

    return SUCCESS;
}
