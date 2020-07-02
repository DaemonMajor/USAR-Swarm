// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "USARAgentController.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_API AUSARAgentController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	AUSARAgentController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBehaviorTree* USARAgentBT;
};
