#include "BSC_Entity.hpp"

std::unordered_map<BSC_EntityType, std::vector<BSC_Entity*>> BSC_Entities;
static int BSC_EntityCount = 0;

BSC_Entity* BSC_CreateEntity(BSC_EntityType entityType, unsigned int level){
    BSC_Entity* entity = new BSC_Entity;

    switch(entityType){
        case PLAYER:
            entity->img.surface = IMG_Load("assets/gfx/entity/player.png");
            entity->img.texture = SDL_CreateTextureFromSurface(SDL2_Rnd, entity->img.surface);
            entity->img.position = {0, 0, static_cast<float>(entity->img.surface->w * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR), 
            static_cast<float>(entity->img.surface->h * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR)};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = 100;
            entity->stats.level.baseLevelUpThreshold = 100;
            entity->stats.level.xpOnDeath = 0;
            entity->stats.baseAtt = 10.0f;
            entity->stats.baseDef = 5.0f;
            entity->stats.baseAttSpd = 3.0f;
            entity->stats.baseHP = 100.0f;
            entity->stats.baseSpd = 85.0f;
            entity->stats.baseProjSpd = 150.0f;
            break;

        case GREEN_SLIME:
            entity->img.surface = IMG_Load("assets/gfx/entity/green_slime.png"); // Initialize SDL_Surface pointer for green slime
            entity->img.texture = SDL_CreateTextureFromSurface(SDL2_Rnd, entity->img.surface);
            entity->img.position = {0, 0, static_cast<float>(entity->img.surface->w) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR, 
            static_cast<float>(entity->img.surface->h) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 7;
            entity->stats.baseAtt = 2.0f;
            entity->stats.baseDef = 1.0f;
            entity->stats.baseAttSpd = 0.4f;
            entity->stats.baseHP = 10.0f;
            entity->stats.baseSpd = 75.0f;
            entity->stats.baseProjSpd = 80.0f;
            break;

        case BLUE_SLIME:
            entity->img.surface = IMG_Load("assets/gfx/entity/blue_slime.png");
            entity->img.texture = SDL_CreateTextureFromSurface(SDL2_Rnd, entity->img.surface);
            entity->img.position = {0, 0, static_cast<float>(entity->img.surface->w) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR, 
            static_cast<float>(entity->img.surface->h) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 9;
            entity->stats.baseAtt = 2.5f;
            entity->stats.baseDef = 1.0f;
            entity->stats.baseAttSpd = 0.5f;
            entity->stats.baseHP = 11.0f;
            entity->stats.baseSpd = 75.0f;
            entity->stats.baseProjSpd = 80.0f;
            break;

        case RED_SLIME:
            entity->img.surface = IMG_Load("assets/gfx/entity/red_slime.png"); 
            entity->img.texture = SDL_CreateTextureFromSurface(SDL2_Rnd, entity->img.surface); 
            entity->img.position = {0, 0, static_cast<float>(entity->img.surface->w) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR, 
            static_cast<float>(entity->img.surface->h) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 10;
            entity->stats.baseAtt = 2.5f;
            entity->stats.baseDef = 1.0f;
            entity->stats.baseAttSpd = 0.5f;
            entity->stats.baseHP = 11.5f;
            entity->stats.baseSpd = 75.0f;
            entity->stats.baseProjSpd = 80.0f;
            break;

        case PURPLE_SLIME:
            entity->img.surface = IMG_Load("assets/gfx/entity/purple_slime.png"); 
            entity->img.texture = SDL_CreateTextureFromSurface(SDL2_Rnd, entity->img.surface); 
            entity->img.position = {0, 0, static_cast<float>(entity->img.surface->w) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR, 
            static_cast<float>(entity->img.surface->h) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 13;
            entity->stats.baseAtt = 2.5f;
            entity->stats.baseDef = 1.0f;
            entity->stats.baseAttSpd = 0.5f;
            entity->stats.baseHP = 13.0f;
            entity->stats.baseSpd = 75.0f;
            entity->stats.baseProjSpd = 80.0f;
            break;

        case BLACK_SLIME:
            entity->img.surface = IMG_Load("assets/gfx/entity/black_slime.png"); 
            entity->img.texture = SDL_CreateTextureFromSurface(SDL2_Rnd, entity->img.surface); 
            entity->img.position = {0, 0, static_cast<float>(entity->img.surface->w) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR, 
            static_cast<float>(entity->img.surface->h) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 16;
            entity->stats.baseAtt = 3.0f;
            entity->stats.baseDef = 1.0f;
            entity->stats.baseAttSpd = 0.5f;
            entity->stats.baseHP = 14.0f;
            entity->stats.baseSpd = 75.0f;
            entity->stats.baseProjSpd = 80.0f;
            break;

        case GREEN_SLIME_THIEF:
            entity->img.surface = IMG_Load("assets/gfx/entity/green_slime_thief.png"); 
            entity->img.texture = SDL_CreateTextureFromSurface(SDL2_Rnd, entity->img.surface);
            entity->img.position = {0, 0, static_cast<float>(entity->img.surface->w) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR, 
            static_cast<float>(entity->img.surface->h) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 19;
            entity->stats.baseAtt = 3.5f;
            entity->stats.baseDef = 1.0f;
            entity->stats.baseAttSpd = 0.5f;
            entity->stats.baseHP = 14.5f;
            entity->stats.baseSpd = 75.0f;
            entity->stats.baseProjSpd = 80.0f;
            break;

        case GREEN_SLIME_WARRIOR:
            entity->img.surface = IMG_Load("assets/gfx/entity/green_slime_warrior.png"); 
            entity->img.texture = SDL_CreateTextureFromSurface(SDL2_Rnd, entity->img.surface);
            entity->img.position = {0, 0, static_cast<float>(entity->img.surface->w) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR, 
            static_cast<float>(entity->img.surface->h) * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR};
            entity->stats.level.level = level;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 16;
            entity->stats.baseAtt = 3.5f;
            entity->stats.baseDef = 1.5f;
            entity->stats.baseAttSpd = 0.3f;
            entity->stats.baseHP = 14.5f;
            entity->stats.baseSpd = 75.0f;
            entity->stats.baseProjSpd = 80.0f;
            break;
        
        default:
            // Handle unknown or uninitialized type
            entity->img.surface = IMG_Load("assets/gfx/entity/_plc.bmp"); 
            entity->img.texture = SDL_CreateTextureFromSurface(SDL2_Rnd, entity->img.surface);
            entity->img.position = {0, 0, static_cast<float>(entity->img.surface->w), 
            static_cast<float>(entity->img.surface->h)};
            entity->img.position = {0, 0, static_cast<float>(entity->img.surface->w), 
            static_cast<float>(entity->img.surface->h)};
            entity->stats.level.level = 0;
            entity->stats.level.remainingXp = BSC_NO_XP;
            entity->stats.level.baseLevelUpThreshold = BSC_NO_XP;
            entity->stats.level.xpOnDeath = 0;
            entity->stats.baseAtt = 0.0f;
            entity->stats.baseDef = 0.0f;
            entity->stats.baseAttSpd = 0.0f;
            entity->stats.baseHP = 0.0f;
            entity->stats.baseSpd = 0.0f;
            entity->stats.baseProjSpd = 0.0f;
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

void BSC_RenderEntity(BSC_Entity* entity, unsigned int vectorIdx){
    if(entity == NULL){
        fprintf(stderr, "No entity found\n");
    }
    SDL_RenderCopyF(SDL2_Rnd, BSC_Entities[entity->type][vectorIdx]->img.texture, NULL, &BSC_Entities[entity->type][vectorIdx]->img.position);

    for(const auto& bullet : BSC_Entities[entity->type][vectorIdx]->fire){
        if(bullet && bullet->entityFireImages.texture){
            SDL_FPoint center = {
                bullet->entityFireImages.position.w / 2.0f,
                bullet->entityFireImages.position.h / 2.0f 
            };

            SDL_RenderCopyExF(
                SDL2_Rnd,                                /* Renderer */
                bullet->entityFireImages.texture,        /* Bullet texture */
                nullptr,                                 /* Source rectangle (use the whole texture) */
                &bullet->entityFireImages.position,      /* Destination rectangle */
                bullet->projDeg,                         /* Rotation angle */
                &center,                                 /* Rotation center point */
                SDL_FLIP_NONE                            /* No flipping */
            );
        }
    }

    return;
}

void BSC_RenderEntities(void){
    for(const auto& [entityType, entityVector] : BSC_Entities){ // Use structured binding in C++17 or later
        for(size_t i = 0 ; i < entityVector.size() ; ++i){
            BSC_RenderEntity(entityVector[i], i);
        }
    }

    return;
}

void BSC_EntityFiring(BSC_Entity* entity, int mouseX, int mouseY){
    BSC_EntityFire* newFire = new  BSC_EntityFire;
    newFire->projRange = BSC_UNIVERSAL_RANGE;

    newFire->entityFireImages.surface = IMG_Load("assets/gfx/fire/player.png");
    newFire->entityFireImages.texture = SDL_CreateTextureFromSurface(SDL2_Rnd, newFire->entityFireImages.surface);

    /* Spawn on top of the entity, initial position */
    newFire->entityFireImages.position.x = entity->img.position.x + 20;
    newFire->entityFireImages.position.y = entity->img.position.y + 20;
    newFire->entityFireImages.position.w = newFire->entityFireImages.surface->w * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR;
    newFire->entityFireImages.position.h = newFire->entityFireImages.surface->h * BSC_UNIVERSAL_ENTITY_SIZE_FACTOR;

    /* Calculate the fire's angle, based on the mouse position */
    float deltaX = mouseX - entity->img.position.x;
    float deltaY = mouseY - entity->img.position.y;
    newFire->projDeg = atan2(deltaY, deltaX) * (180.0 / M_PI);

    if(newFire->projDeg < 0){
        newFire->projDeg += 360.0f;
    }

    SDL_FreeSurface(newFire->entityFireImages.surface);
    entity->fire.push_back(newFire); /* Add this to the entity's fire vector */

    return;
}

void BSC_UpdateEntityFire(BSC_Entity* entity, float deltaTime){
    for(auto it = entity->fire.begin(); it != entity->fire.end();){
        auto& fire = *it;

        float angleRad = fire->projDeg * (M_PI / 180.0f);
        float deltaX = std::cos(angleRad) * entity->stats.baseProjSpd * deltaTime;
        float deltaY = std::sin(angleRad) * entity->stats.baseProjSpd * deltaTime;

        fire->entityFireImages.position.x += deltaX;
        fire->entityFireImages.position.y += deltaY;

        float distanceTraveled = std::sqrt(deltaX * deltaX + deltaY * deltaY);
        fire->projRange -= distanceTraveled;

        if(fire->projRange <= 0){
            SDL_DestroyTexture(fire->entityFireImages.texture);
            delete *it;
            it = entity->fire.erase(it); /* Erase the pointer from the vector, deallocated with smart pointer */
        }else{
            ++it;
        }
    }
}
