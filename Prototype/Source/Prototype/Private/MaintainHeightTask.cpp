// Fill out your copyright notice in the Description page of Project Settings.


#include "MaintainHeightTask.h"
#include "BoidsAgent.h"
#include "AIController.h"

EBTNodeResult::Type UMaintainHeightTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    ABoidsAgent* agent = Cast<ABoidsAgent>(OwnerComp.GetAIOwner()->GetPawn());
    MoveToHeight(agent);

    return EBTNodeResult::Succeeded;
}

void UMaintainHeightTask::MoveToHeight(ABoidsAgent* agent)
{
    float agentHeight = agent->GetActorLocation().Z;
    float minHeight = agent->targetHeight - agent->heightVariance;
    float maxHeight = agent->targetHeight + agent->heightVariance;

    FVector agentVel = agent->GetVelocity();
    if (agentHeight < minHeight) {
        agentVel.Z = agent->maxSpeed/2;   // fly up at half max thrust

        /*DEBUGGING*/
        //FString climbingText = FString::Printf(TEXT("Agent %d climbing from %f."), agent->agentID, agentHeight);
        //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Green, climbingText, true);
        /*DEBUGGING*/
    }
    else if (agentHeight > maxHeight) {
        agentVel.Z = -(agent->maxSpeed/2);   // fly down at half max thrust

        /*DEBUGGING*/
        //FString fallingText = FString::Printf(TEXT("Agent %d falling from %f."), agent->agentID, agentHeight);
        //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Green, fallingText, true);
        /*DEBUGGING*/
    }

    agent->SetVelocity(agentVel);

    /*DEBUGGING*/
    //FString statusText = FString::Printf(TEXT("Agent %d maintaining height."), agent->agentID);
    //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Green, statusText, true);
    /*DEBUGGING*/
}