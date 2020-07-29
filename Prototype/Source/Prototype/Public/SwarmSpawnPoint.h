// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "USAR_Constants.h"
#include "USARAgent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwarmSpawnPoint.generated.h"

UCLASS()
class PROTOTYPE_API ASwarmSpawnPoint : public APawn
{
	GENERATED_BODY()
	
public:
	ASwarmSpawnPoint();

	UFUNCTION()
		TArray<AUSARAgent*> SpawnAgents();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* spawnRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int numAgentsToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int flockID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float timeBetweenSpawns;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float spawnRadius;

	UFUNCTION()
		void Init(float numAgents, int flock, float timing, float radius);
	UFUNCTION()
		FVector GetRandLoc();
};