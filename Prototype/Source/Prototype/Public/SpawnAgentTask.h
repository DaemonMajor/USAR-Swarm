// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SwarmSpawnPoint.h"
#include "SpawnAgentTask.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_API USpawnAgentTask : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UFUNCTION()
		FVector GetRandLoc(ASwarmSpawnPoint* spawn);
};