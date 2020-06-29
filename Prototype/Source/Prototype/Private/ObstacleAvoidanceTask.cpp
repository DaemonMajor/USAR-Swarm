// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleAvoidanceTask.h"

EBTNodeResult::Type UObstacleAvoidanceTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    return EBTNodeResult::Succeeded;
}