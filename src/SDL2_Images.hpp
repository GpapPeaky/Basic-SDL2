#pragma once

#include "../ThirdParty/SDL2/include/SDL2/SDL.h"
#include "../ThirdParty/SDL2/include/SDL2/SDL_image.h"

/**
 * @brief SDL2 image data
 */
typedef struct SDL2_Images{
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect position;
}SDL2_Images;
