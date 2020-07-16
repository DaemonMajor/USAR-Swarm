// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"

void AUSARAgent::ActiveSearchTask()
{
    FVector waypoint;
    GetSearchWP(waypoint);
    
    if (FVector::PointsAreNear(GetActorLocation(), waypoint, 5)) {
        RemoveSearchWP();
        
        if (!GetSearchWP(waypoint)) {
            waypoint = GetActorLocation();
            statusActiveSearch = false;
        }

        /*DEBUGGING*/
        //if (showDebug) {
        //    FString wpRemovedText = FString::Printf(TEXT("Agent %d reached search waypoint."), agentID);
        //    GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, wpRemovedText, true);
        //}
        /*DEBUGGING*/
    }

    FVector targetVector = waypoint - GetActorLocation();
    targetVector = targetVector.GetClampedToSize(searchSpeed, searchSpeed);

    SetSearchVector(targetVector);
}