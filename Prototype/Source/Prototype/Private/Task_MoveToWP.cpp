// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"

void AUSARAgent::MoveToWPHandle()
{
    if (!statusActiveSearch) {
        MoveToWPTask();
    }
}

void AUSARAgent::MoveToWPTask()
{
    FVector waypoint;
    FVector targetVector = FVector::ZeroVector;
    if (GetCurrFlockWP(waypoint)) {
        waypoint.Z = targetHeight;

        targetVector = waypoint - GetActorLocation();
        targetVector = targetVector.GetClampedToSize(maxSpeed * 3, maxSpeed * 3);     // set magnitude so agent doesn't slow down as it nears the waypoint
    }

    SetFlockWPVector(targetVector);
}