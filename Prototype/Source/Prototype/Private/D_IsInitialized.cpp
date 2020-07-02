// Fill out your copyright notice in the Description page of Project Settings.


#include "D_IsInitialized.h"
#include "USARAgent.h"
#include "AIController.h"

bool UD_IsInitialized::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());

    return agent->isInitialized;
}