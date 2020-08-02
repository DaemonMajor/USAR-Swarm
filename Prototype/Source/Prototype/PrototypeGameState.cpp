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