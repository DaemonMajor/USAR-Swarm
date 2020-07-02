// Fill out your copyright notice in the Description page of Project Settings.


#include "MaintainHeightTask.h"
#include "USARAgent.h"
#include "AIController.h"

EBTNodeResult::Type UMaintainHeightTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());

    MoveToHeight(agent);

    return EBTNodeResult::Succeeded;
}

void UMaintainHeightTask::MoveToHeight(AUSARAgent* agent)
{
    float agentHeight = agent->GetActorLocation().Z;
    float targetHeight = agent->targetHeight;

    FVector correctionVector = FVector::ZeroVector;
    if (agentHeight < targetHeight) {
        correctionVector.Z = agent->maxSpeed/2;   // fly up at half max thrust
    }
    else if (agentHeight > targetHeight) {
        correctionVector.Z = -(agent->maxSpeed/2);   // fly down at half max thrust
    }

    agent->SetHeightVector(correctionVector);

    /*DEBUGGING*/
    //FString statusText = FString::Printf(TEXT("Agent %d maintaining height."), agent->agentID);
    //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Yellow, statusText, true);
    /*DEBUGGING*/
}