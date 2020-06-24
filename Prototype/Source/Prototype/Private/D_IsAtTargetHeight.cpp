// Fill out your copyright notice in the Description page of Project Settings.


#include "D_IsAtTargetHeight.h"

bool D_IsAtTargetHeight::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    ABoidsAgent* agent = Cast<ABoidsAgent>(OwnerComp.GetAIOwner()->GetPawn());
    float agentHeight = agent->GetActorLocation().Z;
    float minHeight = agent->targetHeight - agent->heightVariance;
    float maxHeight = agent->targetHeight + agent->heightVariance;
    
    bool isClimbing = agent->statusClimbing;
    bool isInRange = (minHeight < agentHeight) && (agentHeight > maxHeight);
    if (isClimbing) {
        if (isInRange) {
            agent->statusClimbing = false;
        }
        return false;
    }
    
    return true;
}