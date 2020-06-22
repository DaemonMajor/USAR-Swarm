// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidsAgentController.h"
#include "BehaviorTree/BehaviorTree.h"

ABoidsAgentController::ABoidsAgentController()
{
    static ConstructorHelpers::FObjectFinder<UBehaviorTree> boidsAgentBehaviorTree(TEXT("Blueprint'/Game/Behaviors/BoidsAgentBT.BoidsAgentBT'"));
    if (boidsAgentBehaviorTree.Succeeded()) {
        boidsAgentBT = boidsAgentBehaviorTree.Object;
    }
}

void ABoidsAgentController::BeginPlay()
{
    Super::BeginPlay();

    RunBehaviorTree(boidsAgentBT);
}