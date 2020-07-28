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

    for (; gridLoc.X < currLoc.X + VISION_RADIUS; gridLoc.X += GRID_SIZE) {
        for (; gridLoc.Y < currLoc.Y + VISION_RADIUS; gridLoc.Y += GRID_SIZE) {
            float dist = FVector::DistXY(currLoc, gridLoc);
            if (dist <= VISION_RADIUS) {
                FLocGridStruct grid = FLocGridStruct(currLoc.X, currLoc.Y, GetWorld()->GetTimeSeconds());

                int idx;
                bool isNewGrid = grid.InsertInMap(envMap, idx);
                if (!isNewGrid) {
                    envMap[idx].confidence = FMath::Clamp(envMap[idx].confidence + CONF_INCR, 0.f, 1.f);
                }
            }
        }
    }
}

/* Send onboard map data to neighbor agents and update the onboard map to reflect data received from neighbors.
*/
void AUSARAgent::ShareMap()
{

}

/* Accepts incoming map data and adds it to the envMapInBuffer.
*/
void AUSARAgent::TakeMapData(const TArray<FLocGridStruct> sharedMap)
{
    for (FLocGridStruct grid : sharedMap) {
        int idx = envMapInBuffer.Find(grid);

        if (idx == INDEX_NONE) {
            
        }
    }
}