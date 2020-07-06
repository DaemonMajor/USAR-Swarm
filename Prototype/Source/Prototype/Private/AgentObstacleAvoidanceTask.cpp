// Fill out your copyright notice in the Description page of Project Settings.


#include "AgentObstacleAvoidanceTask.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

EBTNodeResult::Type UAgentObstacleAvoidanceTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AUSARAgent* agent = Cast<AUSARAgent>(OwnerComp.GetAIOwner()->GetPawn());

    if (agent->statusDirectMove) {
        if (agent->GetActorLocation().Equals(agent->GetDirectMoveLoc(), 1)) {
            agent->statusDirectMove = false;
            agent->SetDirectMoveLoc(FVector::ZeroVector);
        }

        return EBTNodeResult::Succeeded;
    }

    bool obstructed = false;
    TArray<FVector> safeVectors = LookAhead(agent, agent->rawVelocity, obstructed);

    if (obstructed) {
        /*DEBUGGING*/
        //FString obstructedText = FString::Printf(TEXT("Agent %d detected obstruction."), agent->agentID);
        //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Orange, obstructedText, true);
        /*DEBUGGING*/

        if (!agent->statusAvoiding) {
            FVector clearVec;
            if (FindClearVector(agent, clearVec, 5000)) {
                agent->SetAvoidanceVector(clearVec);
            }
            else {
                agent->SetStatusStuck();

                /*DEBUGGING*/
                FString stuckText = FString::Printf(TEXT("Agent %d stuck."), agent->agentID);
                GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Red, stuckText, true);
                /*DEBUGGING*/
            }
        }
        else {
            obstructed = false;
            safeVectors = LookAhead(agent, agent->GetVelocity(), obstructed);

            if (obstructed) {
                FVector clearVec;
                if (FindClearVector(agent, clearVec, 5000)) {
                    agent->SetAvoidanceVector(clearVec);

                    /*DEBUGGING*/
                    //FString safeVectorFoundText = FString::Printf(TEXT("Agent %d found safe vector."), agent->agentID);
                    //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Turquoise, safeVectorFoundText, true);
                    /*DEBUGGING*/
                }
                else {
                    agent->SetStatusStuck();

                    /*DEBUGGING*/
                    FString stuckText = FString::Printf(TEXT("Agent %d stuck."), agent->agentID);
                    GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Red, stuckText, true);
                    /*DEBUGGING*/
                }
            }
        }

        agent->statusAvoiding = true;
    }
    else {
        if (agent->statusAvoiding) {
            agent->statusDirectMove = true;

            FVector goToVec = agent->rawVelocity.GetClampedToSize(0, agent->obstacleAvoidDist);
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
    targetVector = TransformToWorld(agent, targetVector);

    // Create array of raycast start/end points in concentric circles around agent
    TArray<FVector> rayStartPts;
    rayStartPts.Add(agent->GetActorLocation());
    TArray<FVector> rayEndPts;
    rayEndPts.Add(targetVector);

    float degStep = 15;  // decrease to increase fidelity of raycast cylinders. recommend factor of 360
    for (int circle = 5; circle <= agent->bodySize; circle += 5) {
        FVector offset = FVector(0, circle, 0);

        for (float deg = 0; deg < 360; deg += degStep) {
            //offset = velRot.RotateVector(offset);
            FRotator rotRoll = FRotator(0, 0, deg);
            offset = rotRoll.RotateVector(offset);
            
            rayStartPts.Add(agent->GetActorLocation() + offset);
            rayEndPts.Add(targetVector + offset);

            deg += degStep;

            /*DEBUGGING*/
            //if (circle == agent->bodySize) {
            //    DrawDebugLine(GetWorld(), agent->GetActorLocation() + offset, targetVector + offset, FColor::Orange, false, 0.01, 0, 1);
            //}
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
            //DrawDebugPoint(GetWorld(), hitResult.ImpactPoint, 3, FColor::Red, false, 0.01);
            /*DEBUGGING*/
        }
    }

    return safeVectors;
}

/* Check in a sphere using the given vector as a starting point, checking for collision. Returns the first vector that hits no obstacle.
*
*   @param agent The agent to perform the sweep for.
*   @param startingVec The vector to start the sweep from.
*   @param fidelity Number of points to check.
*   @return The first vector that hits no obstacles in a LineTraceSingleByChannel call. Returns null vector if no clear vector found.
*/
bool UAgentObstacleAvoidanceTask::FindClearVector(AUSARAgent* agent, FVector& targetVec, int fidelity) {
    /*DEBUGGING*/
    //FString checkSurroundingsText = FString::Printf(TEXT("Agent %d checking surroundings."), agent->agentID);
    //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, checkSurroundingsText, true);
    /*DEBUGGING*/

    bool foundClearVec = false;

    // Fibonacci sphere
    const float gRatio = (sqrt(5.f) + 1.f) / 2.f;   // golden ratio
    const float gAngle = 180 * (3.f - sqrt(5.f));   // golden angle in degrees

    for (int i = 1; i <= fidelity; i++) {
        float azimuth = FMath::Asin(-1.f + 2.f * float(i) / (fidelity + 1));
        float inclination = gAngle * i;

        float x = FMath::Cos(inclination)* FMath::Cos(-azimuth);
        float y = FMath::Sin(inclination) * FMath::Cos(-azimuth);
        float z = FMath::Sin(-azimuth);

        FVector checkVec = agent->obstacleAvoidDist * FVector(x, y, z) + agent->GetActorLocation();
        FHitResult hitResult;
        FCollisionQueryParams queryParams;
        queryParams.AddIgnoredActor(agent);
        FCollisionResponseParams responseParams;

        if (!GetWorld()->LineTraceSingleByChannel(hitResult, agent->GetActorLocation(), checkVec, ECC_WorldStatic, queryParams, responseParams)) {
            foundClearVec = true;
            targetVec = checkVec - agent->GetActorLocation();

            /*DEBUGGING*/
            //FString safeVectorFoundText = FString::Printf(TEXT("Agent %d found safe vector (%f, %f, %f)."), agent->agentID, targetVec.X, targetVec.Y, targetVec.Z);
            //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, safeVectorFoundText, true);

            //DrawDebugPoint(GetWorld(), checkVec, 10, FColor::Green, false, 0.01);
            /*DEBUGGING*/
            
            break;
        }
        else {
            /*DEBUGGING*/
            //DrawDebugPoint(GetWorld(), checkVec, 5, FColor::Magenta, false, 0.01);
            /*DEBUGGING*/
        }
    }

    return foundClearVec;
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
    //FRotator agentRot = agent->GetActorRotation().GetInverse();
    //FVector transVector = agentRot.RotateVector(vector);

    FVector transVector = vector + agent->GetActorLocation();

    return transVector;
}