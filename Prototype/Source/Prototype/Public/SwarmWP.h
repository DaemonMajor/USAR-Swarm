// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwarmWP.generated.h"

UCLASS()
class PROTOTYPE_API ASwarmWP : public AActor
{
	GENERATED_BODY()
	
public:	
	virtual void Tick(float DeltaSeconds) override;
	ASwarmWP();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int wpID = -1;			// Unique waypoint ID. Value of -1 sets waypoint as inactive.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int flockID = -1;		// Flock assigned to this waypoint.

	UFUNCTION()
		int GetID();
	UFUNCTION()
		void SetID(int id);
	UFUNCTION()
		void SetFlock(int flock);

	UFUNCTION()
		void Deactivate();

protected:
	virtual void BeginPlay() override;

	
};