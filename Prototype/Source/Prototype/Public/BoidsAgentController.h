// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BoidsAgentController.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_API ABoidsAgentController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	ABoidsAgentController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBehaviorTree* boidsAgentBT;
};
