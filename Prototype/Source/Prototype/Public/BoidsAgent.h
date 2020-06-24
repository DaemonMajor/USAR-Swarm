// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SphereComponent.h"
#include "BoidsAgent.generated.h"

UCLASS()
class PROTOTYPE_API ABoidsAgent : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABoidsAgent();

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


	/* FOR DEBUGGING ONLY */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float speed = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float alignmentFactor = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float cohesionFactor = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float separationFactor = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int numNeighbors = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector agentVelocity;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector alignVector;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector flockCenter;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector sepVector;
	/* =============== */

	/*MOVE TO PROTECTED AFTER DEBUGGING*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int agentID;	// switch to const after debugging
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int flockID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxTurnRate;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float bodySize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float neighborRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float visionRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float alignmentWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float cohesionWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float separationWeight;
	
	const float agentSpacing = 300;	// how far apart agents should be spaced

	UFUNCTION()
		int GetID();
	UFUNCTION()
		void SetID(int id);
	UFUNCTION()
		TArray<ABoidsAgent*> GetNeighbors();
	
	UFUNCTION()
		void SetVelocity(FVector newVel);			// set new velocity
	virtual FVector GetVelocity() const override;	// get agent velocity (bypasses built-in component velocity because documentation is unclear)

	/* for future implementation
	UFUNCTION()
		FVector getTarget();				// get target location
	UFUNCTION()
		void setTarget(FVector newTarget);	// set target location
	*/

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
		
	UPROPERTY()
		float pitchRate = 0;
	UPROPERTY()
		float yawRate = 0;
	UPROPERTY()
		float rollRate = 0;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		class UStaticMeshComponent* agentMesh;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		class UFloatingPawnMovement* moveComp;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		class USphereComponent* agentBody;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		class USphereComponent* neighborSphere;
	UPROPERTY()
        TArray<ABoidsAgent*> neighborAgents = TArray<ABoidsAgent*>();
	UPROPERTY()
		FVector target;

	UPROPERTY()
		float bootUpDelay = 0.5;
	UPROPERTY()
		FTimerHandle bootUpDelayTimer;		// start neighbor scans after this delay (after all agents have been placed in world)

	UFUNCTION()
		void ScanNeighbors();	// populate neighborAgents (used at BeginPlay)
	UFUNCTION()
		void BootUpSequence();
	UFUNCTION()
		void OnNeighborEnter(UPrimitiveComponent* agentSensor, AActor* neighbor, UPrimitiveComponent* neighborBody, int32 neighborIndex, 
							 bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
		void OnNeighborLeave(UPrimitiveComponent* agentSensor, AActor* neighbor, UPrimitiveComponent* neighborBody, int32 neighborIndex);

	UFUNCTION()
		void MoveAgent(float deltaSec);
};