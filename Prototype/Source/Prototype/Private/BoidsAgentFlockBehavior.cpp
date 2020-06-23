// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidsAgentFlockBehavior.h"
#include "BoidsAgent.h"
#include "AIController.h"
#include "Engine/Engine.h"
#include "Math/Vector.h"

UBoidsAgentFlockBehavior::UBoidsAgentFlockBehavior()
{
    bNotifyBecomeRelevant = true;
}

void UBoidsAgentFlockBehavior::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::OnBecomeRelevant(OwnerComp, NodeMemory);

    ABoidsAgent* agent = Cast<ABoidsAgent>(OwnerComp.GetAIOwner()->GetPawn());
    FVector alignFactor = getAlignment(agent) * agent->alignmentWeight;
    FVector cohFactor = getCohesion(agent) * agent->cohesionWeight;
    FVector sepFactor = getSeparation(agent) * agent->separationWeight;

    FVector newVel = calcNewVector(agent, alignFactor, cohFactor, sepFactor) - agent->GetActorLocation();
    agent->setVelocity(newVel);

    /*DEBUGGING*/
    agent->alignmentFactor = alignFactor.Size();
    agent->cohesionFactor = cohFactor.Size();
    agent->separationFactor = sepFactor.Size();
    /*DEBUGGING*/
}

/**
*   Calculate average velocity of neighbors for agent.
*
*   @param agent Agent to calculate alignment vector for.
*   @return Average velocity of neighbors. Returns zero if agent has no neighbors.
*/
FVector UBoidsAgentFlockBehavior::getAlignment(ABoidsAgent* agent)
{
    FVector alignVector = FVector::ZeroVector;

    TArray<ABoidsAgent*> neighbors = agent->getNeighbors();
    for (ABoidsAgent* boid : neighbors) {
        alignVector += boid->GetVelocity();
    }
    alignVector /= neighbors.Num();

    agent->alignVector = alignVector;
    return alignVector;
}

/**
*   Calculate center of mass of neighbors for agent.
*
*   @param agent Agent to calculate cohesion vector for.
*   @return Vector pointing to center mass of agent's neighbors. Returns zero if agent has no neighbors.
*/
FVector UBoidsAgentFlockBehavior::getCohesion(ABoidsAgent* agent)
{
    FVector centerMass = FVector::ZeroVector;

    TArray<ABoidsAgent*> neighbors = agent->getNeighbors();
    for (ABoidsAgent* boid : neighbors) {
        centerMass += boid->GetActorLocation();
    }
    centerMass /= neighbors.Num();

    agent->flockCenter = centerMass;
    return centerMass;
}

/**
*   Calculate negative direction to neighbors for agent. Closer neighbors provide greater impetus.
*
*   @param agent Agent to calculate separation vector for.
*   @return Vector pointing away from neighbors.
*/
FVector UBoidsAgentFlockBehavior::getSeparation(ABoidsAgent* agent)
{
    FVector sepDir = FVector::ZeroVector;

    TArray<ABoidsAgent*> neighbors = agent->getNeighbors();
    FVector agentLoc = agent->GetActorLocation();
    for (ABoidsAgent* boid : neighbors) {
        FVector boidLoc = boid->GetActorLocation();
        FVector separation = agentLoc - boidLoc;
        
        float sepFactor = 0;
        float dist = separation.Size();
        float spacing = agent->neighborRadius * agent->agentSpacing;
        if (dist < spacing) {
            sepFactor = FMath::Pow(spacing - dist, 0.5f);
        }
        sepFactor = FMath::Clamp(sepFactor, 0.f, 1.f);

        sepDir += separation * sepFactor;
    }

    agent->sepVector = sepDir;
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
FVector UBoidsAgentFlockBehavior::calcNewVector(ABoidsAgent* agent, FVector alignFactor, FVector cohFactor, FVector sepFactor)
{
    return alignFactor + cohFactor + sepFactor;
}