// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveToTargetTask.h"
#include "BoidsAgent.h"
#include "AIController.h"

EBTNodeResult::Type UMoveToTargetTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    ABoidsAgent* agent = Cast<ABoidsAgent>(OwnerComp.GetAIOwner()->GetPawn());

    ASwarmWP* waypoint = agent->GetCurrWaypoint();
    
    if (waypoint) {
        FVector targetVector = waypoint->GetActorLocation() - agent->GetActorLocation();
        FVector currVector = agent->GetVelocity();
    
        agent->SetVelocity(currVector + targetVector);
    }

    return EBTNodeResult::Succeeded;
}