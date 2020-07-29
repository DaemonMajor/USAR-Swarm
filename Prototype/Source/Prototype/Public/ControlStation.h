// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LocGridStruct.h"
#include "FlockStruct.h"
#include "USARAgent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ControlStation.generated.h"


UCLASS()
class PROTOTYPE_API AControlStation : public AActor
{
	GENERATED_BODY()
	
public:
	AControlStation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool showMap;

	UFUNCTION()
		void UpdateMap(const TArray<FLocGridStruct> agentMap);
	UFUNCTION()
		void SaveMap();
	UFUNCTION()
		void DisplayMap();

	UFUNCTION()
		void AddAgent(AUSARAgent* agent);					// Give the passed agent a unique ID and assign to specified flock. Returns flock data.
	UFUNCTION()
		void AssignToFlock(AUSARAgent* agent, int flockID);	// Assign given agent to specified flock.
	UFUNCTION()
		int AddWaypoint(ASwarmWP* waypoint, int flockID);	// Give the passed waypoint a unique ID and assign to specified flock. Returns waypoint ID.
	UFUNCTION()
		void RemoveWaypoint(ASwarmWP* waypoint);			// Unassign a waypoint.

protected:
	virtual void BeginPlay() override;

	TArray<Flock*> flockData;			// Tracker for active flocks.
	UPROPERTY()
		int numAgents;					// Number of active agents.
	UPROPERTY()
		int numWP;						// Number of active waypoints.

	UPROPERTY()
		TArray<FLocGridStruct> envMap;	// global map constructed from agent-provided maps

	UPROPERTY()
		FTimerHandle timerBootUpDelay;	// timer handle for waypoints that exist on world start
	UPROPERTY()
		FTimerHandle timerMapDisplay;	// timer handle for refreshing map display
	UPROPERTY()
		FTimerHandle timerEndSim;		// timer handle for countdown until end of simulation

	UFUNCTION()
		void SwarmInit();
	UFUNCTION()
		void InitWaypoints();			// activate preplaced waypoints
	UFUNCTION()
		void EndSim();
};
