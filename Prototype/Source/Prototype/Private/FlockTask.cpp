// Fill out your copyright notice in the Description page of Project Settings.


#include "FlockTask.h"
#include "BoidsAgent.h"
#include "AIController.h"

EBTNodeResult::Type UFlockTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    return EBTNodeResult::Succeeded;
}