// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ControlStation.generated.h"

UCLASS()
class PROTOTYPE_API AControlStation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AControlStation();

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
		FTimerHandle bootUpDelayTimer;	// timer handle for waypoints that exist on world start

	UFUNCTION()
		void InitWaypoints();	// activate preplaced waypoints
};
