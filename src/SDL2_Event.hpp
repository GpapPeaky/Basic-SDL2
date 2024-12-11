#include "../ThirdParty/SDL2/include/SDL2/SDL.h"

#ifndef __SDL2_EVENT_HPP__
#define __SDL2_EVENT_HPP__

/**
 * @brief Handles main loop events
 * 
 * @param quit Checks if we have quit the main loop
 */
void SDL2_HandleEvents(bool& quit);

#endif
