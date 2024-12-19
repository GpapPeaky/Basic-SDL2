#include "../ThirdParty/SDL2/include/SDL2/SDL.h"
#include "BSC_Entity.hpp"
#include <math.h>

#ifndef __SDL2_EVENT_HPP__
#define __SDL2_EVENT_HPP__

/**
 * @brief Handles main loop events
 * 
 * @param quit Checks if we have quit the main loop
 * @param dt Delta time
 */
void SDL2_HandleEvents(bool& quit, float dt);

/**
 * @brief Handle the player movement
 * 
 * @param entity Player Entity
 * @param dt Delta time for smoother movement
 */
void SDL2_HandlePlayerMovement(BSC_Entity* entity, float dt);

#endif
