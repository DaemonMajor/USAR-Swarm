// Fill out your copyright notice in the Description page of Project Settings.


#include "D_IsAvoiding.h"
#include "BoidsAgent.h"
#include "AIController.h"

bool UD_IsAvoiding::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    ABoidsAgent* agent = Cast<ABoidsAgent>(OwnerComp.GetAIOwner()->GetPawn());

    return agent->statusAvoiding;
}