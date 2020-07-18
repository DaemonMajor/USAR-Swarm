// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"

void AUSARAgent::ActiveSearchHandle()
{
    if (statusActiveSearch) {
        ActiveSearchTask();
    }
}

void AUSARAgent::ActiveSearchTask()
{
    FVector centerPt;
    if (GetCurrFlockWP(centerPt)) {
        FVector toCenter = centerPt - GetActorLocation();
        toCenter.Z = 0;

        FRotator rot = FRotator(0, 90, 0);
        if (expandingSearch < 0) {
            rot = FRotator(0, 75, 0);
        }

        FVector moveVec = rot.RotateVector(toCenter);

        searchVector = moveVec.GetClampedToSize(SEARCH_SPEED, SEARCH_SPEED);

        /*DEBUGGING*/
        if (showDebug) {
            DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + searchVector, 10.f, FColor::Orange, false, 0.25, 0, 1.f);
        }
        /*DEBUGGING*/
    }
}

/* Determines if the flock is ready to enter search behavior by checking if all neighbors' statusReadyToSearch.
*
*/
bool AUSARAgent::FlockReadyToSearch()
{
    bool ready = true;

    for (AUSARAgent* n : neighborAgents) {
        if (!(n->statusReadyToSearch || n->statusActiveSearch)) {
            ready = false;
        }
    }

    return ready;
}

/* Initiates search behavior.
*
*/
void AUSARAgent::BeginSearch() {
    alignWeight = 0;
    cohWeight = 0;
    agentSpacing = MAX_AGENT_SPACING;
    targetHeight = SEARCH_HEIGHT;

    statusReadyToSearch = false;
    statusActiveSearch = true;

    expandingSearch = 1;
    GetWorldTimerManager().SetTimer(timerSearchExpand, this, &AUSARAgent::ExpandSearch, 2.5, true);
}

/* Expands then contracts search area covered by flock. Exits search behavior when done.
*
*/
void AUSARAgent::ExpandSearch()
{
    if (expandingSearch > 0) {
        sepWeight += 5;

        if (sepWeight >= MAX_SEPARATION_WEIGHT) {
            expandingSearch = -1;

            agentSpacing = AGENT_SPACING;
        }
    }
    else if (expandingSearch < 0) {
        sepWeight -= 5;

        if (sepWeight <= SEPARATION_WEIGHT) {
            alignWeight  = ALIGNMENT_WEIGHT;
            cohWeight    = COHESION_WEIGHT;
            sepWeight    = SEPARATION_WEIGHT;
            targetHeight = MOVE_HEIGHT;

            statusActiveSearch = false;
            flockWPs.RemoveAt(0);

            expandingSearch = 0;
            GetWorldTimerManager().ClearTimer(timerSearchExpand);
        }
    }
}