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
        heightVector = FVector::ZeroVector;

        statusClimbing = false;
    }
}

void AUSARAgent::MaintainHeightTask()
{
    float agentHeight = GetActorLocation().Z;
    
    FVector correctionVector = FVector::ZeroVector;
    correctionVector.Z = FMath::Clamp(targetHeight - agentHeight, -MAX_SPEED, MAX_SPEED);
    
    heightVector = correctionVector;
}