#include "BSC_Entity.hpp"

std::unordered_map<BSC_EntityType, std::vector<BSC_Entity*>> BSC_Entities;
static int BSC_EntityCount = 0;

BSC_Entity* BSC_CreateEntity(BSC_EntityType entityType, unsigned int level){
    BSC_Entity* entity = new BSC_Entity;

    switch(entityType){
        case PLAYER:
            entity->img.surface = IMG_Load("assets/player.png");
            entity->img.texture = SDL_CreateTextureFromSurface(SDL2_Rnd, entity->img.surface);
            entity->img.position = {0, 0, entity->img.surface->w * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR, entity->img.surface->h * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = 100;
            entity->stats.level.baseLevelUpThreshold = 100;
            entity->stats.level.xpOnDeath = 0;
            entity->stats.baseAtt = 10.0f;
            entity->stats.baseDef = 5.0f;
            entity->stats.baseAttSpd = 1.0f;
            entity->stats.baseHP = 100.0f;
            entity->stats.baseSpd = 5.0f;
            break;

        case GREEN_SLIME:
            entity->img.surface = NULL; // Initialize SDL_Surface pointer for green slime
            entity->img.texture = NULL; // Initialize SDL_Texture pointer for green slime
            entity->img.position = {0, 0, entity->img.surface->w, entity->img.surface->h};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 7;
            entity->stats.baseAtt = 2.0f;
            entity->stats.baseDef = 1.0f;
            entity->stats.baseAttSpd = 0.4f;
            entity->stats.baseHP = 10.0f;
            entity->stats.baseSpd = 2.0f;
            break;

        case BLUE_SLIME:
            entity->img.surface = NULL; // Initialize SDL_Surface pointer for blue slime
            entity->img.texture = NULL; // Initialize SDL_Texture pointer for blue slime
            entity->img.position = {0, 0, entity->img.surface->w, entity->img.surface->h};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 9;
            entity->stats.baseAtt = 2.5f;
            entity->stats.baseDef = 1.0f;
            entity->stats.baseAttSpd = 0.5f;
            entity->stats.baseHP = 11.0f;
            entity->stats.baseSpd = 2.0f;
            break;

        case RED_SLIME:
            entity->img.surface = NULL; // Initialize SDL_Surface pointer for red slime
            entity->img.texture = NULL; // Initialize SDL_Texture pointer for red slime
            entity->img.position = {0, 0, entity->img.surface->w, entity->img.surface->h};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 10;
            entity->stats.baseAtt = 2.5f;
            entity->stats.baseDef = 1.0f;
            entity->stats.baseAttSpd = 0.5f;
            entity->stats.baseHP = 11.5f;
            entity->stats.baseSpd = 2.0f;
            break;

        case PURPLE_SLIME:
            entity->img.surface = NULL; // Initialize SDL_Surface pointer for red slime
            entity->img.texture = NULL; // Initialize SDL_Texture pointer for red slime
            entity->img.position = {0, 0, entity->img.surface->w, entity->img.surface->h};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 13;
            entity->stats.baseAtt = 2.5f;
            entity->stats.baseDef = 1.0f;
            entity->stats.baseAttSpd = 0.5f;
            entity->stats.baseHP = 13.0f;
            entity->stats.baseSpd = 2.0f;
            break;

        case BLACK_SLIME:
            entity->img.surface = NULL; // Initialize SDL_Surface pointer for red slime
            entity->img.texture = NULL; // Initialize SDL_Texture pointer for red slime
            entity->img.position = {0, 0, entity->img.surface->w, entity->img.surface->h};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 16;
            entity->stats.baseAtt = 3.0f;
            entity->stats.baseDef = 1.0f;
            entity->stats.baseAttSpd = 0.5f;
            entity->stats.baseHP = 13.0f;
            entity->stats.baseSpd = 2.0f;
            break;
        
        default:
            // Handle unknown or uninitialized type
            entity->img.surface = NULL;
            entity->img.texture = NULL;
            entity->img.position = {0, 0, entity->img.surface->w, entity->img.surface->h};
            entity->stats.level.level = 0;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 0;
            entity->stats.baseAtt = 0.0f;
            entity->stats.baseDef = 0.0f;
            entity->stats.baseAttSpd = 0.0f;
            entity->stats.baseHP = 0.0f;
            entity->stats.baseSpd = 0.0f;
            std::fprintf(stderr, "Unkown Entity Type\n");
            break;
    }

    SDL_FreeSurface(entity->img.surface); /* Free the surface */

    entity->Id = BSC_EntityCount++;
    entity->type = entityType;
    entity->stats = BSC_StatEvaluation(entity->stats); /* Evaluate the entity's stats */

    /* Add the entity inside the unordered map of vectors */
    BSC_Entities[entity->type].push_back(entity);

    return entity;
}
