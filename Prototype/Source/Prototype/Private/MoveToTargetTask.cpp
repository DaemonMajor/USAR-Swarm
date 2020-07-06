// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveToTargetTask.h"
#include "USARAgent.h"
#include "AIController.h"

EBTNodeResult::Type UMoveToTargetTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());

    FVector waypoint;
    FVector targetVector = FVector::ZeroVector;
    if (agent->GetCurrWaypoint(waypoint)) {
        waypoint.Z = agent->targetHeight;

        targetVector = waypoint - agent->GetActorLocation();
        targetVector = targetVector.GetClampedToSize(agent->maxSpeed * 3, agent->maxSpeed * 3);     // set magnitude so agent doesn't slow down as it nears the waypoint
    }

    agent->SetWaypointVector(targetVector);

    return EBTNodeResult::Succeeded;
}