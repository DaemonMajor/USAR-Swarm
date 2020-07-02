// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SpawnPointController.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_API ASpawnPointController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	ASpawnPointController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBehaviorTree* SpawnPointBT;
};
