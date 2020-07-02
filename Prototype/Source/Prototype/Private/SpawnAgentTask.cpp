// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnAgentTask.h"
#include "USARAgent.h"
#include "../PrototypeGameState.h"
#include "AIController.h"

EBTNodeResult::Type USpawnAgentTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    ASwarmSpawnPoint* spawn = Cast<ASwarmSpawnPoint>(OwnerComp.GetAIOwner()->GetPawn());
    static APrototypeGameState* gameState = GetWorld()->GetGameState<APrototypeGameState>();

    FVector agentPos = GetRandLoc(spawn);
    FRotator zeroRot;

    AUSARAgent* agent = GetWorld()->SpawnActor<AUSARAgent>(agentPos, zeroRot);
    agent->AssignToFlock(1);

    spawn->numAgentsToSpawn--;

    return EBTNodeResult::Succeeded;
}

/* Get random location in semisphere above spawn point's center.
*
*   @param spawn SwarmSpawnPoint to use.
*   @return Vector in vicinity of the spawn point, restricted by the spawn point's spawnRadius.
*/
FVector USpawnAgentTask::GetRandLoc(ASwarmSpawnPoint* spawn)
{
    float maxRange = spawn->spawnRadius;
    float xPos = FMath::FRandRange(-maxRange, maxRange);
    float yPos = FMath::FRandRange(-maxRange, maxRange);
    float zPos = FMath::FRandRange(0, maxRange);

    FVector spawnPos = FVector(xPos, yPos, zPos).GetClampedToSize(0, maxRange);

    return spawnPos;
}