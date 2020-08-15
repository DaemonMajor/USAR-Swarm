#include "USARAgent.h"

void AUSARAgent::ActiveSearchHandle()
{
    GetWorldTimerManager().ClearTimer(timerMoveTask);

    alignWeight  = 0;
    cohWeight    = 0;
    targetHeight = SEARCH_HEIGHT;

    switch (searchBehaviorType) {
        case SearchBehavior::Spiral : {
            expandingSearch = 1;

            FTimerDelegate searchDel = FTimerDelegate::CreateUObject(this, &AUSARAgent::BBSearch_Revolve, float(10));
            GetWorldTimerManager().SetTimer(timerBBSearchRevolve, searchDel, RATE_BBSEARCH_R, true);
            GetWorldTimerManager().SetTimer(timerBBSearchExpand, this, &AUSARAgent::BBSearch_Expand, RATE_BBSEARCH_E, true);
                
            break;
        }
        case SearchBehavior::Radial: {
            expandingSearch = 1;

            FTimerDelegate searchDel = FTimerDelegate::CreateUObject(this, &AUSARAgent::BBSearch_Revolve, float(90));
            GetWorldTimerManager().SetTimer(timerBBSearchRevolve, searchDel, RATE_BBSEARCH_R, true);
            GetWorldTimerManager().SetTimer(timerBBSearchExpand, this, &AUSARAgent::BBSearch_Expand, RATE_BBSEARCH_E, true);

            break;
        }
        case SearchBehavior::RandomWalk : {
            FRotator turnDeg = FRotator(0, FMath::RandRange(0, 360), 0);
            searchVector = FVector(SEARCH_SPEED, 0, 0);
            searchVector = turnDeg.RotateVector(searchVector);

            GetWorldTimerManager().SetTimer(timerRandWalkSearchStep, this, &AUSARAgent::RandWalkSearchStep, RATE_RWSEARCH, true);
            GetWorldTimerManager().SetTimer(timerRWSearch, this, &AUSARAgent::RandWalkSearch_End, RWSEARCH_LENGTH, false);

            break;
        }
        default :
            statusLoitering = true;
            flockWPs.RemoveAt(0);
            numWPs--;
    }
}

/* Enters active search state neighbor is detected as actively searching.
*
*/
void AUSARAgent::CheckNeighborsSearch()
{
    for (AUSARAgent* n : neighborAgents) {
        if (n->statusActiveSearch) {
            flockWPVector = FVector::ZeroVector;

            statusTraveling    = false;
            statusActiveSearch = true;

            ActiveSearchHandle();

            break;
        }
    }
}

void AUSARAgent::BBSearch_Revolve(float angle)
{
    //if (investigatingVic) {
    //    searchVector   = locatedVictims[locatedVictims.Num()]->GetActorLocation() - GetActorLocation();
    //    searchVector.Z = 0;
    //    searchVector   = searchVector.GetClampedToSize(0, MAX_SPEED);
    //}
    //else {
        FVector centerPt;
        if (GetCurrFlockWP(centerPt)) {
            FVector toCenter = centerPt - GetActorLocation();
            toCenter.Z = 0;

            FRotator rot = FRotator(0, 90 + angle, 0);
            if (expandingSearch < 0) {
                rot = FRotator(0, 90 - angle, 0);
            }

            FVector moveVec = rot.RotateVector(toCenter);

            searchVector = moveVec.GetClampedToSize(SEARCH_SPEED, SEARCH_SPEED);
        }
    //}

    /*DEBUGGING*/
    if (showDebug) {
        DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + searchVector, 10.f, FColor::Silver, false, 0.25, 0, 1.f);
    }
    /*DEBUGGING*/
}

/* Expands then contracts search area covered by flock. Exits search behavior when done.
*
*/
void AUSARAgent::BBSearch_Expand()
{
    if (expandingSearch > 0) {
        sepWeight += 5.f;
        agentSpacing += 50.f;

        if(sepWeight >= MAX_SEPARATION_WEIGHT) {
            expandingSearch = -1;

            agentSpacing = AGENT_SPACING;
        }
    }
    else if (expandingSearch < 0) {
        if (sepWeight > SEPARATION_WEIGHT) {
            sepWeight -= 5.f;
        }
        else {
            searchVector = FVector::ZeroVector;

            alignWeight  = ALIGNMENT_WEIGHT;
            cohWeight    = COHESION_WEIGHT;
            sepWeight    = SEPARATION_WEIGHT;
            targetHeight = MOVE_HEIGHT;

            expandingSearch = 0;

            statusActiveSearch = false;
            statusLoitering    = true;
            flockWPs.RemoveAt(0);
            numWPs--;

            GetWorldTimerManager().ClearTimer(timerBBSearchExpand);
            GetWorldTimerManager().ClearTimer(timerBBSearchRevolve);
            GetWorldTimerManager().SetTimer(timerCheckMoveReady, this, &AUSARAgent::FlockReadyToMove, 1.f, true);
        }
    }
}

/* Random walk based search behavior.
*/
void AUSARAgent::RandWalkSearchStep()
{
    float bNewDir = FMath::FRand();

    if (bNewDir > RW_MOMENTUM) {
        FRotator turnDeg = FRotator(0, FMath::RandRange(-90, 90), 0);
        searchVector = turnDeg.RotateVector(searchVector);
    }
}

void AUSARAgent::RandWalkSearch_End()
{
    searchVector = FVector::ZeroVector;

    alignWeight  = ALIGNMENT_WEIGHT;
    cohWeight    = COHESION_WEIGHT;
    sepWeight    = SEPARATION_WEIGHT;
    targetHeight = MOVE_HEIGHT;

    statusActiveSearch = false;
    statusLoitering = true;
    flockWPs.RemoveAt(0);
    numWPs--;

    GetWorldTimerManager().ClearTimer(timerRWSearch);
    GetWorldTimerManager().ClearTimer(timerRandWalkSearchStep);
    GetWorldTimerManager().SetTimer(timerMoveTask, this, &AUSARAgent::FlockReadyToMove, RATE_WP_TASK, true);
}

float AUSARAgent::CalcWaitTime()
{
    float waitTime = 15;
    if (numNeighbors < flockSize - 1) {
        waitTime += WAIT_FACTOR * sqrt(flockSize - numNeighbors);
    }

    return waitTime;
}