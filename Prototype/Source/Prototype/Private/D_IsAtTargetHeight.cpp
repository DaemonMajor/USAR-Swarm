// Fill out your copyright notice in the Description page of Project Settings.


#include "D_IsAtTargetHeight.h"
#include "USARAgent.h"
#include "AIController.h"

bool UD_IsAtTargetHeight::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());
    float agentHeight = agent->GetActorLocation().Z;
    float minHeight = agent->targetHeight - agent->heightVariance;
    float maxHeight = agent->targetHeight + agent->heightVariance;
    
    bool isInRange = (minHeight < agentHeight) && (agentHeight < maxHeight);

    if (isInRange) {
        agent->statusClimbing = false;

        return true;
    }
    
    agent->statusClimbing = true;
    
    return false;
}