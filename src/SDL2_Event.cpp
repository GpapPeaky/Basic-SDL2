#include "SDL2_Event.hpp"

void SDL2_HandleEvents(bool& quit){
    SDL_Event e;

    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_e))){
            quit = true;
        }

        SDL2_HandlePlayerMovement(BSC_Entities[PLAYER][0], e);
    }

    return;
}

void SDL2_HandlePlayerMovement(BSC_Entity* entity, SDL_Event e){
    if(e.type == SDL_KEYDOWN || e.type == SDL_KEYUP){
        bool keyPressed = (e.type == SDL_KEYDOWN);

        switch(e.key.keysym.sym){
            case SDLK_w: // Move up
                if(keyPressed) entity->img.position.y -= entity->stats.baseSpd;
                break;

            case SDLK_s: // Move down
                if(keyPressed) entity->img.position.y += entity->stats.baseSpd;
                break;

            case SDLK_a: // Move left
                if(keyPressed) entity->img.position.x -= entity->stats.baseSpd;
                break;

            case SDLK_d: // Move right
                if(keyPressed) entity->img.position.x += entity->stats.baseSpd;
                break;

            default:
                break;
        }
    }

    return;
}
