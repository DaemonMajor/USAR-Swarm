// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/SphereComponent.h"
#include "SwarmWP.h"
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool isInitialized = false;

	/* FOR DEBUGGING ONLY */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float speed = 0;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//	float alignmentFactor = 0;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//	float cohesionFactor = 0;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//	float separationFactor = 0;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//	int numNeighbors = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector agentVelocity;	// velocity in local coordinates
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector avoidanceVector;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector heightVector;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector flockVector;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector waypointVector;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//	FVector alignVector;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//	FVector flockCenter;
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	//	FVector sepVector;
	/* =============== */

	/*MOVE TO PROTECTED AFTER DEBUGGING*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int agentID;	// switch to const after debugging
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int flockID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool statusClimbing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float maxSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float bodySize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float neighborRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float visionRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float targetHeight;	// height to maintain
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float heightVariance;	// variance allowed between agent height and target height

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
		void AssignToFlock(int flock);

	UFUNCTION()
		TArray<ABoidsAgent*> GetNeighbors();
	
	UFUNCTION()
		void SetTargetHeight(float height);
	UFUNCTION()
		void SetHeightVariance(float var);
	
	UFUNCTION()
		void SetAvoidanceVector(FVector rawVector);
	UFUNCTION()
		void SetHeightVector(FVector rawVector);
	UFUNCTION()
		void SetFlockVector(FVector rawVector);
	UFUNCTION()
		void SetWaypointVector(FVector rawVector);
	UFUNCTION()
		void SetVelocity();			// set new velocity based on component vectors (avoidanceVector, flockVector, waypointVector)
	virtual FVector GetVelocity() const override;	// get agent velocity in local coordinates (bypasses built-in component velocity because documentation is unclear)

	UFUNCTION()
		void AddWaypoint(ASwarmWP* wp);		// append waypoint to list of target waypoints
	UFUNCTION()
		void RemoveWaypoint(ASwarmWP* wp);	// remove waypoint from list of target waypoints
	UFUNCTION()
		ASwarmWP* GetCurrWaypoint();		// fetch current waypoint

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
		
	UPROPERTY()
		float yawRate;		// rate at which agent can turn in degrees per second
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UStaticMeshComponent* agentRoot;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UStaticMeshComponent* agentBody;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		UFloatingPawnMovement* moveComp;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		USphereComponent* neighborSphere;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		USphereComponent* visionSphere;

	UPROPERTY()
        TArray<ABoidsAgent*> neighborAgents = TArray<ABoidsAgent*>();
	UPROPERTY()
		TArray<ASwarmWP*> waypoints = TArray<ASwarmWP*>();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector wpLoc;

	UPROPERTY()
		float bootUpDelay = 0.5;
	UPROPERTY()
		FTimerHandle bootUpDelayTimer;		// Start neighbor scans after this delay (after all agents have been placed in world).

	UFUNCTION()
		void ScanNeighbors();	// Populate neighborAgents (used at BeginPlay).
	UFUNCTION()
		void BootUpSequence();
	UFUNCTION()
		void OnNeighborEnter(UPrimitiveComponent* agentSensor, AActor* neighbor, UPrimitiveComponent* neighborBody, int32 neighborIndex, 
							 bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
		void OnNeighborLeave(UPrimitiveComponent* agentSensor, AActor* neighbor, UPrimitiveComponent* neighborBody, int32 neighborIndex);

	UFUNCTION()
		void MoveAgent(float deltaSec);
	UFUNCTION()
		FRotator FaceDirection(FVector dir, float deltaSec);	// Rotate agent on z-axis to face specified direction.
};