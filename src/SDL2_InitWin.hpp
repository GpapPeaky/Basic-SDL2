#pragma once

#include "../ThirdParty/SDL2/include/SDL2/SDL.h"
#include "../ThirdParty/SDL2/include/SDL2/SDL_image.h"

#include <iostream>

#define SUCCESS 0
#define FAILURE -1

#define WIN_W 900
#define WIN_H 800

extern SDL_Window* SDL2_Win;
extern SDL_Renderer* SDL2_Rnd;

/**
 * @brief Initialises the renderer, the window, and the SDL/IMG modes required
*/
int SDL2_InitWin(void);
