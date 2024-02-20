#include "include.aux"
#include "SDL.h"
#include "SDL_image.h"

#ifndef INIT_WINDOW
#define INIT_WINDOW

extern SDL_Window * win;
extern SDL_Renderer * rnd;

/**
 * @brief Initialises the renderer, the window, and the SDL/IMG modes required
*/
INITIALISER init_win();

#endif