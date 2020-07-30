#include "USARAgent.h"
#include "Misc/CoreMiscDefines.h"
#include "Math/UnrealMathUtility.h"

/* Update the agent's onboard map from sensor data.
*/
void AUSARAgent::UpdateMap()
{
    FVector currLoc = GetActorLocation();

    FVector gridLoc;
    gridLoc.Z = currLoc.Z + VISION_RADIUS;

    while (gridLoc.Z >= 0) {
        gridLoc.X = currLoc.X - VISION_RADIUS;

        while (gridLoc.X < currLoc.X + VISION_RADIUS) {
            gridLoc.Y = currLoc.Y - VISION_RADIUS;

            while (gridLoc.Y < currLoc.Y + VISION_RADIUS) {
                float dist = FVector::Dist(currLoc, gridLoc);

                if (dist <= VISION_RADIUS) {
                    FHitResult hitResult;
                    FCollisionObjectQueryParams objectParams;
                    objectParams.AddObjectTypesToQuery(ECC_WorldStatic);
                    FCollisionQueryParams queryParams;
                    queryParams.AddIgnoredActor(this);

                    if (!GetWorld()->LineTraceSingleByObjectType(hitResult, currLoc, gridLoc, objectParams, queryParams)) {
                        AddGrid(gridLoc, dist);
                    }
                    else if (dist == hitResult.Distance) {
                        int grid = AddGrid(gridLoc, dist);
                        envMap[grid].occupied = true;
                    }
                }

                gridLoc.Y += GRID_SIZE;
            }

            gridLoc.X += GRID_SIZE;
        }

        gridLoc.Z -= GRID_SIZE;
    }
}

/* Adds grid holding location gridLoc into map. Increments confidence value if grid already exists.
*
*   @param gridLoc Location to add to map.
*   @param dist Distance between agent and location to add.
*/
int AUSARAgent::AddGrid(FVector gridLoc, float dist)
{
    int x = (int)gridLoc.X - (int)gridLoc.X % GRID_SIZE;
    int y = (int)gridLoc.Y - (int)gridLoc.Y % GRID_SIZE;
    int z = (int)gridLoc.Z - (int)gridLoc.Z % GRID_SIZE;
    float conf = CONF_INCR * dist / VISION_RADIUS;

    FLocGridStruct grid = FLocGridStruct(x, y, z, conf, GetWorld()->GetTimeSeconds());

    /*DEBUGGING*/
    if (showDebug) {
        FVector dbgPt = FVector(grid.x, grid.y, grid.z);
        DrawDebugPoint(GetWorld(), dbgPt, 10, FColor::Blue, false, RATE_MAP_UPDATE);
    }
    /*DEBUGGING*/

    int idx;
    bool isNewGrid = grid.InsertInMap(envMap, idx);
    if (!isNewGrid) {
        envMap[idx].confidence = FMath::Clamp(envMap[idx].confidence + conf, 0.f, 1.f);
    }
    else {
        gridsExplored = envMap.Num();
    }

    return idx;
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