#pragma once

#include "../ThirdParty/SDL2/include/SDL2/SDL.h"
#include "../ThirdParty/SDL2/include/SDL2/SDL_image.h"

/**
 * @brief SDL2 image data
 */
typedef struct SDL2_Images{
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_FRect position;
}SDL2_Images;
