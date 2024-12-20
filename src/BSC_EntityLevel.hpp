#pragma once

/**
 * @brief Flags for no xp remaining
 */
#define BSC_NO_XP -1

/**
 * @brief Entity level struct
 */
typedef struct BSC_EntityLevel{
    unsigned int level;         /* Entity level */
    int remainingXp;            /* Remaining xp points required for a level up */
    int baseLevelUpThreshold;   /* Base xp points required for a level up */
    unsigned int xpOnDeath;     /* Xp drop */
}BSC_EntityLevel;
