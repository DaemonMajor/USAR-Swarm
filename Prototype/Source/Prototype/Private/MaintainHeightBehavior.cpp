// Fill out your copyright notice in the Description page of Project Settings.


#include "MaintainHeightBehavior.h"
#include "BoidsAgent.h"
#include "AIController.h"

UMaintainHeightBehavior::UMaintainHeightBehavior()
{
    bNotifyBecomeRelevant = true;
}

void UMaintainHeightBehavior::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::OnBecomeRelevant(OwnerComp, NodeMemory);

    ABoidsAgent* agent = Cast<ABoidsAgent>(OwnerComp.GetAIOwner()->GetPawn());
    MoveToHeight(agent);
}

void UMaintainHeightBehavior::MoveToHeight(ABoidsAgent* agent)
{
    float agentHeight = agent->GetActorLocation().Z;
    float minHeight = agent->targetHeight - agent->heightVariance;
    float maxHeight = agent->targetHeight + agent->heightVariance;
    bool isClimbing = agent->statusClimbing;

    FVector agentVel = agent->GetVelocity();
    if (!isClimbing && agentHeight < minHeight) {
        agentVel += FVector(0, 0, agent->maxSpeed/2);   // fly up at half max thrust

        FString climbingText = FString::Printf(TEXT("Agent %d climbing from %f."), agent->agentID, agentHeight);
        GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Green, climbingText, true);
    }
    else if (!isClimbing && agentHeight > maxHeight) {
        agentVel -= FVector(0, 0, agent->maxSpeed/2);   // fly down at half max thrust

        FString fallingText = FString::Printf(TEXT("Agent %d falling from %f."), agent->agentID, agentHeight);
        GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Green, fallingText, true);
    }
    else {
        agent->statusClimbing = false;
    }

    agent->SetVelocity(agentVel);
}