// Fill out your copyright notice in the Description page of Project Settings.


#include "SwarmSpawnPoint.h"
#include "SpawnPointController.h"
#include "USARAgent.h"

ASwarmSpawnPoint::ASwarmSpawnPoint()
{
 	PrimaryActorTick.bCanEverTick = false;

	spawnRoot = CreateDefaultSubobject<UStaticMeshComponent>("SpawnPointRoot");
	SetRootComponent(spawnRoot);
	spawnRoot->SetSimulatePhysics(false);

	AIControllerClass = ASpawnPointController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	numAgentsToSpawn = 0;
	flockID = -1;
	timeBetweenSpawns = 0;
	spawnRadius = 0;
}

void ASwarmSpawnPoint::Init(float numAgents, int flock, float timing, float radius)
{
	numAgentsToSpawn = numAgents;
	flockID = flock;
	timeBetweenSpawns = timing;
	spawnRadius = radius;
}