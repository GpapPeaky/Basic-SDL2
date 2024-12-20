#include "BSC_EntityStats.hpp"

BSC_EntityStats BSC_StatEvaluation(BSC_EntityStats entityStats){
    entityStats.baseAtt += entityStats.baseAtt * (entityStats.level.level / BSC_LVL_REDUCTION_FACTOR);
    entityStats.baseDef += entityStats.baseDef * (entityStats.level.level / BSC_LVL_REDUCTION_FACTOR);
    entityStats.baseAttSpd +=  entityStats.baseAttSpd * (entityStats.level.level / BSC_LVL_REDUCTION_FACTOR);
    entityStats.baseHP += entityStats.baseHP * (entityStats.level.level / BSC_LVL_REDUCTION_FACTOR);
    entityStats.baseSpd += entityStats.baseSpd * (entityStats.level.level / BSC_LVL_REDUCTION_FACTOR);
    entityStats.baseProjSpd += entityStats.baseProjSpd * (entityStats.level.level / BSC_LVL_REDUCTION_FACTOR);
    
    return entityStats;
}
