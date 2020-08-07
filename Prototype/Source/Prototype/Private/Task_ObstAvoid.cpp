// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

void AUSARAgent::ObstAvoidHandle()
{
    ObstAvoidTask();
    MaintainPersonalSpace(8);
}

void AUSARAgent::MaintainPersonalSpace(int numPoints)
{
    FVector agentLoc = GetActorLocation();
    float phi = (1.f + sqrtf(5.f)) / 2.f;

    for (int i = 0; i < numPoints; i++) {
        float itr   = float(-numPoints + 1 + 2 * i);
        float theta = 2 * PI * itr / phi;
        float sPhi  = itr / numPoints;
        float cPhi  = sqrtf(FMath::Square(numPoints) - FMath::Square(itr)) / numPoints;

        float x = cPhi * sinf(theta);
        float y = cPhi * cosf(theta);
        float z = sPhi;

        FVector checkVec = (BODY_SIZE + SAFETY_DIST) * FVector(x, y, z) + agentLoc;

        FHitResult hitResult;
        FCollisionQueryParams queryParams;
        queryParams.AddIgnoredActor(this);
        FCollisionResponseParams responseParams;

        if (GetWorld()->LineTraceSingleByChannel(hitResult, GetActorLocation(), checkVec, ECC_WorldStatic, queryParams, responseParams)) {
            FVector obstDir = hitResult.ImpactPoint - GetActorLocation();
            avoidanceVector -= obstDir;

            /*DEBUGGING*/
            if (showDebug) {
                DrawDebugPoint(GetWorld(), hitResult.ImpactPoint, 7.5, FColor::Red, false, RATE_AVOID_TASK);
            }
            /*DEBUGGING*/
        }

        /*DEBUGGING*/
        if (showDebug) {
            DrawDebugLine(GetWorld(), GetActorLocation(), checkVec, FColor::Yellow, false, RATE_AVOID_TASK, 3);
            DrawDebugPoint(GetWorld(), checkVec, 5, FColor::Yellow, false, RATE_AVOID_TASK);
        }
        /*DEBUGGING*/
    }
}

void AUSARAgent::ObstAvoidTask()
{
    //if (statusDirectMove) {
    //    if (GetActorLocation().Equals(GetDirectMoveLoc(), 1)) {
    //        statusDirectMove = false;
    //        directMoveLoc = FVector::ZeroVector;
    //    }

    //    return;
    //}

    bool obstructed = false;
    TArray<FVector> safeVectors = LookAhead(rawVelocity, obstructed);

    if (obstructed) {
        if (statusAvoiding) {
            obstructed = false;
            safeVectors = LookAhead(GetVelocity(), obstructed);

            if (obstructed) {
                FVector clearVec;
                if (FindClearVector(clearVec, FIB_SPHERE_FIDELITY)) {
                    avoidanceVector = clearVec;
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
        else {
            FVector clearVec;
            if (FindClearVector(clearVec, FIB_SPHERE_FIDELITY)) {
                avoidanceVector = clearVec;
            }
            else {
                SetStatusStuck();

                /*DEBUGGING*/
                FString stuckText = FString::Printf(TEXT("Agent %d stuck."), agentID);
                GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Red, stuckText, true);
                /*DEBUGGING*/
            }
        }

        statusAvoiding = true;
    }
    else {
        //if (statusAvoiding) {
        //    statusDirectMove = true;

        //    FVector goToVec = rawVelocity.GetClampedToSize(0, OBSTACLE_AVOID_DIST);
        //    directMoveLoc = goToVec + GetActorLocation();
        //}

        statusAvoiding = false;
        avoidanceVector = FVector::ZeroVector;
    }
}

/* Look for obstacles in the given direction. Sets the agent status to avoiding if an obstacle is detected.
*  Returns array of "safe" vectors.
*
*   @return Array of obstacle-free vectors.
*/
TArray<FVector> AUSARAgent::LookAhead(FVector vel, bool& obstructed)
{
    FVector agentLoc = GetActorLocation();

    // Transform agent velocity from local to world coordinates
    FVector targetVector = vel.GetClampedToSize(0, OBSTACLE_AVOID_DIST);
    FRotator velRot = vel.Rotation();
    targetVector = TransformToWorld(targetVector);

    // Create array of raycast start/end points in concentric circles around agent
    TArray<FVector> rayStartPts;
    rayStartPts.Add(agentLoc);
    TArray<FVector> rayEndPts;
    rayEndPts.Add(targetVector);

    float degStep = 45;  // decrease to increase fidelity of raycast cylinders. recommend factor of 360
    for (int circle = BODY_SIZE; circle <= BODY_SIZE; circle += 5) {
        FVector offset = FVector(0, circle, 0);

        for (float deg = 0; deg < 360; deg += degStep) {
            FRotator rotRoll = FRotator(0, 0, deg);
            offset = rotRoll.RotateVector(offset);
            offset = velRot.RotateVector(offset);
            
            rayStartPts.Add(agentLoc + offset);
            rayEndPts.Add(targetVector + offset);

            deg += degStep;

            /*DEBUGGING*/
            if (showDebug) {
                if (circle == BODY_SIZE) {
                    DrawDebugLine(GetWorld(), agentLoc + offset, targetVector + offset, FColor::Orange, false, RATE_AVOID_TASK, 2.5);
                }
            }
            /*DEBUGGING*/
        }
    }

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
bool AUSARAgent::FindClearVector(FVector& targetVec, int fidelity)
{
    bool foundClearVec = false;

    // Fibonacci sphere
    FVector agentLoc = GetActorLocation();
    float phi = (1.f + sqrtf(5.f)) / 2.f;

    for (int i = 0; i < fidelity; i++) {
        float itr = float(-fidelity + 1 + 2 * i);
        float theta = 2 * PI * itr / phi;
        float sPhi = itr / fidelity;
        float cPhi = sqrtf(FMath::Square(fidelity) - FMath::Square(itr)) / fidelity;

        float x = cPhi * sinf(theta);
        float y = cPhi * cosf(theta);
        float z = sPhi;

        FVector tmpVec = agentVelocity.Rotation().RotateVector(FVector(x, y, z));   // remove this once agent turning is in place
        FVector checkVec = OBSTACLE_AVOID_DIST * tmpVec + agentLoc;                 // check vectors closest to agent velocity first

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
            if (showDebug) {
                DrawDebugPoint(GetWorld(), checkVec, 5, FColor::Magenta, false, 0.1);
            }
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