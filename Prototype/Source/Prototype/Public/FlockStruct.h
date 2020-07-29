#pragma once

#include "USARAgent.h"
#include "SwarmWP.h"
#include "Engine.h"
#include "FlockStruct.generated.h"

USTRUCT()
struct Flock
{
	GENERATED_BODY()

	UPROPERTY()
		int flockID;
	UPROPERTY()
		TArray<AUSARAgent*> agents;
	UPROPERTY()
		TArray<ASwarmWP*> waypoints;

	Flock() :
		flockID(-1)
	{}

	Flock(int id) :
		flockID(id)
	{}
};