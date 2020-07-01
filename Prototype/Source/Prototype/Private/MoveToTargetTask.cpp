// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveToTargetTask.h"
#include "BoidsAgent.h"
#include "AIController.h"

EBTNodeResult::Type UMoveToTargetTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    ABoidsAgent* agent = Cast<ABoidsAgent>(OwnerComp.GetAIOwner()->GetPawn());

    ASwarmWP* waypoint = agent->GetCurrWaypoint();
    FVector targetVector = FVector::ZeroVector;
    if (waypoint) {
        FVector wpLoc = waypoint->GetActorLocation();
        wpLoc.Z = agent->targetHeight;

        targetVector = wpLoc - agent->GetActorLocation();
        targetVector = targetVector.GetClampedToSize(agent->maxSpeed * 3, agent->maxSpeed * 3);     // set magnitude so agent doesn't slow down as it nears the waypoint
    }

    agent->SetWaypointVector(targetVector);

    return EBTNodeResult::Succeeded;
}