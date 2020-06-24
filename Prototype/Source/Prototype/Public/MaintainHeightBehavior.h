// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BoidsAgent.h"
#include "MaintainHeightBehavior.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_API UMaintainHeightBehavior : public UBTService
{
	GENERATED_BODY()

public:
	UMaintainHeightBehavior();

protected:
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	void MoveToHeight(ABoidsAgent* agent);
};