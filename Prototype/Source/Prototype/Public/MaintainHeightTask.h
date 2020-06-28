// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BoidsAgent.h"
#include "MaintainHeightTask.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_API UMaintainHeightTask : public UBTTaskNode
{
	GENERATED_BODY()

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	void MoveToHeight(ABoidsAgent* agent);
};
