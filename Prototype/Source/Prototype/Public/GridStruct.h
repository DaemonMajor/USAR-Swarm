#pragma once

#include "USAR_Constants.h"
#include "Engine.h"
#include "GridStruct.generated.h"


USTRUCT()
struct PROTOTYPE_API FGridStruct
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
	

	FGridStruct()
	{
	}

	FGridStruct(int xPos, int yPos, int zPos, float conf, float time) :
		x(xPos),
		y(yPos),
		z(zPos),
		confidence(conf),
		occupied(false),
		lastUpdated(time)
	{}

	/* Find the grid in a given map.
	*
	*	@param map Environment map to search in.
	*	@return Index at which the grid was found. Returns -1 if not found.
	*/
	int FindInMap(TSet<FGridStruct>& map)
	{
		int idx = -1;

		while (true) {

		}
	}

	/* Inserts the grid into the passed environment map.
	*	@param map Environment map to add the grid to.
	*	@param bNewGrid Set by the function to true if the grid did not already exist in the map.
	*	@return Returns a pointer to the grid in the map.
	*/
	FGridStruct* InsertInMap(TSet<FGridStruct>& map, bool& bNewGrid)
	{
		bNewGrid = false;

		FGridStruct* grid = map.Find(*this);
		if (grid == nullptr) {
			FSetElementId idx = map.Add(*this);

			grid = &map[idx];
			bNewGrid = true;
		}

		return grid;
	}

	/* Combine grid data.
	*
	*	@param grid Grid to combine with.
	*/
	void Combine(FGridStruct grid) {
		confidence = FMath::Clamp(confidence + grid.confidence, 0.f, 1.f);

		if (grid.occupied) {
			occupied = true;
		}

		for (FVector vicLoc : grid.survivors) {
			survivors.AddUnique(vicLoc);
		}
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
		FString occString	= (occupied ? "occupied" : "empty");

		return xString + sep + yString + sep + zString + sep + confString + sep + occString;
	}

	FORCEINLINE bool operator==(const FGridStruct& grid) const
	{
		if ((x == grid.x) && (y == grid.y) && (z == grid.z)) {
			return true;
		}
		
		return false;
	}

	FORCEINLINE bool operator<(const FGridStruct& grid) const
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

FORCEINLINE uint32 GetTypeHash(const FGridStruct& grid)
{
	return GetTypeHash(FVector(grid.x, grid.y, grid.z));
}