// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlStation.h"
#include "FlockStruct.h"
#include "SwarmWP.h"
#include "SwarmSpawnPoint.h"
#include "../PrototypeGameState.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AControlStation::AControlStation()
{
	PrimaryActorTick.bCanEverTick = false;

	showMap = false;
}

// Called when the game starts or when spawned
void AControlStation::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetGameState<APrototypeGameState>()->SetControlStation(this);
	
	GetWorldTimerManager().SetTimer(timerBootUpDelay, this, &AControlStation::SwarmInit, 1, false);
	GetWorldTimerManager().SetTimer(timerMapDisplay, this, &AControlStation::DisplayMap, 5, true);
	GetWorldTimerManager().SetTimer(timerEndSim, this, &AControlStation::EndSim, SIM_LENGTH, false);
}

/* Assign the passed agent a unique ID and add to control station's registry.
*
*	@param agent Agent to add.
*/
void AControlStation::AddAgent(AUSARAgent* agent)
{
	agent->SetID(numAgents);
	numAgents++;
}

/* Assigns the passed agent to the specified flock. A new flock with flockID will be formed if one does not exist.
*
*	@param agent Agent to assign.
*	@param flock ID of the flock to assign to.
*/
void AControlStation::AssignToFlock(AUSARAgent* agent, int flockID)
{
	agent->ClearFlockWPs();
	agent->flockID = flockID;

	/*DEBUGGING*/
	FString flockAssignText = FString::Printf(TEXT("Agent %d assigned to flock %d (%d waypoints)."), agent->agentID, flockID, flockData[0]->waypoints.Num());
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, flockAssignText, true);
	/*DEBUGGING*/
	
	Flock* flock = new Flock();

	if (!flockData.Num()) {
		flock->flockID = flockID;
		flock->agents.Add(agent);

		flockData.Add(flock);
	}
	else {
		bool isAdded = false;

		for (Flock* f : flockData) {
			if (f->flockID == flockID) {
				f->agents.Add(agent);

				flock = f;
				isAdded = true;

				break;
			}
		}

		if (!isAdded) {
			flock->flockID = flockID;
			flock->agents.Add(agent);

			flockData.Add(flock);
		}
	}

	for (ASwarmWP* wp : flock->waypoints) {
		agent->AddFlockWP(wp->GetActorLocation());
	}
}

/* Give the passed waypoint a unique ID and assign to specified flock. Returns waypoint ID.
*
*	@param waypoint Waypoint to assign a flock.
*	@param flockID ID of the flock to assign.
*	@return Assigned unique waypoint ID. Returns -1 if invalid flock ID.
*/
int AControlStation::AddWaypoint(ASwarmWP* waypoint, int flockID)
{
	for (Flock* f : flockData) {
		if (f->flockID == flockID) {
			f->waypoints.Add(waypoint);

			//for (AUSARAgent* agent : f.agents) {
			//	agent->AddFlockWP(waypoint->GetActorLocation());
			//}

			waypoint->SetID(numWP);
			numWP++;

			return numWP - 1;
		}
	}

	return -1;
}

/* Unassign the passed waypoint. Current implementation assumes a waypoint is only assigned to one flock.
*
*	@param waypoint	Waypoint to unassign.
*/
void AControlStation::RemoveWaypoint(ASwarmWP* waypoint)
{
	for (Flock* f : flockData) {
		if (f->waypoints.Remove(waypoint)) {
			for (AUSARAgent* agent : f->agents) {
				agent->RemoveFlockWP(waypoint->GetActorLocation());
			}

			return;
		}
	}
}

/* Activate preplaced waypoints. All waypoints assigned to flock 1.
*/
void AControlStation::InitWaypoints()
{
	TArray<AActor*> preplacedWPs;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASwarmWP::StaticClass(), preplacedWPs);

	for (AActor* itr : preplacedWPs) {
		ASwarmWP* wp = Cast<ASwarmWP>(itr);
		wp->SetFlock(1);
		wp->SetID(AddWaypoint(wp, 1));
	}

	/*DEBUGGING*/
	FString initWPText = FString::Printf(TEXT("%d waypoints assigned."), flockData[0]->waypoints.Num());
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, initWPText, true);
	/*DEBUGGING*/
}

/* Forms flock 1 and initializes preplaced waypoints. Spawns agents at preplaced spawn points and assigns them to flock 1.
*/
void AControlStation::SwarmInit()
{
	Flock* f1 = new Flock(1);
	flockData.Add(f1);

	InitWaypoints();

	TArray<AActor*> spawnPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASwarmSpawnPoint::StaticClass(), spawnPoints);
	for (AActor* spawn : spawnPoints) {
		TArray<AUSARAgent*> swarm = Cast<ASwarmSpawnPoint>(spawn)->SpawnAgents();

		for (AUSARAgent* agent : swarm) {
			AddAgent(agent);
			AssignToFlock(agent, 1);
		}
	}

	GetWorld()->GetTimerManager().ClearTimer(timerBootUpDelay);
}

/* Called by agents to update the global environment map.
*/
void AControlStation::UpdateMap(const TArray<FLocGridStruct> agentMap)
{
	for (FLocGridStruct grid : agentMap) {
		int idx;
		bool isNewGrid = grid.InsertInMap(envMap, idx);
		if (!isNewGrid) {
			envMap[idx].confidence = FMath::Clamp(envMap[idx].confidence + grid.confidence, 0.f, 1.f);
		}
	}
}

/* Refreshes displayed global map when showMap is enabled.
*/
void AControlStation::DisplayMap()
{
	if (!showMap) {
		return;
	}

	for (FLocGridStruct grid : envMap) {
		FVector loc = FVector(grid.x, grid.y, 10);
		FVector boxSize = FVector(1, 1, 1);
		FPlane p	= FPlane(loc, FVector(0, 0, 1));
		int8 conf	= 255 * grid.confidence;
		FColor c	= FColor(0, conf, 0);

		DrawDebugBox(GetWorld(), loc, boxSize, c, true, -1, '\000', 5);
		//DrawDebugSolidPlane(GetWorld(), p, loc, GRID_SIZE, c, true, -1);
	}
}

/* Pauses simulation and writes current state of map to a file.
*/
void AControlStation::SaveMap()
{
	// grab map data from flocks
	// remove after implementing flock return/map dump behavior
	for (Flock* f : flockData) {
		AUSARAgent* agent = f->agents[0];

		TArray<FLocGridStruct> map = agent->UploadMap();
		for (FLocGridStruct grid : map) {
			int idx;
			bool isNewGrid = grid.InsertInMap(envMap, idx);
			if (!isNewGrid) {
				envMap[idx].confidence = FMath::Clamp(envMap[idx].confidence + grid.confidence, 0.f, 1.f);
			}
		}
	}

	// write map data to file
	// ...
}

/* Ends the simulation and saves the environment map to a file.
*/
void AControlStation::EndSim()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	SaveMap();

	showMap = true;
	DisplayMap();

	GetWorldTimerManager().ClearAllTimersForObject(this);

	for (Flock* f : flockData) {
		for (AUSARAgent* agent : f->agents) {
			agent->PowerDown();
		}
	}
}