// Fill out your copyright notice in the Description page of Project Settings.


#include "MaintainHeightTask.h"

EBTNodeResult::Type UMaintainHeightTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    return EBTNodeResult::Succeeded;
}