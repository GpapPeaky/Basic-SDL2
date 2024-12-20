#pragma once

#include "SDL2_Images.hpp"
#include "SDL2_InitWin.hpp"     /* For the renderer */
#include "BSC_EntityStats.hpp" 
#include "BSC_EntityFire.hpp" 
#include <iostream>
#include <vector>
#include <unordered_map>

#define BSC_UNIVERSAL_ENTITY_SIZE_FACTOR 2.1f

/**
 * @brief Entity type enumerators
 */
typedef enum BSC_EntityType{
    /* Player */
    PLAYER,
    /* Basic Slimes */
    GREEN_SLIME,
    BLUE_SLIME,
    RED_SLIME,
    PURPLE_SLIME,
    BLACK_SLIME,
    /* Green Slimes */
    GREEN_SLIME_THIEF,
    GREEN_SLIME_WARRIOR,
    GREEN_SLIME_ARCHER,
    GREEN_SLIME_KNIGHT,
    GREEN_SLIME_SOLDIER,
    GREEN_SLIME_GENERAL,
    /* Blue Slimes */
    BLUE_SLIME_THIEF,
    BLUE_SLIME_WARRIOR,
    BLUE_SLIME_ARCHER,
    BLUE_SLIME_KNIGHT,
    BLUE_SLIME_SOLDIER,
    BLUE_SLIME_GENERAL,
    /* Goblins */
    GOBLIN,
    GOBLIN_THIEF,
    GOBLIN_WARRIOR,
    GOBLIN_ARCHER,
    GOBLIN_KNIGHT,
    GOBLIN_SOLDIER,
    GOBLIN_GENERAL,
    /* Red Slimes */
    RED_SLIME_THIEF,
    RED_SLIME_WARRIOR,
    RED_SLIME_ARCHER,
    RED_SLIME_KNIGHT,
    RED_SLIME_SOLDIER,
    RED_SLIME_GENERAL,
    /* Purple Slimes */
    PURPLE_SLIME_THIEF,
    PURPLE_SLIME_WARRIOR,
    PURPLE_SLIME_ARCHER,
    PURPLE_SLIME_KNIGHT,
    PURPLE_SLIME_SOLDIER,
    PURPLE_SLIME_GENERAL,
    /* Black Slimes */
    BLACK_SLIME_THIEF,
    BLACK_SLIME_WARRIOR,
    BLACK_SLIME_ARCHER,
    BLACK_SLIME_KNIGHT,
    BLACK_SLIME_SOLDIER,
    BLACK_SLIME_GENERAL,
}BSC_EntityType;

/**
 * @brief Max amount of entities
 */
#define MAX_ENTITIES BLACK_SLIME_GENERAL

/**
 * @brief Entity abstraction
 */
typedef struct BSC_Entity{
    SDL2_Images img;        /* Image data */
    BSC_EntityStats stats;  /* Stats and level info */
    BSC_EntityType type;    /* Entity type */
    std::vector<BSC_EntityFire*> fire;
    unsigned int Id;        /* Entity id */
}BSC_Entity;

/**
 * @brief Sorted by enemy type, includes a vector of enemies per type
 */
extern std::unordered_map<BSC_EntityType, std::vector<BSC_Entity*>> BSC_Entities;

/**
 * @brief Creates a new entity, based on a predefined type
 * 
 * @param entityType Type of entity
 * 
 * @returns The created entity
 */
BSC_Entity* BSC_CreateEntity(BSC_EntityType entityType, unsigned int level);

/**
 * @brief Renders a specified entity, along with it's votes
 * 
 * @param entity Entity to render
 * @param vectorIdx Vector idx
 */
void BSC_RenderEntity(BSC_Entity* entity, unsigned int vectorIdx);

/**
 * @brief Renders all entities, along with their bullets
 */
void BSC_RenderEntities(void);

/**
 * @brief Entity fire function
 * 
 * @param entity Entity to fire
 * @param mouseX Mouse X coordinate
 * @param mouseY Mouse Y coordinate
 */
void BSC_EntityFiring(BSC_Entity* entity, int mouseX, int mouseY);

/**
 * @brief Updates the fire of an entity
 * 
 * @param entity Entity to update
 * @param dt deltatime
 */
void BSC_UpdateEntityFire(BSC_Entity* entity, float dt);
