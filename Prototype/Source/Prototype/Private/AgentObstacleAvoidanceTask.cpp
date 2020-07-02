// Fill out your copyright notice in the Description page of Project Settings.


#include "AgentObstacleAvoidanceTask.h"
#include "SwarmWP.h"
#include "AIController.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"

EBTNodeResult::Type UAgentObstacleAvoidanceTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());

    bool activelyAvoiding = agent->statusAvoiding;
    TArray<FVector> safeVectors;
    
    // if agent is already detoured to avoid an obstacle, check rawVelocity
    if (activelyAvoiding) {
        safeVectors = LookAhead(agent, agent->rawVelocity);

        if (safeVectors.Num()) {
            /*DEBUGGING*/
            FString safeVectorsText = FString::Printf(TEXT("Agent %d detected obstruction (%d)."), agent->agentID, safeVectors.Num());
            GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Orange, safeVectorsText, true);
            /*DEBUGGING*/

            for (FVector vec : safeVectors) {
                if (CheckVector(agent, vec)) {
                    FVector confirmedVector = vec - agent->GetActorLocation();
                    // need to transform to local rotation

                    agent->SetAvoidanceVector(confirmedVector);

                    return EBTNodeResult::Succeeded;
                }
            }
        }
    }
    
    safeVectors = LookAhead(agent, agent->GetVelocity());

    if (safeVectors.Num()) {
        /*DEBUGGING*/
        FString safeVectorsText = FString::Printf(TEXT("Agent %d detected obstruction (%d)."), agent->agentID, safeVectors.Num());
        GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, safeVectorsText, true);
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
        //FString avoidingText = FString::Printf(TEXT("Agent %d blocked. Attempting to move around obstacle."), agent->agentID);
        //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, avoidingText, true);
        /*DEBUGGING*/

        // turn 90 degrees yaw, then in 15 deg increments until clear
        FVector rightTurn = FRotator(0, 90, 0).RotateVector(agent->GetActorLocation());
        FVector clearVec = FindClearVector(agent, rightTurn);

        agent->SetAvoidanceVector(clearVec);
    }

    return EBTNodeResult::Succeeded;
}

/* Raycast in a cylinder in the direction of the agent's velocity to look for obstacles. Sets the agent status to avoiding if obstacle is detected.
*  Returns array of "safe" vectors.
*
*   @param agent Agent to raycast for.
*   @return Array of obstacle-free vectors.
*/
TArray<FVector> UAgentObstacleAvoidanceTask::LookAhead(AUSARAgent* agent, FVector vel)
{
    // Transform agent velocity from local to world coordinates
    FVector targetVector = vel;
    //FRotator velRot = UKismetMathLibrary::FindLookAtRotation(FVector::ZeroVector, agent->GetVelocity());
    targetVector = TransformToWorld(agent, targetVector) + agent->GetActorLocation();

    // Create array of raycast start/end points in concentric circles around agent
    TArray<FVector> rayStartPts;
    rayStartPts.Add(agent->GetActorLocation());
    TArray<FVector> rayEndPts;
    rayEndPts.Add(targetVector);

    float degStep = 15;  // decrease to increase fidelity of raycast cylinders. recommend factor of 360
    for (int circle = 1; circle < agent->bodySize; circle++) {
        FVector offset = FVector(0, circle, 0);

        float deg = 0;
        for (int step = 0; step < 360/degStep; step++) {
            if (deg == 180 - degStep) {
                deg = -180;
            }

            FRotator rot = FRotator(0, 0, deg);
            offset = rot.RotateVector(offset);
            //offset = velRot.RotateVector(offset);     // need to figure out proper rotation
            offset = TransformToWorld(agent, offset);

            rayStartPts.Add(agent->GetActorLocation() + offset);
            rayEndPts.Add(targetVector + offset);

            deg += degStep;

            /*DEBUGGING*/
            if (circle == agent->bodySize - 1) {
                DrawDebugLine(GetWorld(), agent->GetActorLocation() + offset, targetVector + offset, FColor::Orange, false, 0.001, 0, 1);
            }
            /*DEBUGGING*/
        }
    }

    FHitResult hitResult;
    FCollisionQueryParams queryParams;
    queryParams.AddIgnoredActor(agent);
    FCollisionResponseParams responseParams;
    
    TArray<FVector> safeVectors;

    // collect vectors with no obstacles.
    for (int i = 0; i < rayStartPts.Num(); i++) {
        if (!GetWorld()->LineTraceSingleByChannel(hitResult, rayStartPts[i], rayEndPts[i], ECC_WorldStatic, queryParams, responseParams)) {
            //FVector* vPtr = new FVector(rayEndPts[i].X, rayEndPts[i].Y, rayEndPts[i].Z);
            safeVectors.Add(rayEndPts[i]);
        }
        else {
            agent->statusAvoiding = true;
        }
    }

    return safeVectors;
}

/* Check area around vector. Returns true only if all vector checks found to be clear.
*
*   @param agent The agent to perform the check for.
*   @param vector The vector to check.
*   @return True if area around vector found clear.
*/
bool UAgentObstacleAvoidanceTask::CheckVector(AUSARAgent* agent, FVector vector)
{
    float degStep = 6;  // increase to increase fidelity of raycast cylinders
    for (int circle = 1; circle < agent->bodySize; circle++) {
        FVector endPt = FVector(circle, 0, 0);

        for (int deg = 0; deg < 360; deg += degStep) {
            FRotator rot = FRotator(0, 0, deg);
            endPt = rot.RotateVector(endPt);
            endPt = vector.Rotation().RotateVector(endPt);
            endPt = vector + TransformToWorld(agent, endPt);

            FHitResult hitResult;
            FCollisionQueryParams queryParams;
            queryParams.AddIgnoredActor(agent);
            FCollisionResponseParams responseParams;
            if (GetWorld()->LineTraceSingleByChannel(hitResult, agent->GetActorLocation(), endPt, ECC_WorldStatic, queryParams, responseParams)) {
                return false;
            }
        }
    }

    return true;
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