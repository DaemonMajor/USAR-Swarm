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
        FString noWPText = FString::Printf(TEXT("Agent %d has no waypoints."), agentID);
        GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, noWPText, true);
        /*DEBUGGING*/
    }

    flockWPVector = targetVector;
}

void AUSARAgent::CheckAtWP()
{
    if (!flockWPs.Num()) {
        return;
    }
    
    float dist = FVector::DistXY(flockCenter, flockWPs[0]);
    float wpTol = 5 * numNeighbors + WP_TOLERANCE;
    if (dist < wpTol) {
        statusTraveling = false;
        statusReadyToSearch = true;

        GetWorldTimerManager().SetTimer(timerCheckSearchReady, this, &AUSARAgent::FlockReadyToSearch, 1.f, true);
    }

    /*DEBUGGING*/
    if (showDebug) {
        //FString atWPText = FString::Printf(TEXT("Flock %f from waypoint."), dist);
        //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, atWPText, true);
    }
    /*DEBUGGING*/
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