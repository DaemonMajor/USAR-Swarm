// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BoidsAgent.h"
#include "SwarmWP.h"
#include "GameFramework/GameStateBase.h"
#include "PrototypeGameState.generated.h"

USTRUCT()
struct Flock
{
	GENERATED_BODY()

	UPROPERTY()
		int flockID;
	UPROPERTY()
		TArray<ABoidsAgent*> agents;
	UPROPERTY()
		TArray<ASwarmWP*> waypoints;
};

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
		Flock AddAgent(ABoidsAgent* agent, int flockID);	// Give the passed agent a unique ID and assign to specified flock. Returns flock data.
	UFUNCTION()
		int AddWaypoint(ASwarmWP* waypoint, int flockID);	// Give the passed waypoint a unique ID and assign to specified flock. Returns waypoint ID.
	UFUNCTION()
		void RemoveWaypoint(ASwarmWP* waypoint);			// Unassign the waypoint.

protected:
	TArray<Flock*> flockData;	// Tracker for active flocks.

	int numAgents;	// Number of active agents.
	int numWP;		// Number of active waypoints.
};