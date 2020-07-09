// Fill out your copyright notice in the Description page of Project Settings.


#include "FlockTask.h"
#include "USARAgent.h"
#include "AIController.h"

EBTNodeResult::Type UFlockTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());
    FVector alignFactor = agent->alignmentWeight * GetAlignment(agent);
    FVector cohFactor = agent->cohesionWeight * GetCohesion(agent);
    FVector sepFactor = agent->separationWeight * GetSeparation(agent);

    FVector flockVector = CalcNewVector(agent, alignFactor, cohFactor, sepFactor);
    agent->SetFlockVector(flockVector);

    /*DEBUGGING*/
    agent->alignmentFactor = alignFactor.Size();
    agent->cohesionFactor = cohFactor.Size();
    agent->separationFactor = sepFactor.Size();
    /*DEBUGGING*/

    /*DEBUGGING*/
    //FString statusText = FString::Printf(TEXT("Agent %d flocking."), agent->agentID);
    //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.0f, FColor::Yellow, statusText , true);
    /*DEBUGGING*/

    return EBTNodeResult::Succeeded;
}

/**
*   Calculate average velocity of neighbors for agent.
*
*   @param agent Agent to calculate alignment vector for.
*   @return Average velocity of neighbors. Returns zero if agent has no neighbors.
*/
FVector UFlockTask::GetAlignment(AUSARAgent* agent)
{
    FVector alignVector = FVector::ZeroVector;

    TArray<AUSARAgent*> neighbors = agent->GetNeighbors();

    for (AUSARAgent* boid : neighbors) {
        if (boid) {
            alignVector += boid->GetVelocity();
        }
    }
    alignVector /= neighbors.Num();

    /*DEBUGGING*/
    agent->alignVector = alignVector;
    /*DEBUGGING*/

    return alignVector;
}

/**
*   Calculate center of mass of neighbors relative to agent.
*
*   @param agent Agent to calculate cohesion vector for.
*   @return Vector pointing to center mass of agent's neighbors. Returns zero if agent has no neighbors.
*/
FVector UFlockTask::GetCohesion(AUSARAgent* agent)
{
    FVector centerMass = FVector::ZeroVector;

    TArray<AUSARAgent*> neighbors = agent->GetNeighbors();
    for (AUSARAgent* boid : neighbors) {
        if (boid) {
            centerMass += boid->GetActorLocation();
        }
    }
    centerMass /= neighbors.Num();
    centerMass -= agent->GetActorLocation();

    /*DEBUGGING*/
    agent->flockCenter = centerMass;
    /*DEBUGGING*/

    return centerMass;
}

/**
*   Calculate negative direction to neighbors for agent. Closer neighbors provide greater impetus.
*
*   @param agent Agent to calculate separation vector for.
*   @return Vector pointing away from neighbors.
*/
FVector UFlockTask::GetSeparation(AUSARAgent* agent)
{
    FVector sepDir = FVector::ZeroVector;

    TArray<AUSARAgent*> neighbors = agent->GetNeighbors();
    FVector agentLoc = agent->GetActorLocation();
    FVector boidLoc, separation;
    for (AUSARAgent* n : neighbors) {
        if (n) {
            boidLoc = n->GetActorLocation();
            separation = agentLoc - boidLoc;

            float sepFactor = 0;
            float dist = separation.Size();
            float spacing = agent->agentSpacing;
            if (dist < spacing) {
                sepFactor = -5 * FMath::Loge(dist) + 28.5;     // zeroed for spacing == 300
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
    agent->sepVector = sepDir;
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
FVector UFlockTask::CalcNewVector(AUSARAgent* agent, FVector alignFactor, FVector cohFactor, FVector sepFactor)
{
    return alignFactor + cohFactor + sepFactor;
}