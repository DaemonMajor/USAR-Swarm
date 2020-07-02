// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPointController.h"
#include "BehaviorTree/BehaviorTree.h"

ASpawnPointController::ASpawnPointController()
{
    static ConstructorHelpers::FObjectFinder<UBehaviorTree> SpawnPointBehaviorTree(TEXT("Blueprint'/Game/Behaviors/SwarmSpawnPointBT.SwarmSpawnPointBT'"));
    if (SpawnPointBehaviorTree.Succeeded()) {
        SpawnPointBT = SpawnPointBehaviorTree.Object;
    }
}

void ASpawnPointController::BeginPlay()
{
    Super::BeginPlay();

    RunBehaviorTree(SpawnPointBT);
}