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
        return static_cast<float>(tmpPt - tmpPt % GRID_SIZE);
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

    float xMax = currLoc.X + VISION_RADIUS;
    float yMax = currLoc.Y + VISION_RADIUS;
    float zMax = currLoc.Z + VISION_RADIUS;

    float gridZ = currLoc.Z - VISION_RADIUS;

    while (gridZ <= zMax) {
        float gridX = currLoc.X - VISION_RADIUS;

        while (gridX <= xMax) {
            float gridY = currLoc.Y - VISION_RADIUS;

            while (gridY <= yMax) {
                FVector gridLoc = FVector(gridX, gridY, gridZ);

                float dist = FVector::Dist(currLoc, gridLoc);

                if (dist <= VISION_RADIUS) {
                    FHitResult hitResult;
                    FCollisionObjectQueryParams objectParams;
                    objectParams.AddObjectTypesToQuery(ECC_WorldStatic);
                    FCollisionQueryParams queryParams;
                    queryParams.AddIgnoredActor(this);

                    if (!GetWorld()->LineTraceSingleByObjectType(hitResult, currLoc, gridLoc, objectParams, queryParams)) {
                        AddGrid(gridLoc, false);
                    }
                    else {
                        FVector hitLoc = hitResult.ImpactPoint;
                        float xHit = SnapToGrid(hitLoc.X);
                        float yHit = SnapToGrid(hitLoc.Y);
                        float zHit = SnapToGrid(hitLoc.Z);
                        FVector hitGrid = FVector(xHit, yHit, zHit);

                        dist = FVector::Dist(GetActorLocation(), hitLoc);
                        AddGrid(hitLoc, true);

                        /*DEBUGGING*/
                        //if (showDebug) {
                        //    DrawDebugPoint(GetWorld(), hitGrid, 5, FColor::Orange, false, RATE_MAP_UPDATE);
                        //}
                        /*DEBUGGING*/
                    }
                }

                gridY += GRID_SIZE;
            }

            gridX += GRID_SIZE;
        }

        gridZ += GRID_SIZE;
    }

    DetectionTask();
}

/* Adds grid holding location gridLoc into map. Increments confidence value if grid already exists.
*
*   @param gridLoc Location to add to map.
*   @param dist Distance between agent and location to add.
*   @return The map index the grid was added to or found at.
*/
FGridStruct* AUSARAgent::AddGrid(FVector loc, bool occupied)
{
    float x = SnapToGrid(loc.X);
    float y = SnapToGrid(loc.Y);
    float z = SnapToGrid(loc.Z);
    float conf = CONF_INCR * FVector::Dist(GetActorLocation(), loc) / VISION_RADIUS;

    FGridStruct gridToAdd = FGridStruct(x, y, z, conf, GetWorld()->GetTimeSeconds());
    gridToAdd.occupied = occupied;

    bool isNewGrid;
    FGridStruct* grid = gridToAdd.InsertInMap(envMap, isNewGrid);
    if (!isNewGrid) {
        grid->Combine(gridToAdd);
    }
    else {
        gridsExplored = envMap.Num();
    }

    /*DEBUGGING*/
    //if (showDebug) {
    //    FVector dbgPt = FVector(grid->x, grid->y, grid->z);
    //    float ptSize = 3.5;
    //    FColor c = FColor::Green;

    //    if (occupied) {
    //        ptSize = 7;
    //        c = FColor::Orange;
    //    }

    //    DrawDebugPoint(GetWorld(), dbgPt, ptSize, c, false, RATE_MAP_UPDATE);
    //}
    /*DEBUGGING*/

    return grid;
}

/* Dumps map data.
*
*   @return Agent's current map representation.
*/
TSet<FGridStruct> AUSARAgent::UploadMap()
{
    return envMap;
}


/* Send onboard map data to neighbor agents.
*/
void AUSARAgent::ShareMap()
{
    TArray<FGridStruct> map;

    for (AUSARAgent* n : neighborAgents) {
        if(alreadyShared.Find(n->agentID) != INDEX_NONE) {
            n->TakeMapData(map);
            
            alreadyShared.Add(n->agentID);
        }
    }
}

/* Merges given map data with onboard map.
*/
void AUSARAgent::TakeMapData(const TArray<FGridStruct> sharedMap)
{
    for (FGridStruct sharedGrid : sharedMap) {
        bool isNewGrid;
        FGridStruct* grid = sharedGrid.InsertInMap(envMap, isNewGrid);

        if (!isNewGrid) {
            grid->Combine(sharedGrid);
        }
    }
}