#pragma once

#include "USAR_Constants.h"
#include "Engine.h"
#include "LocGridStruct.generated.h"

USTRUCT()
struct PROTOTYPE_API FLocGridStruct
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY()
		int x;
	UPROPERTY()
		int y;

	UPROPERTY()
		float confidence;

	UPROPERTY()
		TArray<FVector> survivors;

	UPROPERTY()
		float lastUpdated;	//time

	FLocGridStruct()
	{
	}

	FLocGridStruct(int xPos, int yPos, float conf, float time) :
		x(xPos),
		y(yPos),
		confidence(conf),
		lastUpdated(time)
	{}

	/* Sorted insert of the grid into an environment map.
	*	@param map Environment map to add the grid to.
	*	@param idx Writes the index of the array the grid is inserted at, or the index at which the grid is found, if it already exists.
	*	@return Returns true if the grid is a new addition to the map, false otherwise.
	*/
	bool InsertInMap(TArray<FLocGridStruct>& map, int& idx)
	{
		bool newGrid = false;

		idx = map.Find(*this);
		if (idx == INDEX_NONE) {
			int i = 0;
			while (i < map.Num()) {
				if (*this < map[i]) {
					break;
				}

				i++;
			}

			map.Insert(*this, i);
			newGrid = true;
		}

		return newGrid;
	}

	FORCEINLINE bool operator==(const FLocGridStruct& loc) const
	{
		if ((x == loc.x) && (y == loc.y)) {
			return true;
		}
		
		return false;
	}

	FORCEINLINE bool operator<(const FLocGridStruct& loc) const
	{
		if (x < loc.x) {
			return true;
		}
		else if (x == loc.x) {
			if (y < loc.y) {
				return true;
			}
		}

		return false;
	}
};