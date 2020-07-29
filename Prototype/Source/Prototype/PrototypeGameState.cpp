// Fill out your copyright notice in the Description page of Project Settings.


#include "PrototypeGameState.h"
#include "Kismet/GameplayStatics.h"

APrototypeGameState::APrototypeGameState()
{
}

void APrototypeGameState::BeginPlay()
{
	Super::BeginPlay();
}

void APrototypeGameState::SetControlStation(AControlStation* cs)
{
	station = cs;
}

/* Pauses simulation and writes current state of map to a file.
*/
void APrototypeGameState::EndSim()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	station->showMap = true;
	station->DisplayMap();

	// write map data to file
	// ...
}