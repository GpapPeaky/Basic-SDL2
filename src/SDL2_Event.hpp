#include "../ThirdParty/SDL2/include/SDL2/SDL.h"
#include "BSC_Entity.hpp"

#ifndef __SDL2_EVENT_HPP__
#define __SDL2_EVENT_HPP__

/**
 * @brief Handles main loop events
 * 
 * @param quit Checks if we have quit the main loop
 */
void SDL2_HandleEvents(bool& quit);

/**
 * @brief Handle the player movement
 * 
 * @param entity Player Entity
 * @param e Event
 */
void SDL2_HandlePlayerMovement(BSC_Entity* entity, SDL_Event e);

#endif
