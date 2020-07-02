// Fill out your copyright notice in the Description page of Project Settings.


#include "D_HasNeighbors.h"
#include "USARAgent.h"
#include "AIController.h"

bool UD_HasNeighbors::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());

    bool hasNeighbors;
    if (agent->GetNeighbors().Num()) {
        hasNeighbors = true;
    }
    else {
        hasNeighbors = false;
    }

    return hasNeighbors;
}