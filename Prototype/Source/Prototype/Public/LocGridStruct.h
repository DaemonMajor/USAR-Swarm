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
		int z;

	UPROPERTY()
		float confidence;
	UPROPERTY()
		bool occupied;

	UPROPERTY()
		TArray<FVector> survivors;

	UPROPERTY()
		float lastUpdated;	//time

	FLocGridStruct()
	{
	}

	FLocGridStruct(int xPos, int yPos, int zPos, float conf, float time) :
		x(xPos),
		y(yPos),
		z(zPos),
		confidence(conf),
		occupied(false),
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
			idx = i;
			newGrid = true;
		}

		return newGrid;
	}

	/* Compiles the grid data to a string for saving to a .csv file. Does not include survivor data.
	*/
	FString ToString()
	{
		FString sep			= FString(TEXT(", "));
		FString xString		= FString::FromInt(x);
		FString yString		= FString::FromInt(y);
		FString zString		= FString::FromInt(z);
		FString confString	= FString::SanitizeFloat(confidence);

		return xString + sep + yString + sep + zString + sep + confString;
	}

	FORCEINLINE bool operator==(const FLocGridStruct& grid) const
	{
		if ((x == grid.x) && (y == grid.y) && (z == grid.z)) {
			return true;
		}
		
		return false;
	}

	FORCEINLINE bool operator<(const FLocGridStruct& grid) const
	{
		if (z < grid.z) {
			return true;
		}
		else if (z == grid.z) {
			if (x < grid.x) {
				return true;
			}
			else if (x == grid.x) {
				if (y < grid.y) {
					return true;
				}
			}
		}

		return false;
	}
};