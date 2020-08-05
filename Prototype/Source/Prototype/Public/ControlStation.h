// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GridStruct.h"
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
		int simTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int searchBehaviorType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int dispMapType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool dispFloor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool showMap;

	UFUNCTION()
		void UpdateMap(const TArray<FGridStruct> agentMap);
	UFUNCTION()
		void SaveMap();
	UFUNCTION()
		void DisplayMap(bool showOccupied, bool showEmpty, bool showVictims);

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

	UPROPERTY()
		FString logDir;					// Directory to write map data to

	TArray<Flock*> flockData;			// Tracker for active flocks.
	UPROPERTY()
		int numAgents;					// Number of active agents.
	UPROPERTY()
		int numWP;						// Number of active waypoints.

	TSet<FGridStruct> envMap;	// Global map constructed from agent-provided maps

	UPROPERTY()
		FTimerHandle timerBootUpDelay;	// Timer handle for waypoints that exist on world start
	UPROPERTY()
		FTimerHandle timerMapDisplay;	// Timer handle for refreshing map display
	UPROPERTY()
		FTimerHandle timerEndSim;		// Timer handle for countdown until end of simulation

	UFUNCTION()
		void SwarmInit();
	UFUNCTION()
		void InitWaypoints();			// Activate preplaced waypoints
	UFUNCTION()
		void EndSim();
};
