// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"

void AUSARAgent::HeightTask()
{
    float agentHeight = GetActorLocation().Z;

    FVector correctionVector = FVector::ZeroVector;
    if (agentHeight < targetHeight) {
        correctionVector.Z = maxSpeed/2;   // fly up at half max thrust
    }
    else if (agentHeight > targetHeight) {
        correctionVector.Z = -(maxSpeed/2);   // fly down at half max thrust
    }

    SetHeightVector(correctionVector);

    /*DEBUGGING*/
    //FString statusText = FString::Printf(TEXT("Agent %d maintaining height."), agent->agentID);
    //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Yellow, statusText, true);
    /*DEBUGGING*/
}