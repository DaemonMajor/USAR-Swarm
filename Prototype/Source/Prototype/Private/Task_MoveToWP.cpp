// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"
#include "../PrototypeGameState.h"


void AUSARAgent::MoveToWPHandle()
{
    MoveToWPTask();
    FollowBestNeighbor();
    CheckAtWP();
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

/* Moves toward the neighbor closest to the waypoint (chance-based).
*/
void AUSARAgent::FollowBestNeighbor()
{
    distToWP = FVector::DistXY(GetActorLocation(), flockWPs[0]);

    if (FMath::FRand() < CHANCE_FOLLOW) {
        AUSARAgent* agentToFollow = this;
        for (AUSARAgent* n : neighborAgents) {
            if (n->distToWP < agentToFollow->distToWP) {
                agentToFollow = n;
            }
        }

        flockWPVector += agentToFollow->GetActorLocation() - GetActorLocation();
    }
}

void AUSARAgent::CheckAtWP()
{
    if (!flockWPs.Num()) {
        return;
    }
    
    float dist = FVector::DistXY(flockCenter, flockWPs[0]);
    float wpTol = 5 * numNeighbors + WP_TOLERANCE;
    if (dist < wpTol) {
        GetWorldTimerManager().ClearTimer(timerMoveTask);

        flockWPVector = FVector::ZeroVector;

        if (statusRTB) {
            GetWorld()->GetGameState<APrototypeGameState>()->station->UpdateMap(envMap);

            PowerDown();
        }
        else if (statusActiveSearch) {
            statusActiveSearch = false;
            statusLoitering    = true;
            flockWPs.RemoveAt(0);
            numWPs--;

            GetWorldTimerManager().SetTimer(timerCheckMoveReady, this, &AUSARAgent::FlockReadyToMove, 1.f, true, CalcWaitTime());
        }
        else {
            statusTraveling     = false;
            statusReadyToSearch = true;

            GetWorldTimerManager().SetTimer(timerCheckSearchReady, this, &AUSARAgent::FlockReadyToSearch, 1.f, true);
        }
    }

    /*DEBUGGING*/
    if (showDebug) {
        FString atWPText = FString::Printf(TEXT("Flock %d [%f] from waypoint (tol: %f)."), flockID, dist, wpTol);
        GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, atWPText, true);
    }
    /*DEBUGGING*/
}

/* Determines if the flock is ready to move to the next waypoint as a group. If no waypoints exist, the control station is set as the waypoint.
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

    if (!flockWPs.Num()) {
        flockWPs.Add(baseStation);
        numWPs++;

        statusRTB = true;
    }

    statusLoitering = false;
    statusTraveling = true;

    GetWorldTimerManager().ClearTimer(timerCheckMoveReady);
    GetWorldTimerManager().SetTimer(timerMoveTask, this, &AUSARAgent::MoveToWPHandle, RATE_WP_TASK, true);
}