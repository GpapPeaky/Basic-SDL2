#pragma once

#include "BSC_EntityLevel.hpp"

/**
 * @brief NewStat += Stat / 10, with each level up
 */
#define BSC_LVL_REDUCTION_FACTOR 10

/**
 * @brief Entity stats struct, universal
 */
typedef struct BSC_EntityStats{
    BSC_EntityLevel level; /* Entity level */
    float baseAtt;         /* Base attack */
    float baseDef;         /* Base defence */
    float baseAttSpd;      /* Base attack speed (rate of fire) */
    float baseHP;          /* Base HP */
    float baseSpd;         /* Base speed (movement speed) */
    float baseProjSpd;     /* Base projectile speed */
}BSC_EntityStats;

/**
 * @brief Stat evaluation, multiplying per level, called after
 * each level up
 * 
 * @param entityStats Entity's stats
 * 
 * @returns The evaluated BSC_EntityStat struct of the entity
 */
BSC_EntityStats BSC_StatEvaluation(BSC_EntityStats entityStats);
