// Fill out your copyright notice in the Description page of Project Settings.


#include "SwarmWP.h"
#include "USARAgent.h"
#include "../PrototypeGameState.h"
#include "DrawDebugHelpers.h"

// Sets default values
ASwarmWP::ASwarmWP()
{
 	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASwarmWP::BeginPlay()
{
	Super::BeginPlay();
}

void ASwarmWP::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// draw debug point for user

}

void ASwarmWP::Deactivate()
{
	AControlStation* station = GetWorld()->GetGameState<APrototypeGameState>()->station;
	station->RemoveWaypoint(this);

	/*DEBUGGING*/
	FString wpDeactivatedText = FString::Printf(TEXT("Waypoint %d deactivated."), wpID);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Red, wpDeactivatedText, true);
	/*DEBUGGING*/

	Destroy();
}

int ASwarmWP::GetID()
{
	return wpID;
}

void ASwarmWP::SetID(int id)
{
	wpID = id;
}

void ASwarmWP::SetFlock(int flock) {
	flockID = flock;
}