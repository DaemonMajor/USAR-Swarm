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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int wpID = -1;		// Unique waypoint ID. Value of -1 sets waypoint as inactive.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int flockID = -1;		// Flock assigned to this waypoint.

	UFUNCTION()
		void Init();

	UFUNCTION()
		int GetID();
	UFUNCTION()
		void SetID(int id);
	UFUNCTION()
		void SetFlock(int flock);

	UFUNCTION()
		void Deactivate();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UStaticMeshComponent* wpRoot;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UStaticMeshComponent* wpArea;

	UFUNCTION()
		void OnAgentEnter(UPrimitiveComponent* wpAreaComp, AActor* agent, UPrimitiveComponent* agentBody, int32 agentIndex,
						  bool bFromSweep, const FHitResult& SweepResult);
};