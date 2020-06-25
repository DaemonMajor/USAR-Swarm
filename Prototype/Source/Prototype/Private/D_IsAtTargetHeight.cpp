// Fill out your copyright notice in the Description page of Project Settings.


#include "D_IsAtTargetHeight.h"
#include "BoidsAgent.h"
#include "AIController.h"

bool UD_IsAtTargetHeight::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    ABoidsAgent* agent = Cast<ABoidsAgent>(OwnerComp.GetAIOwner()->GetPawn());
    float agentHeight = agent->GetActorLocation().Z;
    float minHeight = agent->targetHeight - agent->heightVariance;
    float maxHeight = agent->targetHeight + agent->heightVariance;
    
    bool isClimbing = agent->statusClimbing;
    bool isInRange = (minHeight < agentHeight) && (agentHeight < maxHeight);

    if (!isInRange) {
        if (isClimbing) {
            return false;
        }

        agent->statusClimbing = true;
        return true;
    }
    
    agent->statusClimbing = false;
    
    return false;
}