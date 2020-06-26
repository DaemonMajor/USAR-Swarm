// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwarmWP.generated.h"

UCLASS()
class PROTOTYPE_API ASwarmWP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwarmWP();

	UFUNCTION()
		int GetID();
	UFUNCTION()
		void SetID(int id);

	UFUNCTION()
		void Deactivate();

	/*FOR DEBUGGING ONLY*/
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		int wpID = -1;		// Unique waypoint ID. Value of -1 sets waypoint as inactive.
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		TArray<int> flocks;		// Flock IDs affected by this waypoint.
	/*FOR DEBUGGING ONLY*/

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY()
		UStaticMeshComponent* wpRoot;
	UPROPERTY()
		UStaticMeshComponent* wpArea;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		float wpRadius;

	UFUNCTION()
		void OnAgentEnter(UPrimitiveComponent* wpAreaComp, AActor* agent, UPrimitiveComponent* agentBody, int32 agentIndex,
			bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnAgentLeave(UPrimitiveComponent* wpAreaComp, AActor* agent, UPrimitiveComponent* agentBody, int32 agentIndex);
};