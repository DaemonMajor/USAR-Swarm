// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LocGridStruct.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ControlStation.generated.h"

UCLASS()
class PROTOTYPE_API AControlStation : public AActor
{
	GENERATED_BODY()
	
public:
	AControlStation();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool showMap;

	UFUNCTION()
		void UpdateMap(const TArray<FLocGridStruct> agentMap);

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
		TArray<FLocGridStruct> envMap;	// global map constructed from agent-provided maps

	UPROPERTY()
		FTimerHandle bootUpDelayTimer;	// timer handle for waypoints that exist on world start
	UPROPERTY()
		FTimerHandle mapDisplayTimer;	// timer handle for refreshing map display

	UFUNCTION()
		void InitWaypoints();	// activate preplaced waypoints
	UFUNCTION()
		void DisplayMap();
};
