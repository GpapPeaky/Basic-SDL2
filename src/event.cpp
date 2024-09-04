#include "event.hpp"

void handle_events(int quit, SDL_Event e){
    while(SDL_PollEvent(&e) != 0){
        if(e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_e){
            quit = 1;
        }
    }

    return;
}