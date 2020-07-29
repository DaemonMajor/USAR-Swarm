// Fill out your copyright notice in the Description page of Project Settings.


#include "SwarmSpawnPoint.h"

ASwarmSpawnPoint::ASwarmSpawnPoint()
{
 	PrimaryActorTick.bCanEverTick = false;

	spawnRoot = CreateDefaultSubobject<UStaticMeshComponent>("SpawnPointRoot");
	SetRootComponent(spawnRoot);
	spawnRoot->SetSimulatePhysics(false);

	numAgentsToSpawn = FLOCK_SIZE;
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

/* Spawn and initialize agents.
*/
TArray<AUSARAgent*> ASwarmSpawnPoint::SpawnAgents()
{
	TArray<AUSARAgent*> swarm;

	while (numAgentsToSpawn) {
		FVector agentPos = GetRandLoc();

		AUSARAgent* agent = GetWorld()->SpawnActor<AUSARAgent>(agentPos + GetActorLocation(), FRotator::ZeroRotator);
		swarm.Add(agent);

		numAgentsToSpawn--;
	}

	return swarm;
}

/* Get random location in semisphere above spawn point's center.
*
*   @param spawn SwarmSpawnPoint to use.
*   @return Vector in vicinity of the spawn point, restricted by the spawn point's spawnRadius.
*/
FVector ASwarmSpawnPoint::GetRandLoc()
{
	float xPos = FMath::FRandRange(-spawnRadius, spawnRadius);
	float yPos = FMath::FRandRange(-spawnRadius, spawnRadius);
	float zPos = 50;

	FVector spawnPos = FVector(xPos, yPos, zPos).GetClampedToSize(0, spawnRadius);

	return spawnPos;
}