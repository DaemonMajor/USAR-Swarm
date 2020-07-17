// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"

void AUSARAgent::FlockHandle()
{
    if (true) {
        FlockTask();
    }
}

void AUSARAgent::FlockTask()
{
    FVector alignFactor = alignWeight * GetAlignment();
    FVector cohFactor = cohWeight * GetCohesion();
    FVector sepFactor = sepWeight * GetSeparation();

    flockVector = CalcNewVector(alignFactor, cohFactor, sepFactor);

    /*DEBUGGING*/
    alignmentFactor = alignFactor.Size();
    cohesionFactor = cohFactor.Size();
    separationFactor = sepFactor.Size();
    /*DEBUGGING*/

    /*DEBUGGING*/
    if (showDebug) {
        DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + flockVector, 10.f, FColor::Turquoise, false, 0.15, 0, 1.f);
    }
    /*DEBUGGING*/
}

/**
*   Calculate average velocity of neighbors for agent.
*
*   @param agent Agent to calculate alignment vector for.
*   @return Average velocity of neighbors. Returns zero if agent has no neighbors.
*/
FVector AUSARAgent::GetAlignment()
{
    FVector alVec = FVector::ZeroVector;

    TArray<AUSARAgent*> neighbors = GetNeighbors();

    for (AUSARAgent* boid : neighbors) {
        if (boid) {
            alVec += boid->GetVelocity();
        }
    }
    alVec /= neighbors.Num();

    /*DEBUGGING*/
    alignVector = alVec;
    /*DEBUGGING*/

    return alVec;
}

/**
*   Calculate center of mass of neighbors relative to agent.
*
*   @param agent Agent to calculate cohesion vector for.
*   @return Vector pointing to center mass of agent's neighbors. Returns zero if agent has no neighbors.
*/
FVector AUSARAgent::GetCohesion()
{
    FVector centerMass = FVector::ZeroVector;

    TArray<AUSARAgent*> neighbors = GetNeighbors();
    for (AUSARAgent* boid : neighbors) {
        if (boid) {
            centerMass += boid->GetActorLocation();
        }
    }
    centerMass /= neighbors.Num();
    centerMass -= GetActorLocation();

    /*DEBUGGING*/
    flockCenter = centerMass;
    /*DEBUGGING*/

    return centerMass;
}

/**
*   Calculate negative direction to neighbors for agent. Closer neighbors provide greater impetus.
*
*   @param agent Agent to calculate separation vector for.
*   @return Vector pointing away from neighbors.
*/
FVector AUSARAgent::GetSeparation()
{
    FVector sepDir = FVector::ZeroVector;

    TArray<AUSARAgent*> neighbors = GetNeighbors();
    FVector agentLoc = GetActorLocation();
    FVector boidLoc, separation;
    for (AUSARAgent* n : neighbors) {
        if (n) {
            boidLoc = n->GetActorLocation();
            separation = agentLoc - boidLoc;

            float sepFactor = 0;
            float dist = separation.Size();
            float spacing = agentSpacing;
            if (dist < spacing) {
                sepFactor = -5 * (FMath::Loge(dist) - FMath::Loge(agentSpacing));
            }

            sepDir += sepFactor * separation;

            /*DEBUGGING*/
            //if (agent->showDebug) {
            //    FString sepText = FString::Printf(TEXT("Agent %d->%d sepFactor = %f (%f)."), agent->agentID, n->agentID, sepFactor, dist);
            //    GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Yellow, sepText, true);
            //}
            /*DEBUGGING*/
        }
    }

    /*DEBUGGING*/
    sepVector = sepDir;
    /*DEBUGGING*/

    return sepDir;
}

/**
*   Calculate new vector for agent based on alignment, cohesion, and separation factors.
*
*   @param agent Agent to calculate velocity for.
*   @param alignFactor Alignment factor.
*   @param cohFactor Cohesion factor.
*   @param sepFactor Separation factor.
*   @return Velocity vector.
*/
FVector AUSARAgent::CalcNewVector(FVector alignFactor, FVector cohFactor, FVector sepFactor)
{
    return alignFactor + cohFactor + sepFactor;
}