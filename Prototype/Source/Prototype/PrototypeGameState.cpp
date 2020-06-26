// Fill out your copyright notice in the Description page of Project Settings.


#include "PrototypeGameState.h"
#include "BoidsAgent.h"
#include "SwarmWP.h"
#include "Kismet/GameplayStatics.h"

APrototypeGameState::APrototypeGameState()
{
	numAgents = 0;
	numWP = 0;
}

int APrototypeGameState::AddAgent(ABoidsAgent* agent)
{
	agent->SetID(numAgents);
	numAgents++;

	return numAgents - 1;
}

int APrototypeGameState::AddWaypoint(ASwarmWP* waypoint)
{
	waypoint->SetID(numWP);
	numWP++;

	return numWP - 1;
}