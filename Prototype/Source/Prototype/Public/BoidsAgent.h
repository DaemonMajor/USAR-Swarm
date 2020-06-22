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
		FVector agentVelocity = FVector::ZeroVector;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector alignVector;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector flockCenter;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector sepVector;
	/* =============== */

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
		TArray<ABoidsAgent*> getNeighbors();
	
	UFUNCTION()
		void setVelocity(FVector newVel);	// set new velocity
	
	/*
	UFUNCTION()
		FVector getTarget();				// get target location
	UFUNCTION()
		void setTarget(FVector newTarget);	// set target location
	*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
		
	UPROPERTY()
		float pitchRate = 0;
	UPROPERTY()
		float yawRate = 0;
	UPROPERTY()
		float rollRate = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int flockID;

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

	UFUNCTION()
		void onNeighborEnter(UPrimitiveComponent* agentSensor, AActor* neighbor, UPrimitiveComponent* neighborBody, int32 neighborIndex, 
							 bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
		void onNeighborLeave(UPrimitiveComponent* agentSensor, AActor* neighbor, UPrimitiveComponent* neighborBody, int32 neighborIndex);

	UFUNCTION()
		void moveAgent(float deltaSec);
};