#include "SDL2_Event.hpp"

void SDL2_HandleEvents(bool& quit, float dt){
    SDL_Event e;
    static bool mousePressed = false;
    static Uint32 lastFireTime = 0;

    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_e))){
            quit = true;
        }else if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT){
            mousePressed = true;
        }else if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT){
            mousePressed = false;
        }
    }

    if(mousePressed){
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        Uint32 currentTime = SDL_GetTicks();
        Uint32 fireDelay = 1000 / BSC_Entities[PLAYER][0]->stats.baseAttSpd;

        if(currentTime - lastFireTime >= fireDelay){
            BSC_EntityFiring(BSC_Entities[PLAYER][0], mouseX, mouseY);
            lastFireTime = currentTime;
        }
    }

    return;
}

void SDL2_HandlePlayerMovement(BSC_Entity* entity, float dt){
    float moveX = 0.0f;
    float moveY = 0.0f;
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);

    if(keystate[SDL_SCANCODE_W]){ // Move up
        moveY -= 1.0f;
    }
    if(keystate[SDL_SCANCODE_S]){ // Move down

        moveY += 1.0f;
    }
    if(keystate[SDL_SCANCODE_A]){ // Move left
        moveX -= 1.0f;
    }
    if(keystate[SDL_SCANCODE_D]){ // Move right
        moveX += 1.0f;
    }

    /* Normalize diagonal movement */
    float magnitude = std::sqrt(moveX * moveX + moveY * moveY);
    if(magnitude > 0.0f){
        moveX /= magnitude;
        moveY /= magnitude;
    }


    /* Update position using base speed and delta time */
    entity->img.position.x += (moveX * entity->stats.baseSpd * dt);
    entity->img.position.y += (moveY * entity->stats.baseSpd * dt);

    return;
}
