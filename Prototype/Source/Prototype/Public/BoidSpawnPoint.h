// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoidSpawnPoint.generated.h"

UCLASS()
class PROTOTYPE_API ABoidSpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidSpawnPoint();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float numAgentsToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float timeBetweenSpawns;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float spawnRadius;

	UFUNCTION()
		void Init(float numAgents, float timing, float radius);
	UFUNCTION()
		void SpawnAgent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle spawnTimer;
};