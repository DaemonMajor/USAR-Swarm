#pragma once

#include "USAR_Constants.h"
#include "LocGridStruct.h"
#include "Engine.h"
#include "LocGridStruct.generated.h"


USTRUCT()
struct PROTOTYPE_API FMapLayerStruct
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY()
		int zVal;
	UPROPERTY()
		TArray<FLocGridStruct> grids;

	MapLayerStruct* nextLayerDown;
	MapLayerStruct* nextLayerUp;

	FORCEINLINE bool operator==(const FMapLayerStruct& layer) const
	{
		return zVal == layer.zVal;
	}

	FORCEINLINE bool operator<(const FMapLayerStruct layer) const
	{
		return zVal < layer.zVal;
	}
};