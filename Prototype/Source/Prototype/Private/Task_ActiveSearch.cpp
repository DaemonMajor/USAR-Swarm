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

        FRotator rot = FRotator(0, 105, 0);
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
void AUSARAgent::FlockReadyToSearch()
{
    for (AUSARAgent* n : neighborAgents) {
        if (!(n->statusReadyToSearch || n->statusActiveSearch)) {
            return;
        }
    }

    GetWorldTimerManager().ClearTimer(timerCheckSearchReady);
    GetWorldTimerManager().ClearTimer(timerMoveTask);
    GetWorldTimerManager().SetTimer(timerSearchTask, this, &AUSARAgent::ActiveSearchHandle, RATE_SEARCH_TASK, true);

    BeginSearch();
}

/* Initiates search behavior.
*
*/
void AUSARAgent::BeginSearch() {
    flockSize = 1;
    alignWeight = 0;
    cohWeight = 0;
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
    FVector toCenter = flockWPs[0] - GetActorLocation();
    toCenter.Z = 0;
    float distToCtr = toCenter.Size();

    /*DEBUGGING*/
    if (showDebug) {
        FString searchRadText = FString::Printf(TEXT("Agent %d [%f] from wp."), agentID, distToCtr);
        GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, searchRadText, true);
    }
    /*DEBUGGING*/


    if (expandingSearch > 0) {
        sepWeight += 5;
        agentSpacing += 50;

        if(sepWeight >= MAX_SEPARATION_WEIGHT) {
        //if (distToCtr > MAX_SEARCH_RAD) {
            expandingSearch = -1;

            agentSpacing = AGENT_SPACING;
        }
    }
    else if (expandingSearch < 0) {
        if (sepWeight > SEPARATION_WEIGHT) {
            sepWeight -= 5;
        }
        if (agentSpacing > AGENT_SPACING) {
            agentSpacing -= 50;
        }

        //int readyNeighbors = 1;     //include self
        //for (AUSARAgent* n : neighborAgents) {
        //    if (!n->statusActiveSearch) {
        //        readyNeighbors++;
        //    }
        //}

        if (sepWeight <= SEPARATION_WEIGHT) {
        //if (distToCtr < 100 * sqrt(10 * (readyNeighbors))) {
            alignWeight  = ALIGNMENT_WEIGHT;
            cohWeight    = COHESION_WEIGHT;
            sepWeight    = SEPARATION_WEIGHT;
            targetHeight = MOVE_HEIGHT;

            expandingSearch = 0;

            statusActiveSearch  = false;
            statusLoitering     = true;
            flockWPs.RemoveAt(0);

            GetWorldTimerManager().ClearTimer(timerSearchTask);
            GetWorldTimerManager().ClearTimer(timerSearchExpand);
            GetWorldTimerManager().SetTimer(timerCheckMoveReady, this, &AUSARAgent::FlockReadyToMove, 1.f, true, CalcWaitTime());
        }
    }
}

float AUSARAgent::CalcWaitTime()
{
    float waitTime = 15;
    if (numNeighbors < flockSize - 1) {
        waitTime += WAIT_FACTOR * sqrt(flockSize - numNeighbors);
    }

    return waitTime;
}