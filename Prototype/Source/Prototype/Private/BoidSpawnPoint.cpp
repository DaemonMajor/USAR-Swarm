// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidSpawnPoint.h"
#include "BoidsAgent.h"

ABoidSpawnPoint::ABoidSpawnPoint()
{
 	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ABoidSpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	
	while (numAgentsToSpawn) {
		GetWorld()->GetTimerManager().SetTimer(spawnTimer, this, &ABoidSpawnPoint::SpawnAgent, timeBetweenSpawns, false);

		numAgentsToSpawn--;
	}

	GetWorld()->GetTimerManager().ClearTimer(spawnTimer);
}

void ABoidSpawnPoint::Init(float numAgents, float timing, float radius)
{
	numAgentsToSpawn = numAgents;
	timeBetweenSpawns = timing;
	spawnRadius = radius;
}

void ABoidSpawnPoint::SpawnAgent() {
	FName agentName = FName("agent_" + FString::FromInt(numAgentsToSpawn));


	//FVector spawnLoc = FVector()
	
	//UWorld::SpawnActor(ABoidsAgent, agentName, )
}