// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlStation.h"
#include "SwarmWP.h"
#include "SwarmSpawnPoint.h"
#include "../PrototypeGameState.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AControlStation::AControlStation()
{
	PrimaryActorTick.bCanEverTick = false;

	simTime				= 10 * 60;		// switch to SIM_LENGTH after debug
	searchBehaviorType	= SearchBehavior::Spiral;
	dispMapType			= GridDisp::Point;
	dispFloor			= false;
	dispEmpty			= false;
	showMap				= false;
}

// Called when the game starts or when spawned
void AControlStation::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetGameState<APrototypeGameState>()->SetControlStation(this);

	GetWorldTimerManager().SetTimer(timerBootUpDelay, this, &AControlStation::SwarmInit, 1, false);

	FTimerDelegate dispMapDel;
	dispMapDel.BindUFunction(this, FName("DisplayMap"), true, dispEmpty, true);
	GetWorldTimerManager().SetTimer(timerMapDisplay, dispMapDel, 5, true);
	GetWorldTimerManager().SetTimer(timerSaveMap, this, &AControlStation::SaveMap, SIM_SAVE_RATE, true, SIM_SAVE_RATE);
	GetWorldTimerManager().SetTimer(timerEndSim, this, &AControlStation::EndSim, simTime, false);

	// Create log directory for maps.
	logDir = FString(LOG_DIR);
	logDir.Append("Env_Map_Results/");
	logDir.Append("USAR_Simulation_");
	switch (searchBehaviorType) {
		case SearchBehavior::None :
			logDir.Append("NoSearch");
			break;
		case SearchBehavior::Spiral :
			logDir.Append("Spiral");
			break;
		case SearchBehavior::RandomWalk :
			logDir.Append("RandomWalk");
			break;
		case SearchBehavior::Frontier :
			logDir.Append("Frontier");
			break;
	}
	logDir.Append(FDateTime::Now().ToString());
	logDir.Append("/");

	IPlatformFile& fManager = FPlatformFileManager::Get().GetPlatformFile();
	if (!fManager.CreateDirectory(*logDir)) {
		UE_LOG(LogTemp, Warning, TEXT("Log directory was not created."));
	}

	save = 1;
}

/* Assign the passed agent a unique ID and add to control station's registry.
*
*	@param agent Agent to add.
*/
void AControlStation::AddAgent(AUSARAgent* agent)
{
	agent->SetID(numAgents);
	agent->searchBehaviorType = searchBehaviorType;

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
void AControlStation::UpdateMap(const TSet<FGridStruct>& agentMap)
{
	for (FGridStruct sharedGrid : agentMap) {
		bool isNewGrid;
		FGridStruct* grid = sharedGrid.InsertInMap(envMap, isNewGrid);
		if (!isNewGrid) {
			grid->Combine(sharedGrid);
		}
	}
}

/* Refreshes displayed global map when showMap is enabled.
*/
void AControlStation::DisplayMap(bool showOccupied, bool showEmpty, bool showVictims)
{
	if (!showMap) {
		return;
	}

	for (FGridStruct grid : envMap) {
		FVector loc		= FVector(grid.x + GRID_SIZE/2, grid.y + GRID_SIZE/2, grid.z + GRID_SIZE/2);
		FVector boxSize = FVector(GRID_SIZE/2 * .9, GRID_SIZE/2 * .9, GRID_SIZE/2 * .9);
		FPlane p	= FPlane(loc, FVector(0, 0, 1));
		int8 conf	= 255 * grid.confidence;
		FColor c;

		if (showOccupied && grid.occupied) {
			c = FColor(128, 0, 0);

			switch (dispMapType) {
				case GridDisp::Point :
					if (dispFloor) {
						DrawDebugPoint(GetWorld(), loc, 5, c, true);
					}
					else {
						if (grid.z > 0) {
							DrawDebugPoint(GetWorld(), loc, 5, c, true);
						}
					}

					break;
				case GridDisp::Box :
					if (dispFloor) {
						DrawDebugBox(GetWorld(), loc, boxSize, c, true, -1, 5);
					}
					else {
						if (grid.z > 0) {
							DrawDebugBox(GetWorld(), loc, boxSize, c, true, -1, 5);
						}
					}

					break;
			}
		}

		if (showEmpty && !grid.occupied) {
			c = FColor(0, conf, 0);

			switch (dispMapType) {
				case GridDisp::Point :
					if (dispFloor) {
						DrawDebugPoint(GetWorld(), loc, 5, c, true);
					}
					else {
						if (grid.z > 0) {
							DrawDebugPoint(GetWorld(), loc, 5, c, true);
						}
					}

					break;
				case GridDisp::Box :
					if (dispFloor) {
						DrawDebugBox(GetWorld(), loc, boxSize, c, true, -1, 5);
					}
					else {
						if (grid.z > 0) {
							DrawDebugBox(GetWorld(), loc, boxSize, c, true, -1, 5);
						}
					}

					break;
			}
		}
		
		if (showVictims) {
			for (FVector s : grid.survivors) {
				DrawDebugPoint(GetWorld(), s, 15, FColor::Magenta, true, -1);
			}
		}
	}
}

/* Writes the current map to a file.
*/
void AControlStation::SaveMap()
{
	// grab map data from flocks
	// remove after implementing flock return/map dump behavior
	for (Flock* f : flockData) {
		for (AUSARAgent* agent : f->agents) {
			TSet<FGridStruct> map = agent->UploadMap();
			for (FGridStruct agentGrid : map) {
				bool isNewGrid;
				FGridStruct* grid = agentGrid.InsertInMap(envMap, isNewGrid);
				if (!isNewGrid) {
					grid->Combine(agentGrid);
				}
			}
		}
	}

	// write map data to file
	FString mapFile = logDir;
	mapFile += "Map_";
	mapFile += FString::FromInt(save);
	mapFile += ".csv";

	FString vicFile = logDir;
	vicFile += "Victims_";
	vicFile += FString::FromInt(save);
	vicFile += ".csv";

	FString mapData = "";
	FString vicData = "";
	for (FGridStruct grid : envMap) {
		FString gridData = grid.ToString();
		gridData += LINE_TERMINATOR;
		mapData += gridData;

		FString locData = "";
		for (FVector vicLoc : grid.survivors) {
			locData += FString::SanitizeFloat(vicLoc.X);
			locData += ", ";
			locData += FString::SanitizeFloat(vicLoc.Y);
			locData += ", ";
			locData += FString::SanitizeFloat(vicLoc.Z);
			locData += LINE_TERMINATOR;

			vicData += locData;
		}
	}

	FFileHelper::SaveStringToFile(mapData, *mapFile);
	FFileHelper::SaveStringToFile(vicData, *vicFile);

	save++;
}

/* Ends the simulation and saves the environment map to a file.
*/
void AControlStation::EndSim()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	SaveMap();

	showMap = true;
	DisplayMap(true, false, true);

	GetWorldTimerManager().ClearAllTimersForObject(this);

	for (Flock* f : flockData) {
		for (AUSARAgent* agent : f->agents) {
			agent->PowerDown();
		}
	}
}