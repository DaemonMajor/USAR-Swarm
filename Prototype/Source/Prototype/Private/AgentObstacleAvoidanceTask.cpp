// Fill out your copyright notice in the Description page of Project Settings.


#include "AgentObstacleAvoidanceTask.h"
#include "SwarmWP.h"
#include "AIController.h"

EBTNodeResult::Type UAgentObstacleAvoidanceTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());
    
    TArray<FVector> safeVectors = LookAhead(agent);

    if (agent->statusAvoiding) {
        if (safeVectors.Num()) {
            /*DEBUGGING*/
            FString avoidingText = FString::Printf(TEXT("Agent %d avoiding obstacle."), agent->agentID);
            GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, avoidingText, true);
            /*DEBUGGING*/

            for (FVector vec : safeVectors) {
                if (CheckVector(agent, vec)) {
                    FVector confirmedVector = vec - agent->GetActorLocation();
                    // need to transform to local rotation

                    agent->SetAvoidanceVector(confirmedVector);
                }
            }
        }
        else {
            /*DEBUGGING*/
            FString avoidingText = FString::Printf(TEXT("Agent %d blocked. Attempting to move around obstacle."), agent->agentID);
            GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, avoidingText, true);
            /*DEBUGGING*/

            // turn 90 degrees yaw, then in 15 deg increments until clear
            FVector rightTurn = FRotator(0, 90, 0).RotateVector(agent->GetActorLocation());
            FVector clearVec = FindClearVector(agent, rightTurn);

            

            agent->SetAvoidanceVector(clearVec);
        }
    }

    return EBTNodeResult::Succeeded;
}

/* Raycast in a cylinder in the direction of the agent's velocity to look for obstacles. Sets the agent status to avoiding if obstacle is detected.
*  Returns array of "safe" vectors.
*
*   @param agent Agent to raycast for.
*   @return Array of obstacle-free vectors.
*/
TArray<FVector> UAgentObstacleAvoidanceTask::LookAhead(AUSARAgent* agent)
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
    
    // collect vectors with no obstacles.
    TArray<FVector> safeVectors;
    agent->statusAvoiding = false;
    for (int i = 0; i < rayStartPts.Num(); i++) {
        if (!GetWorld()->LineTraceSingleByChannel(hitResult, rayStartPts[i], rayEndPts[i], ECC_WorldStatic, queryParams, responseParams)) {
            safeVectors.Add(rayEndPts[i]);
        }
        else {
            agent->statusAvoiding = true;
        }
    }

    return safeVectors;
}

bool UAgentObstacleAvoidanceTask::CheckVector(AUSARAgent* agent, FVector vector)
{
    bool isSafe = false;

    // raycast cone around vector

    return true;    // placeholder
}

/* Sweep a given vector in an arc in 15 degree increments, checking for collisions. Returns the first vector that hits no obstacle.
*
*   @param agent The agent to perform the sweep for.
*   @param startingVec The vector to start the sweep from.
*   @return The first vector that hits no obstacles in a LineTraceSingleByChannel call. Returns null vector if no clear vector found.
*/
FVector UAgentObstacleAvoidanceTask::FindClearVector(AUSARAgent* agent, FVector startingVec) {
    float degIncr = 15;     // in case increment needs to be changed later

    for (int i = 0; i < 360/degIncr; i++) {
        FHitResult hitResult;
        FCollisionQueryParams queryParams;
        queryParams.AddIgnoredActor(agent);
        FCollisionResponseParams responseParams;
        FRotator rot = FRotator(0, degIncr * i, 0);     // rotate around z axis
        FVector clearVec = rot.RotateVector(startingVec);

        // if vector is clear
        if (!GetWorld()->LineTraceSingleByChannel(hitResult, agent->GetActorLocation(), clearVec, ECC_WorldStatic, queryParams, responseParams)) {
            return clearVec;
        }
    }

    return FVector(NULL, NULL, NULL);
}

FVector UAgentObstacleAvoidanceTask::TransformToWorld(AUSARAgent* agent, FVector vector)
{
    FRotator agentRot = agent->GetActorRotation().GetInverse();
    FVector transVector = agentRot.RotateVector(vector);

    return transVector;
}