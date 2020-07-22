// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"

void AUSARAgent::MaintainHeightHandle()
{
    float agentHeight = GetActorLocation().Z;
    float minHeight = targetHeight - heightVariance;
    float maxHeight = targetHeight + heightVariance;

    bool isInRange = (minHeight < agentHeight) && (agentHeight < maxHeight);
    if (!isInRange) {
        MaintainHeightTask();

        if (!statusAvoiding && !statusAvoiding) {
            statusClimbing = true;
        }
    }
    else {
        SetHeightVector(FVector::ZeroVector);

        statusClimbing = false;
    }
}

void AUSARAgent::MaintainHeightTask()
{
    float agentHeight = GetActorLocation().Z;

    FVector correctionVector = FVector::ZeroVector;
    if (agentHeight < targetHeight) {
        correctionVector.Z = MAX_SPEED/2;   // fly up at half max thrust
    }
    else if (agentHeight > targetHeight) {
        correctionVector.Z = -(MAX_SPEED/2);   // fly down at half max thrust
    }

    SetHeightVector(correctionVector);
}