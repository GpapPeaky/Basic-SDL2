#pragma once

#include "SDL2_Images.hpp" /* For image data */
#include <cmath>           /* for atan2 and M_PI */

/**
 * @brief Entity fire universal range
 */
#define BSC_UNIVERSAL_RANGE 500.0f

typedef struct BSC_EntityFire{
    SDL2_Images entityFireImages;
    float projDeg;      /* Projectile angle */
    float projRange;    /* Projectile range */
}BSC_EntityFire;
