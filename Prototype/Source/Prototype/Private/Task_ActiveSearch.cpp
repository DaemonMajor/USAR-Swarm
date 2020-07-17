// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"
#include "DrawDebugHelpers.h"

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
        FVector moveVec = rot.RotateVector(toCenter);

        searchVector = moveVec.GetClampedToSize(SEARCH_SPEED, SEARCH_SPEED);

        /*DEBUGGING*/
        if (showDebug) {
            DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + searchVector, 10.f, FColor::Orange, false, 0.25, 0, 1.f);
        }
        /*DEBUGGING*/
    }
}

void AUSARAgent::ExpandSearch()
{
    sepWeight += 5;

    if (sepWeight > MAX_SEPARATION_WEIGHT) {
        statusActiveSearch = false;
        flockWPs.RemoveAt(0);

        alignWeight = ALIGNMENT_WEIGHT;
        cohWeight = COHESION_WEIGHT;
        sepWeight = SEPARATION_WEIGHT;
        agentSpacing = AGENT_SPACING;

        GetWorldTimerManager().ClearTimer(timerSearchExpand);
    }
}