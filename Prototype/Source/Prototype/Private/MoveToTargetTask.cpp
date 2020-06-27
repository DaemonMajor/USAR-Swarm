// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveToTargetTask.h"
#include "BoidsAgent.h"
#include "AIController.h"

EBTNodeResult::Type UMoveToTargetTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    ABoidsAgent* agent = Cast<ABoidsAgent>(OwnerComp.GetAIOwner()->GetPawn());
<<<<<<< HEAD
    ASwarmWP* waypoint = agent->GetCurrWaypoint();
    
    if (waypoint) {
        FVector targetVector = waypoint->GetActorLocation() - targetVector;
    
        agent->SetVelocity(targetVector);
    }
=======
    
>>>>>>> parent of 6965bdd... Added waypoint handling. Waypoints still non-functional. Need to add function to add waypoints to agents on game start.

    return EBTNodeResult::Succeeded;
}