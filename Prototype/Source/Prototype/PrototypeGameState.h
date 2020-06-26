// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	UFUNCTION()
	int AddAgent(ABoidsAgent* agent);	// increment numAgents and assign the passed agent a unique ID
	UFUNCTION()
	int AddWaypoint(ASwarmWP* waypoint);	// increment numWP and assign the passed waypoint a unique ID

protected:
	int numAgents;	// number of active agents
	int numWP;	// number of active waypoints
};
