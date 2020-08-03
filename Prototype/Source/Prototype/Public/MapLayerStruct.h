#pragma once

#include "USAR_Constants.h"
#include "GridStruct.h"
#include "Engine.h"
#include "MapLayerStruct.generated.h"


USTRUCT()
struct PROTOTYPE_API FMapLayerStruct
{
	GENERATED_USTRUCT_BODY()

public:
	TArray<FGridStruct> grids;

	TArray<FGridStruct*> zLayers;

	/* Retrieves the index of the given grid if it exists in the map.
	*
	*	@param grid Grid to search for.
	*	@return Index of the grid. Returns -1 if grid does not exist in the map.
	*/
	int Find(FGridStruct grid) {
		int idx = -1;

		for (FGridStruct* z : zLayers) {
			//while(grid.z == z.z) {
			//}
		}

		return idx;
	}
};