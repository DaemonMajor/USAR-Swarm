// Fill out your copyright notice in the Description page of Project Settings.


#include "SpiralSearchTask.h"
#include "USARAgent.h"
#include "AIController.h"

EBTNodeResult::Type USpiralSearchTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());



    return EBTNodeResult::Succeeded;
}