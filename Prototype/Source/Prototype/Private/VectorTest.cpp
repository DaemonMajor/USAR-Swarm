// Fill out your copyright notice in the Description page of Project Settings.

#include "VectorTest.h"
#include "USARAgent.h"
#include "AIController.h"

EBTNodeResult::Type UVectorTest::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());
    
    FVector testVec = FVector(agent->maxSpeed, 0, 0);
    FRotator testRot = FRotator(0, 90, 0);
    testVec = testRot.RotateVector(testVec);

    agent->SetWaypointVector(testVec);

    return EBTNodeResult::Succeeded;
}