// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgentController.h"
#include "BehaviorTree/BehaviorTree.h"

AUSARAgentController::AUSARAgentController()
{
    static ConstructorHelpers::FObjectFinder<UBehaviorTree> USARAgentBehaviorTree(TEXT("Blueprint'/Game/Behaviors/USARAgentBT.USARAgentBT'"));
    if (USARAgentBehaviorTree.Succeeded()) {
        USARAgentBT = USARAgentBehaviorTree.Object;
    }
}

void AUSARAgentController::BeginPlay()
{
    Super::BeginPlay();

    RunBehaviorTree(USARAgentBT);
}