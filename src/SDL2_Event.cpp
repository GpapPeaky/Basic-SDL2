#include "SDL2_Event.hpp"

void SDL2_HandleEvents(bool& quit, OGL_VertexObject& object){
    SDL_Event e;

    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_e))){
            quit = true;
        }else if(e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_w)){
            OGL_UpdateObjectPosition(object, 0.0f, -0.001f, 0.0f); /* Change in y, not x,z. Quad will move up */
        }else if(e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_a)){
            OGL_UpdateObjectPosition(object, -0.001f, 0.0f, 0.0f); /* Change in x, not y,z. Quad will move to the left */
        }else if(e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_s)){
            OGL_UpdateObjectPosition(object, 0.0f, 0.001f, 0.0f); /* Change in y, not x,z. Quad will move down */
        }else if(e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_d)){
            OGL_UpdateObjectPosition(object, 0.001f, 0.0f, 0.0f); /* Change in x, not y,z. Quad will move to the right */
        }
    }

    return;
}
