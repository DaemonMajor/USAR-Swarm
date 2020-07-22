// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"

void AUSARAgent::MoveToWPHandle()
{
    if (!statusActiveSearch) {
        MoveToWPTask();

        if (statusTraveling) {
            CheckAtWP();
        }
    }
}

void AUSARAgent::MoveToWPTask()
{
    FVector waypoint;
    FVector targetVector = FVector::ZeroVector;
    if (GetCurrFlockWP(waypoint)) {
        waypoint.Z = targetHeight;

        targetVector = waypoint - GetActorLocation();
        targetVector = targetVector.GetClampedToSize(MAX_SPEED * 3, MAX_SPEED * 3);     // set magnitude so agent doesn't slow down as it nears the waypoint
    }
    else {
        /*DEBUGGING*/
        if (showDebug) {
            FString noWPText = FString::Printf(TEXT("Agent %d has no waypoints."), agentID);
            GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, noWPText, true);
        }
        /*DEBUGGING*/
    }

    SetFlockWPVector(targetVector);
}

void AUSARAgent::CheckAtWP()
{
    float minDist = MIN_WP_ERR + sqrtf(neighborAgents.Num()) * AGENT_SPACING;
    FVector agentLoc = GetActorLocation();
    agentLoc.Z = 0;
    FVector wpLoc = flockWPs[0];
    wpLoc.Z = 0;

    float distToWP = abs((agentLoc - wpLoc).Size());

    if (distToWP <= minDist) {
        statusTraveling = false;
        statusReadyToSearch = true;

        GetWorldTimerManager().SetTimer(timerCheckSearchReady, this, &AUSARAgent::FlockReadyToSearch, 1.f, true);
    }
}

/* Determines if the flock is ready to move to the next waypoint as a group.
*
*	@return True if the flock is ready, false if not.
*/
void AUSARAgent::FlockReadyToMove()
{
    bool ready = true;
    for (AUSARAgent* n : neighborAgents) {
        if (!(n->statusLoitering || n->statusTraveling)) {
            return;
        }
    }

    statusLoitering = false;
    statusTraveling = true;

    GetWorldTimerManager().ClearTimer(timerCheckMoveReady);
    GetWorldTimerManager().SetTimer(timerMoveTask, this, &AUSARAgent::MoveToWPHandle, RATE_WP_TASK, true);
}