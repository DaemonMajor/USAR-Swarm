#include "USARAgent.h"
#include "Misc/CoreMiscDefines.h"
#include "Math/UnrealMathUtility.h"

/* Update the agent's onboard map from sensor data.
*/
void AUSARAgent::UpdateMap()
{
    FVector currLoc = GetActorLocation();

    FVector gridLoc = currLoc;
    gridLoc.X -= VISION_RADIUS;
    gridLoc.Y -= VISION_RADIUS;
    //for (; gridLoc.X < currLoc.X + VISION_RADIUS; gridLoc.X += GRID_SIZE) {
    while(gridLoc.X < currLoc.X + VISION_RADIUS) {
        //for (; gridLoc.Y < currLoc.Y + VISION_RADIUS; gridLoc.Y += GRID_SIZE) {
        while(gridLoc.Y < currLoc.Y + VISION_RADIUS) {
            float dist = FVector::DistXY(currLoc, gridLoc);

            /*DEBUGGING*/
            if (showDebug) {
                DrawDebugPoint(GetWorld(), gridLoc, 10, FColor::Blue, false, 1);

                FString locText = FString::Printf(TEXT("Loc: [%f, %f],   Grid: [%f, %f]"), currLoc.X, currLoc.Y, gridLoc.X, gridLoc.Y);
                GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.5f, FColor::Green, locText, true);

                FString mapDistText = FString::Printf(TEXT("Dist to grid = %f."), dist);
                GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.5f, FColor::Green, mapDistText, true);
            }
            /*DEBUGGING*/

            if (dist <= VISION_RADIUS) {
                float conf = CONF_INCR * dist / VISION_RADIUS;

                FLocGridStruct grid = FLocGridStruct(currLoc.X, currLoc.Y, conf, GetWorld()->GetTimeSeconds());

                int idx;
                bool isNewGrid = grid.InsertInMap(envMap, idx);
                if (!isNewGrid) {
                    envMap[idx].confidence = FMath::Clamp(envMap[idx].confidence + conf, 0.f, 1.f);
                }
                else {
                    gridsExplored = envMap.Num();
                }
            }

            gridLoc.Y += GRID_SIZE;
        }

        gridLoc.X += GRID_SIZE;
    }
}

/* Dumps map data.
*
*   @return Agent's current map representation.
*/
TArray<FLocGridStruct> AUSARAgent::UploadMap()
{
    return envMap;
}


/* Send onboard map data to neighbor agents.
*/
void AUSARAgent::ShareMap()
{
    float currTime = GetWorld()->GetTimeSeconds();
    TArray<FLocGridStruct> map;

    // only share recently updated grids
    for (FLocGridStruct grid : envMap) {
        if (currTime - grid.lastUpdated < RATE_MAP_SHARE) {
            map.AddUnique(grid);
        }
    }

    for (AUSARAgent* n : neighborAgents) {
        n->TakeMapData(map);
    }
}

/* Merges given map data with onboard map.
*/
void AUSARAgent::TakeMapData(const TArray<FLocGridStruct> sharedMap)
{
    for (FLocGridStruct grid : sharedMap) {
        int idx;
        bool isNewGrid = grid.InsertInMap(envMap, idx);
        if (!isNewGrid) {
            envMap[idx].confidence = FMath::Clamp(envMap[idx].confidence + grid.confidence, 0.f, 1.f);
        }
    }
}