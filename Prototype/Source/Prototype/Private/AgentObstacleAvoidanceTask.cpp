// Fill out your copyright notice in the Description page of Project Settings.


#include "AgentObstacleAvoidanceTask.h"
#include "SwarmWP.h"
#include "AIController.h"

EBTNodeResult::Type UAgentObstacleAvoidanceTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    ABoidsAgent* agent = Cast<ABoidsAgent>(OwnerComp.GetAIOwner()->GetPawn());
    
    TArray<FVector> safeVectors = LookAhead(agent);
    for (FVector vec : safeVectors) {
        if (CheckVector(agent, vec)) {
            FVector confirmedVector = vec - agent->GetActorLocation();
            // need to transform to local rotation
            agent->SetAvoidanceVector(confirmedVector);
        }
    }

    return EBTNodeResult::Succeeded;
}

TArray<FVector> UAgentObstacleAvoidanceTask::LookAhead(ABoidsAgent* agent)
{
    // Transform agent velocity from local to world coordinates
    FVector targetVector = agent->GetVelocity();
    FRotator velRot = targetVector.Rotation();
    targetVector = TransformToWorld(agent, targetVector) + agent->GetActorLocation();

    // Create array of raycast start/end points in concentric circles around agent
    TArray<FVector> rayStartPts;
    rayStartPts.Add(agent->GetActorLocation());
    TArray<FVector> rayEndPts;
    rayEndPts.Add(targetVector);

    float degStep = 2;  // increase to increase fidelity of raycast cylinders
    for (int circle = 1; circle < agent->bodySize; circle++) {
        FVector offset = FVector(circle, 0, 0);

        for (int deg = 0; deg < 360; deg += degStep) {
            FRotator rot = FRotator(0, 0, deg);
            offset = rot.RotateVector(offset);
            offset = velRot.RotateVector(offset);
            offset = TransformToWorld(agent, offset);

            rayStartPts.Add(agent->GetActorLocation() + offset);
            rayEndPts.Add(targetVector + offset);
        }
    }

    FHitResult hitResult;
    FCollisionQueryParams queryParams;
    queryParams.AddIgnoredActor(agent);
    FCollisionResponseParams responseParams;
    
    TArray<FVector> safeVectors;
    for (int i = 0; i < rayStartPts.Num(); i++) {
        if (!GetWorld()->LineTraceSingleByChannel(hitResult, rayStartPts[i], rayEndPts[i], ECC_WorldStatic, queryParams, responseParams)) {
            safeVectors.Add(rayEndPts[i]);
        }
        else {
            //agent->statusAvoiding = true;
        }
    }

    return safeVectors;
}

bool UAgentObstacleAvoidanceTask::CheckVector(ABoidsAgent* agent, FVector vector)
{
    bool isSafe = false;

    // raycast cone around vector

    return isSafe;
}

FVector UAgentObstacleAvoidanceTask::TransformToWorld(ABoidsAgent* agent, FVector vector)
{
    FRotator agentRot = agent->GetActorRotation().GetInverse();
    FVector transVector = agentRot.RotateVector(vector);

    return transVector;
}