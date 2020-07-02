// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BoidsAgent.h"
#include "AgentObstacleAvoidanceTask.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_API UAgentObstacleAvoidanceTask : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UFUNCTION()
		TArray<FVector> LookAhead(ABoidsAgent* agent);
	UFUNCTION()
		bool CheckVector(ABoidsAgent* agent, FVector vector);
	UFUNCTION()
		FVector FindClearVector(ABoidsAgent* agent, FVector startingVec);

	UFUNCTION()
		FVector TransformToWorld(ABoidsAgent* agent, FVector vector);
};