// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlockStruct.h"
#include "ControlStation.h"
#include "USARAgent.h"
#include "SwarmWP.h"
#include "GameFramework/GameStateBase.h"
#include "PrototypeGameState.generated.h"


/**
 * 
 */
UCLASS()
class PROTOTYPE_API APrototypeGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	APrototypeGameState();

	UPROPERTY()
		AControlStation* station;

	UFUNCTION()
		void SetControlStation(AControlStation* cs);

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
		FTimerHandle timerEndSim;

	UFUNCTION()
		void EndSim();
};