#include "include.aux"
#include "SDL.h"
#include "SDL_image.h"

#ifndef __INIT_WIN_H__
#define __INIT_WIN_H__

extern SDL_Window * win;
extern SDL_Renderer * rnd;

/**
 * @brief Initialises the renderer, the window, and the SDL/IMG modes required
*/
INITIALISER init_win();

#endif