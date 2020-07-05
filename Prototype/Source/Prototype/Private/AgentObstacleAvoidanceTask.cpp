// Fill out your copyright notice in the Description page of Project Settings.


#include "AgentObstacleAvoidanceTask.h"
#include "AIController.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"

EBTNodeResult::Type UAgentObstacleAvoidanceTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());

    if (agent->statusDirectMove) {
        if (agent->GetActorLocation() == agent->GetDirectMoveLoc()) {
            agent->statusDirectMove = false;
        }

        return EBTNodeResult::Succeeded;
    }

    bool obstructed = false;
    TArray<FVector> safeVectors = LookAhead(agent, agent->rawVelocity, obstructed);

    if (obstructed) {
        /*DEBUGGING*/
        FString safeVectorsText = FString::Printf(TEXT("Agent %d detected obstruction."), agent->agentID);
        GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Orange, safeVectorsText, true);
        /*DEBUGGING*/

        if (!agent->statusAvoiding) {
            FVector upVec = FVector(0, 0, agent->obstacleAvoidDist);
            FVector clearVec = FindClearVector(agent, upVec);

            agent->SetAvoidanceVector(clearVec);

            /*DEBUGGING*/
            FString safeVectorFoundText = FString::Printf(TEXT("Agent %d found safe vector."), agent->agentID);
            GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Turquoise, safeVectorFoundText, true);

            DrawDebugPoint(GetWorld(), clearVec + agent->GetActorLocation(), 10, FColor::Green, false, 0.01);
            /*DEBUGGING*/
        }
        else {
            obstructed = false;
            safeVectors = LookAhead(agent, agent->GetVelocity(), obstructed);

            if (obstructed) {
                FVector upVec = FVector(0, 0, agent->obstacleAvoidDist);
                FVector clearVec = FindClearVector(agent, upVec);

                agent->SetAvoidanceVector(clearVec);

                /*DEBUGGING*/
                FString safeVectorFoundText = FString::Printf(TEXT("Agent %d found safe vector."), agent->agentID);
                GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Turquoise, safeVectorFoundText, true);

                DrawDebugPoint(GetWorld(), clearVec + agent->GetActorLocation(), 10, FColor::Green, false, 0.01);
                /*DEBUGGING*/
            }
        }

        agent->statusAvoiding = true;
    }
    else {
        if (agent->statusAvoiding) {
            agent->statusDirectMove = true;

            FVector goToVec = agent->rawVelocity.GetClampedToSize(agent->obstacleAvoidDist, agent->obstacleAvoidDist);
            agent->SetDirectMoveLoc(goToVec + agent->GetActorLocation());
        }

        agent->statusAvoiding = false;
        agent->SetAvoidanceVector(FVector::ZeroVector);
    }

    return EBTNodeResult::Succeeded;
}

/* Raycast in a cylinder in the direction of the agent's velocity to look for obstacles. Sets the agent status to avoiding if obstacle is detected.
*  Returns array of "safe" vectors.
*
*   @param agent Agent to raycast for.
*   @return Array of obstacle-free vectors.
*/
TArray<FVector> UAgentObstacleAvoidanceTask::LookAhead(AUSARAgent* agent, FVector vel, bool& obstructed)
{
    // Transform agent velocity from local to world coordinates
    FVector targetVector = vel;
    FRotator velRot = UKismetMathLibrary::FindLookAtRotation(FVector::ZeroVector, targetVector);
    targetVector = TransformToWorld(agent, targetVector) + agent->GetActorLocation();

    // Create array of raycast start/end points in concentric circles around agent
    TArray<FVector> rayStartPts;
    rayStartPts.Add(agent->GetActorLocation());
    TArray<FVector> rayEndPts;
    rayEndPts.Add(targetVector);

    float degStep = 15;  // decrease to increase fidelity of raycast cylinders. recommend factor of 360
    for (int circle = 1; circle < agent->bodySize; circle += 5) {
        FVector offset = FVector(0, circle, 0);

        float deg = 0;
        for (int step = 0; step < 360/degStep; step++) {
            if (deg == 180 - degStep) {
                deg = -180;
            }

            FRotator rot = FRotator(0, 0, deg);
            offset = rot.RotateVector(offset);
            //FRotator corrRot = FRotator(0, velRot.Yaw, 0);    
            //offset = corrRot.RotateVector(offset);
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
            safeVectors.Add(rayEndPts[i]);
        }
        else {
            obstructed = true;
            
            /*DEBUGGING*/
            DrawDebugPoint(GetWorld(), hitResult.ImpactPoint, 3, FColor::Red, false, 0.01);
            /*DEBUGGING*/
        }
    }

    return safeVectors;
}

/* Sweep the given vector in a spiral, checking for collision. Returns the first vector that hits no obstacle.
*
*   @param agent The agent to perform the sweep for.
*   @param startingVec The vector to start the sweep from.
*   @return The first vector that hits no obstacles in a LineTraceSingleByChannel call. Returns null vector if no clear vector found.
*/
FVector UAgentObstacleAvoidanceTask::FindClearVector(AUSARAgent* agent, FVector startingVec) {
    float offset = 0;
    float degIncr = 15;     // in case increment needs to be changed later

    int i = 0;
    FRotator rot = FRotator(0, degIncr * i, 0);     // rotate around z axis
    while (true) {
        FVector checkVec = startingVec + FVector(offset, 0, 0);     // currently assumes given vector is up vector
        checkVec = rot.RotateVector(checkVec);
        FHitResult hitResult;
        FCollisionQueryParams queryParams;
        queryParams.AddIgnoredActor(agent);
        FCollisionResponseParams responseParams;

        // if vector is clear
        if (!GetWorld()->LineTraceSingleByChannel(hitResult, agent->GetActorLocation(), checkVec + agent->GetActorLocation(), ECC_WorldStatic, queryParams, responseParams)) {
            return checkVec;
        }
    }

    return FVector(NULL, NULL, NULL);
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

FVector UAgentObstacleAvoidanceTask::TransformToWorld(AUSARAgent* agent, FVector vector)
{
    FRotator agentRot = agent->GetActorRotation().GetInverse();
    FVector transVector = agentRot.RotateVector(vector);

    return transVector;
}