#include "../ThirdParty/SDL2/include/SDL2/SDL.h"
#include "../ThirdParty/SDL2/include/SDL2/SDL_image.h"
#include <iostream>

#ifndef __SDL2_INITWIN_HPP__
#define __SDL2_INITWIN_HPP__

#define SUCCESS 0
#define FAILURE -1

extern SDL_Window* SDL2_Win;
extern SDL_Renderer* SDL2_Rnd;

/**
 * @brief Initialises the renderer, the window, and the SDL/IMG modes required
 * 
 * @returns 0 on success, -1 on failure
*/
int SDL2_InitWin(void);

#endif
