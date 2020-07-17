// Fill out your copyright notice in the Description page of Project Settings.


#include "D_AgentsLeftToSpawn.h"
#include "SwarmSpawnPoint.h"
#include "AIController.h"

bool UD_AgentsLeftToSpawn::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    ASwarmSpawnPoint* spawn = Cast<ASwarmSpawnPoint>(OwnerComp.GetAIOwner()->GetPawn());
    
    bool shouldSpawn;
    if (spawn->numAgentsToSpawn) {
        shouldSpawn = true;
    }
    else {
        shouldSpawn = false;
    }

    return shouldSpawn;
}