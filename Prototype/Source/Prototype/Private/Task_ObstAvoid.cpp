// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

void AUSARAgent::ObstAvoidHandle()
{
    if (!statusStuck) {     // add cases here if obstacle avoidance should be turned off
        ObstAvoidTask();
    }
}

void AUSARAgent::ObstAvoidTask()
{
    if (statusDirectMove) {
        if (GetActorLocation().Equals(GetDirectMoveLoc(), 1)) {
            statusDirectMove = false;
            SetDirectMoveLoc(FVector::ZeroVector);
        }

        return;
    }

    bool obstructed = false;
    TArray<FVector> safeVectors = LookAhead(rawVelocity, obstructed);

    if (obstructed) {
        /*DEBUGGING*/
        //FString obstructedText = FString::Printf(TEXT("Agent %d detected obstruction."), agentID);
        //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Orange, obstructedText, true);
        /*DEBUGGING*/

        if (!statusAvoiding) {
            FVector clearVec;
            if (FindClearVector(clearVec, 5000)) {
                SetAvoidanceVector(clearVec);
            }
            else {
                SetStatusStuck();

                /*DEBUGGING*/
                FString stuckText = FString::Printf(TEXT("Agent %d stuck."), agentID);
                GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Red, stuckText, true);
                /*DEBUGGING*/
            }
        }
        else {
            obstructed = false;
            safeVectors = LookAhead(GetVelocity(), obstructed);

            if (obstructed) {
                FVector clearVec;
                if (FindClearVector(clearVec, 5000)) {
                    SetAvoidanceVector(clearVec);

                    /*DEBUGGING*/
                    //FString safeVectorFoundText = FString::Printf(TEXT("Agent %d found safe vector."), agentID);
                    //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Turquoise, safeVectorFoundText, true);
                    /*DEBUGGING*/
                }
                else {
                    SetStatusStuck();

                    /*DEBUGGING*/
                    FString stuckText = FString::Printf(TEXT("Agent %d stuck."), agentID);
                    GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Red, stuckText, true);
                    /*DEBUGGING*/
                }
            }
        }

        statusAvoiding = true;
    }
    else {
        if (statusAvoiding) {
            statusDirectMove = true;

            FVector goToVec = rawVelocity.GetClampedToSize(0, OBSTACLE_AVOID_DIST);
            SetDirectMoveLoc(goToVec + GetActorLocation());
        }

        statusAvoiding = false;
        SetAvoidanceVector(FVector::ZeroVector);
    }
}

/* Raycast in a cylinder in the direction of the agent's velocity to look for obstacles. Sets the agent status to avoiding if obstacle is detected.
*  Returns array of "safe" vectors.
*
*   @return Array of obstacle-free vectors.
*/
TArray<FVector> AUSARAgent::LookAhead(FVector vel, bool& obstructed)
{
    // Transform agent velocity from local to world coordinates
    FVector targetVector = vel;
    FRotator velRot = UKismetMathLibrary::FindLookAtRotation(FVector::ZeroVector, targetVector);
    targetVector = TransformToWorld(targetVector);

    // Create array of raycast start/end points in concentric circles around agent
    TArray<FVector> rayStartPts;
    rayStartPts.Add(GetActorLocation());
    TArray<FVector> rayEndPts;
    rayEndPts.Add(targetVector);

    //float degStep = 15;  // decrease to increase fidelity of raycast cylinders. recommend factor of 360
    //for (int circle = 5; circle <= agent->BODY_SIZE; circle += 5) {
    //    FVector offset = FVector(0, circle, 0);

    //    for (float deg = 0; deg < 360; deg += degStep) {
    //        //offset = velRot.RotateVector(offset);
    //        FRotator rotRoll = FRotator(0, 0, deg);
    //        offset = rotRoll.RotateVector(offset);
    //        
    //        rayStartPts.Add(agent->GetActorLocation() + offset);
    //        rayEndPts.Add(targetVector + offset);

    //        deg += degStep;

    //        /*DEBUGGING*/
    //        if (agent->showDebug) {
    //            if (circle == agent->BODY_SIZE) {
    //                DrawDebugLine(GetWorld(), agent->GetActorLocation() + offset, targetVector + offset, FColor::Orange, false, 0.01, 0, 1);
    //            }
    //        }
    //        /*DEBUGGING*/
    //    }
    //}

    FHitResult hitResult;
    FCollisionObjectQueryParams objectParams;
    objectParams.AddObjectTypesToQuery(ECC_WorldStatic);
    FCollisionQueryParams queryParams;
    queryParams.AddIgnoredActor(this);
    
    TArray<FVector> safeVectors;

    // collect vectors with no obstacles.
    for (int i = 0; i < rayStartPts.Num(); i++) {
        if(!GetWorld()->LineTraceSingleByObjectType(hitResult, rayStartPts[i], rayEndPts[i], objectParams, queryParams)) {
            safeVectors.Add(rayEndPts[i]);
        }
        else {
            obstructed = true;
            
            /*DEBUGGING*/
            if (showDebug) {
                DrawDebugPoint(GetWorld(), hitResult.ImpactPoint, 3, FColor::Red, false, 0.01);
            }
            /*DEBUGGING*/
        }
    }

    return safeVectors;
}

/* Check in a sphere using the given vector as a starting point, checking for collision. Returns the first vector that hits no obstacle.
*
*   @param startingVec The vector to start the sweep from.
*   @param fidelity Number of points to check.
*   @return The first vector that hits no obstacles in a LineTraceSingleByChannel call. Returns null vector if no clear vector found.
*/
bool AUSARAgent::FindClearVector(FVector& targetVec, int fidelity) {
    /*DEBUGGING*/
    //FString checkSurroundingsText = FString::Printf(TEXT("Agent %d checking surroundings."), agentID);
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

        FVector checkVec = OBSTACLE_AVOID_DIST * FVector(x, y, z) + GetActorLocation();
        FHitResult hitResult;
        FCollisionQueryParams queryParams;
        queryParams.AddIgnoredActor(this);
        FCollisionResponseParams responseParams;

        if (!GetWorld()->LineTraceSingleByChannel(hitResult, GetActorLocation(), checkVec, ECC_WorldStatic, queryParams, responseParams)) {
            foundClearVec = true;
            targetVec = checkVec - GetActorLocation();

            /*DEBUGGING*/
            if (showDebug) {
                //FString safeVectorFoundText = FString::Printf(TEXT("Agent %d found safe vector (%f, %f, %f)."), agentID, targetVec.X, targetVec.Y, targetVec.Z);
                //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, safeVectorFoundText, true);

                DrawDebugPoint(GetWorld(), checkVec, 10, FColor::Green, false, 0.01);
            }
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
*   @param vector The vector to check.
*   @return True if area around vector found clear.
*/
bool AUSARAgent::CheckVector(FVector vector)
{
    float degStep = 6;  // increase to increase fidelity of raycast cylinders
    for (int circle = 1; circle < BODY_SIZE; circle++) {
        FVector endPt = FVector(circle, 0, 0);

        for (int deg = 0; deg < 360; deg += degStep) {
            FRotator rot = FRotator(0, 0, deg);
            endPt = rot.RotateVector(endPt);
            endPt = vector.Rotation().RotateVector(endPt);
            endPt = vector + TransformToWorld(endPt);

            FHitResult hitResult;
            FCollisionQueryParams queryParams;
            queryParams.AddIgnoredActor(this);
            FCollisionResponseParams responseParams;
            if (GetWorld()->LineTraceSingleByChannel(hitResult, GetActorLocation(), endPt, ECC_WorldStatic, queryParams, responseParams)) {
                return false;
            }
        }
    }

    return true;
}

FVector AUSARAgent::TransformToWorld(FVector vector)
{
    //FRotator agentRot = agent->GetActorRotation().GetInverse();
    //FVector transVector = agentRot.RotateVector(vector);

    FVector transVector = vector + GetActorLocation();

    return transVector;
}