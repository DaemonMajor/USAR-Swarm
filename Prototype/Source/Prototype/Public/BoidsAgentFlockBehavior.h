// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BoidsAgent.h"
#include "BehaviorTree/BTService.h"
#include "BoidsAgentFlockBehavior.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_API UBoidsAgentFlockBehavior : public UBTService
{
	GENERATED_BODY()
	
public:
	UBoidsAgentFlockBehavior();

protected:
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	FVector getAlignment(ABoidsAgent* agent);		// Get average velocity of neighbor agents
	FVector getCohesion(ABoidsAgent* agent);		// Get vector pointing to center of mass of neighbor agents
	FVector getSeparation(ABoidsAgent* agent);		// Calculate vector pointing away from neighbor agents

	FVector calcNewVector(ABoidsAgent* agent, FVector alignFactor, FVector cohFactor, FVector sepFactor);	// calculate new vector for agent based on alignment, cohesion, and separation factors
};
