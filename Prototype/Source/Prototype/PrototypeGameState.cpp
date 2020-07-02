// Fill out your copyright notice in the Description page of Project Settings.


#include "PrototypeGameState.h"
#include "USARAgent.h"
#include "SwarmWP.h"
#include "Kismet/GameplayStatics.h"

APrototypeGameState::APrototypeGameState()
{
	numAgents = 0;
	numWP = 0;
}

/* Give the passed agent a unique ID and assign to specified flock. Returns flock data.
*
*	@param agent Agent to assign.
*	@param flockID Flock to assign the agent to. A new flock will be formed if one with the specified ID does not exist.
*	@return Flock data on the flock the agent was assigned to.
*/
Flock APrototypeGameState::AddAgent(AUSARAgent* agent, int flockID)
{
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

	agent->SetID(numAgents);
	numAgents++;

	return *flock;
}

/* Give the passed waypoint a unique ID and assign to specified flock. Returns waypoint ID.
*
*	@param waypoint Waypoint to assign a flock.
*	@param flockID ID of the flock to assign.
*	@return Assigned unique waypoint ID. Returns -1 if invalid flock ID.
*/
int APrototypeGameState::AddWaypoint(ASwarmWP* waypoint, int flockID)
{
	for (Flock* f : flockData) {
		if (f->flockID == flockID) {
			f->waypoints.Add(waypoint);

			for (AUSARAgent* agent : f->agents) {
				agent->AddWaypoint(waypoint);
			}

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
void APrototypeGameState::RemoveWaypoint(ASwarmWP* waypoint)
{
	for (Flock* f : flockData) {
		if (f->waypoints.Remove(waypoint)) {
			for (AUSARAgent* agent : f->agents) {
				agent->RemoveWaypoint(waypoint);
			}

			return;
		}
	}
}