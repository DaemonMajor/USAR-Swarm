#include "USARAgent.h"
#include "Misc/CoreMiscDefines.h"
#include "Math/UnrealMathUtility.h"


/* Utility function to help translate coordinate to a grid.
*
*   @param pt Number to Snap.
*   @return Number Snaped to the nearest GRID_SIZE
*/
float SnapToGrid(float pt) {
    int tmpPt = static_cast<int>(pt);

    if (pt > 0) {
        return static_cast<float>(tmpPt - abs(tmpPt) % GRID_SIZE);
    }
    else if (pt < 0) {
        return static_cast<float>(tmpPt - (GRID_SIZE - abs(tmpPt) % GRID_SIZE));
    }
    else {
        return 0;
    }
}

/* Update the agent's onboard map from sensor data.
*/
void AUSARAgent::UpdateMap()
{
    FVector currLoc = GetActorLocation();

    FVector gridLoc;
    gridLoc.Z = currLoc.Z - VISION_RADIUS;

    int numGrids = 0;
    while (gridLoc.Z < currLoc.Z + VISION_RADIUS) {
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
                        AddGrid(gridLoc, dist, false);
                    }
                    else {
                        float xGrid = SnapToGrid(gridLoc.X);
                        float yGrid = SnapToGrid(gridLoc.Y);
                        float zGrid = SnapToGrid(gridLoc.Z);
                        FVector grid = FVector(xGrid, yGrid, zGrid);

                        float xHit = SnapToGrid(hitResult.ImpactPoint.X);
                        float yHit = SnapToGrid(hitResult.ImpactPoint.Y);
                        float zHit = SnapToGrid(hitResult.ImpactPoint.Z);
                        FVector hitGrid = FVector(xHit, yHit, zHit);

                        dist = FVector::Dist(GetActorLocation(), hitResult.ImpactPoint);
                        AddGrid(hitResult.ImpactPoint, dist, true);

                        /*DEBUGGING*/
                        if (showDebug) {
                            DrawDebugPoint(GetWorld(), hitResult.ImpactPoint, 5, FColor::Red, false, RATE_MAP_UPDATE);
                            DrawDebugLine(GetWorld(), hitResult.ImpactPoint, hitGrid, FColor::Orange, false, RATE_MAP_UPDATE, 3.5);
                        }
                        /*DEBUGGING*/
                    }

                    numGrids++;
                }

                gridLoc.Y += GRID_SIZE;
            }

            gridLoc.X += GRID_SIZE;
        }

        gridLoc.Z += GRID_SIZE;
    }
}

/* Adds grid holding location gridLoc into map. Increments confidence value if grid already exists.
*
*   @param gridLoc Location to add to map.
*   @param dist Distance between agent and location to add.
*   @return The map index the grid was added to or found at.
*/
int AUSARAgent::AddGrid(FVector gridLoc, float dist, bool occupied)
{
    float x = SnapToGrid(gridLoc.X);
    float y = SnapToGrid(gridLoc.Y);
    float z = SnapToGrid(gridLoc.Z);
    float conf = CONF_INCR * dist / VISION_RADIUS;

    FLocGridStruct grid = FLocGridStruct(x, y, z, conf, GetWorld()->GetTimeSeconds());
    grid.occupied = occupied;

    /*DEBUGGING*/
    if (showDebug) {
        FVector dbgPt = FVector(grid.x, grid.y, grid.z);
        float ptSize = 3.5;
        FColor c = FColor::Green;
        
        if (occupied) {
            ptSize = 7;
            c = FColor::Orange;
        }

        DrawDebugPoint(GetWorld(), dbgPt, ptSize, c, false, RATE_MAP_UPDATE);
    }
    /*DEBUGGING*/

    int idx;
    bool isNewGrid = grid.InsertInMap(envMap, idx);
    if (!isNewGrid) {
        envMap[idx].confidence = FMath::Clamp(envMap[idx].confidence + conf, 0.f, 1.f);

        if (occupied) {
            envMap[idx].occupied = true;
        }
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