// Fill out your copyright notice in the Description page of Project Settings.


#include "SpiralSearchTask.h"
#include "USARAgent.h"
#include "AIController.h"

EBTNodeResult::Type USpiralSearchTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());

    FVector waypoint;
    agent->GetSearchWP(waypoint);
    
    if (FVector::PointsAreNear(agent->GetActorLocation(), waypoint, 5)) {
        agent->RemoveSearchWP();
        
        if (!agent->GetSearchWP(waypoint)) {
            waypoint = agent->GetActorLocation();
            agent->statusActiveSearch = false;
        }

        /*DEBUGGING*/
        if (agent->showDebug) {
            FString wpRemovedText = FString::Printf(TEXT("Agent %d reached search waypoint."), agent->agentID);
            GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, wpRemovedText, true);
        }
        /*DEBUGGING*/
    }

    FVector targetVector = waypoint - agent->GetActorLocation();
    targetVector = targetVector.GetClampedToSize(agent->searchSpeed, agent->searchSpeed);

    agent->SetSearchVector(targetVector);

    return EBTNodeResult::Succeeded;
}