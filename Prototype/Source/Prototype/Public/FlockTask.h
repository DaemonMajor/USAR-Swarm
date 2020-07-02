// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "USARAgent.h"
#include "FlockTask.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_API UFlockTask : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	FVector GetAlignment(AUSARAgent* agent);		// Get average velocity of neighbor agents
	FVector GetCohesion(AUSARAgent* agent);		// Get vector pointing to center of mass of neighbor agents
	FVector GetSeparation(AUSARAgent* agent);		// Calculate vector pointing away from neighbor agents

	FVector CalcNewVector(AUSARAgent* agent, FVector alignFactor, FVector cohFactor, FVector sepFactor);	// calculate new vector for agent based on alignment, cohesion, and separation factors
};