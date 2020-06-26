// Copyright Epic Games, Inc. All Rights Reserved.

#include "PrototypeGameMode.h"
#include "PrototypeCharacter.h"
#include "PrototypeGameState.h"
#include "UObject/ConstructorHelpers.h"

APrototypeGameMode::APrototypeGameMode()
{
	//set default game state
	GameStateClass = APrototypeGameState::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> playerPawn(TEXT("/Game/TopDownCPP/Blueprints/PrototypeCharacterBP"));
	if (playerPawn.Class != NULL)
	{
		DefaultPawnClass = playerPawn.Class;
	}
}