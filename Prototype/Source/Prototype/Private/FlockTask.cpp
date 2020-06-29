// Fill out your copyright notice in the Description page of Project Settings.


#include "FlockTask.h"
#include "BoidsAgent.h"
#include "AIController.h"

EBTNodeResult::Type UFlockTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    ABoidsAgent* agent = Cast<ABoidsAgent>(OwnerComp.GetAIOwner()->GetPawn());
    FVector alignFactor = GetAlignment(agent) * agent->alignmentWeight;
    FVector cohFactor = GetCohesion(agent) * agent->cohesionWeight;
    FVector sepFactor = GetSeparation(agent) * agent->separationWeight;

    FVector flockVector = CalcNewVector(agent, alignFactor, cohFactor, sepFactor);
    agent->SetFlockVector(flockVector);

    /*DEBUGGING*/
    //agent->alignmentFactor = alignFactor.Size();
    //agent->cohesionFactor = cohFactor.Size();
    //agent->separationFactor = sepFactor.Size();
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
FVector UFlockTask::GetAlignment(ABoidsAgent* agent)
{
    FVector alignVector = FVector::ZeroVector;

    TArray<ABoidsAgent*> neighbors = agent->GetNeighbors();

    for (ABoidsAgent* boid : neighbors) {
        if (boid) {
            alignVector += boid->GetVelocity();
        }
    }
    alignVector /= neighbors.Num();

    //agent->alignVector = alignVector;
    return alignVector;
}

/**
*   Calculate center of mass of neighbors relative to agent.
*
*   @param agent Agent to calculate cohesion vector for.
*   @return Vector pointing to center mass of agent's neighbors. Returns zero if agent has no neighbors.
*/
FVector UFlockTask::GetCohesion(ABoidsAgent* agent)
{
    FVector centerMass = FVector::ZeroVector;

    TArray<ABoidsAgent*> neighbors = agent->GetNeighbors();
    for (ABoidsAgent* boid : neighbors) {
        if (boid) {
            centerMass += boid->GetActorLocation();
        }
    }
    centerMass /= neighbors.Num();
    centerMass -= agent->GetActorLocation();

    //agent->flockCenter = centerMass;
    return centerMass;
}

/**
*   Calculate negative direction to neighbors for agent. Closer neighbors provide greater impetus.
*
*   @param agent Agent to calculate separation vector for.
*   @return Vector pointing away from neighbors.
*/
FVector UFlockTask::GetSeparation(ABoidsAgent* agent)
{
    FVector sepDir = FVector::ZeroVector;

    TArray<ABoidsAgent*> neighbors = agent->GetNeighbors();
    FVector agentLoc = agent->GetActorLocation();
    FVector boidLoc, separation;
    for (ABoidsAgent* boid : neighbors) {
        if (boid) {
            boidLoc = boid->GetActorLocation();
            separation = agentLoc - boidLoc;

            float sepFactor = 0;
            float dist = separation.Size();
            float spacing = agent->agentSpacing;
            if (dist < spacing) {
                sepFactor = FMath::Pow(spacing - dist, 1.5f);
            }

            sepDir += separation * sepFactor;
        }
    }

    //agent->sepVector = sepDir;
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
FVector UFlockTask::CalcNewVector(ABoidsAgent* agent, FVector alignFactor, FVector cohFactor, FVector sepFactor)
{
    return alignFactor + cohFactor + sepFactor;
}