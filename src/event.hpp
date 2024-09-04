#include "SDL.h"


#ifndef __EVENT_H__
#define __EVENT_H__

/**
 * @brief Handles main loop events
 * 
 * @param quit Checks if we have quit the main loop
 * @param e Event executed
 */
void handle_events(int quit, SDL_Event e);

#endif
