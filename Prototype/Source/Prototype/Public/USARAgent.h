// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/SphereComponent.h"
#include "USAR_Constants.h"
#include "SwarmWP.h"
#include "VictimActor.h"
#include "DrawDebugHelpers.h"
#include "USARAgent.generated.h"

UCLASS()
class PROTOTYPE_API AUSARAgent : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AUSARAgent();

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool isInitialized = false;

	/* FOR DEBUGGING ONLY */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool showDebug;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float speed = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int numNeighbors = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector agentVelocity;	// velocity in local coordinates
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector rawVelocity;	// for debugging only (flockWP + flock vector)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector avoidanceVector;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector searchVector;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector heightVector;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector flockVector;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector flockWPVector;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector wpLoc;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float alignmentFactor = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float cohesionFactor = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float separationFactor = 0;
	
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool statusStuck;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool statusAvoiding;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool statusDirectMove;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool statusReadyToSearch;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool statusActiveSearch;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool statusClimbing;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool statusTraveling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float targetHeight;			// height to maintain
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float heightVariance;		// variance allowed between agent height and target height

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float alignWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float cohWeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float sepWeight;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float agentSpacing;			// how far apart agents should be spaced
	
	UFUNCTION()
		int GetID();
	UFUNCTION()
		void SetID(int id);
	UFUNCTION()
		void AssignToFlock(int flock);

	UFUNCTION()
		TArray<AUSARAgent*> GetNeighbors();

	UFUNCTION()
		FVector GetDirectMoveLoc();
	
	UFUNCTION()
		void SetTargetHeight(float height);
	UFUNCTION()
		void SetHeightVariance(float var);
	
	UFUNCTION()
		void SetAvoidanceVector(FVector rawVector);
	UFUNCTION()
		void SetDirectMoveLoc(FVector loc);
	UFUNCTION()
		void SetSearchVector(FVector rawVector);
	UFUNCTION()
		void SetHeightVector(FVector rawVector);
	UFUNCTION()
		void SetFlockVector(FVector rawVector);
	UFUNCTION()
		void SetFlockWPVector(FVector rawVector);
	UFUNCTION()
		void SetVelocity();								// set new velocity based on component vectors (avoidanceVector, flockVector, flockWPVector)
	virtual FVector GetVelocity() const override;		// get agent velocity in local coordinates (bypasses built-in component velocity because documentation is unclear)

	UFUNCTION()
		void AddFlockWP(FVector wp, bool atEnd = true);	// append waypoint to list of target waypoints
	UFUNCTION()
		void RemoveFlockWP(FVector wp);					// remove waypoint from list of target waypoints
	UFUNCTION()
		bool GetCurrFlockWP(FVector& wp);				// fetch current waypoint

	UFUNCTION()
		void RemoveSearchWP();
	UFUNCTION()
		bool GetSearchWP(FVector& vec);

	UFUNCTION()
		void SetStatusStuck();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
		
	//UPROPERTY()
	//	float yawRate;		// rate at which agent can turn in degrees per second
	
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

	// Timers for behavior modules
	UPROPERTY()
		FTimerHandle timerAvoidTask;
	UPROPERTY()
		FTimerHandle timerSearchTask;
	UPROPERTY()
		FTimerHandle timerSearchExpand;
	UPROPERTY()
		FTimerHandle timerHeightTask;
	UPROPERTY()
		FTimerHandle timerFlockTask;
	UPROPERTY()
		FTimerHandle timerMoveTask;

	UPROPERTY()
        TArray<AUSARAgent*> neighborAgents = TArray<AUSARAgent*>();
	UPROPERTY()
		TArray<AVictimActor*> victimsInRange = TArray<AVictimActor*>();
	UPROPERTY()
		TArray<FVector> flockWPs = TArray<FVector>();
	UPROPERTY()
		TArray<FVector> searchWPs = TArray<FVector>();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector directMoveLoc;
	
	//UPROPERTY()
		TArray<AVictimActor*> detectedVictims = TArray<AVictimActor*>();

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
		void OnReachWP(UPrimitiveComponent* body, AActor* swarmWP, UPrimitiveComponent* wpArea, int32 neighborIndex,
					   bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnDetectHuman(UPrimitiveComponent* agentSensor, AActor* victim, UPrimitiveComponent* humanBody, int32 neighborIndex,
						   bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnUnDetectHuman(UPrimitiveComponent* agentSensor, AActor* victim, UPrimitiveComponent* humanBody, int32 neighborIndex);

	UFUNCTION()
		void MoveAgent(float deltaSec);
	//UFUNCTION()
	//	FRotator FaceDirection(FVector dir, float deltaSec);	// Rotate agent on z-axis to face specified direction.

	UFUNCTION()
		bool FlockReadyToSearch();
	//UFUNCTION()
	//	void StartSearchPattern();
	UFUNCTION()
		bool FlockReadyToMove();
	UFUNCTION()
		int CheckDetections();

	/*BEHAVIOR MODULES*/
	void ObstAvoidHandle();
	void ActiveSearchHandle();
	void MaintainHeightHandle();
	void FlockHandle();
	void MoveToWPHandle();

	// obstacle avoidance behavior
	void ObstAvoidTask();
	TArray<FVector> LookAhead(FVector vel, bool& obstructed);
	bool CheckVector(FVector vector);
	bool FindClearVector(FVector& targetVec, int fidelity);
	FVector TransformToWorld(FVector vector);

	// active search behavior
	void ActiveSearchTask();
	void ExpandSearch();

	// height maintenance behavior
	void MaintainHeightTask();

	// flocking behavior
	void FlockTask();
	FVector GetAlignment();			// Get average velocity of neighbor agents
	FVector GetCohesion();			// Get vector pointing to center of mass of neighbor agents
	FVector GetSeparation();		// Calculate vector pointing away from neighbor agents
	FVector CalcNewVector(FVector alignFactor, FVector cohFactor, FVector sepFactor);	// Calculate new vector for agent based on alignment, cohesion, and separation factors

	// move-to-waypoint behavior
	void MoveToWPTask();
	/*BEHAVIOR MODULES*/

private:
	int numSearchRadii;
};