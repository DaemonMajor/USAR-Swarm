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

        FRotator rot90Deg = FRotator(0, 90, 0);
        FVector moveVec = rot90Deg.RotateVector(toCenter);

        searchVector = moveVec.GetClampedToSize(SEARCH_SPEED, SEARCH_SPEED);

        separationWeight += 0.1;
    }

    if (separationWeight > MAX_SEPARATION_WEIGHT) {
        statusActiveSearch = false;
        flockWPs.RemoveAt(0);
    }
}

//void AUSARAgent::ActiveSearchTask()
//{
//    FVector waypoint;
//    GetSearchWP(waypoint);
//    
//    if (FVector::PointsAreNear(GetActorLocation(), waypoint, 5)) {
//        RemoveSearchWP();
//        
//        if (!GetSearchWP(waypoint)) {
//            waypoint = GetActorLocation();
//            statusActiveSearch = false;
//        }
//
//        /*DEBUGGING*/
//        //if (showDebug) {
//        //    FString wpRemovedText = FString::Printf(TEXT("Agent %d reached search waypoint."), agentID);
//        //    GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, wpRemovedText, true);
//        //}
//        /*DEBUGGING*/
//    }
//
//    FVector targetVector = waypoint - GetActorLocation();
//    targetVector = targetVector.GetClampedToSize(searchSpeed, searchSpeed);
//
//    SetSearchVector(targetVector);
//}