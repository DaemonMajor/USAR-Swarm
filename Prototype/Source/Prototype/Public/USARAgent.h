// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/SphereComponent.h"
#include "USAR_Constants.h"
#include "SwarmWP.h"
#include "VictimActor.h"
#include "GridStruct.h"
#include "DrawDebugHelpers.h"
#include "USARAgent.generated.h"

UCLASS()
class PROTOTYPE_API AUSARAgent : public APawn
{
	GENERATED_BODY()

public:
	AUSARAgent();

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool isInitialized = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int searchBehaviorType;

	/* FOR DEBUGGING ONLY */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool showDebug;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool showFibSphere = false;
		int fibSpherePt = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int numNeighbors = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int flockSize = 1;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float distToWP;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int gridsExplored;
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
		bool statusActiveSearch;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool statusClimbing;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool statusTraveling;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool statusLoitering;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool statusRTB;

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
		TArray<AUSARAgent*> GetNeighbors();

	UFUNCTION()
		FVector GetDirectMoveLoc();
	
	virtual FVector GetVelocity() const override;		// get agent velocity in local coordinates (bypasses built-in component velocity because documentation is unclear)
	UFUNCTION()
		void SetVelocity();								// set new velocity based on component vectors (avoidanceVector, flockVector, flockWPVector)
	
	UFUNCTION()
		void SetBaseStation(FVector stationLoc);
	UFUNCTION()
		void AddFlockWP(FVector wp, bool atEnd = true);	// append waypoint to list of target waypoints
	UFUNCTION()
		void RemoveFlockWP(FVector wp);					// remove waypoint from list of target waypoints
	UFUNCTION()
		void ClearFlockWPs();
	UFUNCTION()
		bool GetCurrFlockWP(FVector& wp);				// fetch current waypoint

	UFUNCTION()
		void SetStatusStuck();

	UFUNCTION()
		void TakeMapData(const TArray<FGridStruct> sharedMap);
	UFUNCTION()
		TSet<FGridStruct> UploadMap();

	UFUNCTION()
		void PowerDown();

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

	UPROPERTY()
        TArray<AUSARAgent*> neighborAgents = TArray<AUSARAgent*>();
	UPROPERTY()
		TArray<AVictimActor*> victimsInRange = TArray<AVictimActor*>();
	UPROPERTY()
		TArray<AVictimActor*> locatedVictims = TArray<AVictimActor*>();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
		int numWPs;
	UPROPERTY()
		TArray<FVector> flockWPs = TArray<FVector>();
	UPROPERTY()
		FVector baseStation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector directMoveLoc;

	TSet<FGridStruct> envMap;
	UPROPERTY()
		TArray<AVictimActor*> detectedVictims = TArray<AVictimActor*>();

	UPROPERTY()
		float bootUpDelay = 1;
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
		void OnDetectHuman(UPrimitiveComponent* agentSensor, AActor* victim, UPrimitiveComponent* humanBody, int32 neighborIndex,
						   bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnUnDetectHuman(UPrimitiveComponent* agentSensor, AActor* victim, UPrimitiveComponent* humanBody, int32 neighborIndex);

	UFUNCTION()
		void MoveAgent(float deltaSec);
	//UFUNCTION()
	//	FRotator FaceDirection(FVector dir, float deltaSec);	// Rotate agent on z-axis to face specified direction.

	
	/***BEHAVIOR MODULES***/
	void ObstAvoidHandle();
	void ActiveSearchHandle();
	void MaintainHeightHandle();
	void FlockHandle();
	void MoveToWPHandle();

	// obstacle avoidance behavior
	FTimerHandle timerAvoidTask;
	void MaintainPersonalSpace(int numPoints);
	void ObstAvoidTask();
	TArray<FVector> LookAhead(FVector vel, bool& obstructed);
	bool CheckVector(FVector vector);
	bool FindClearVector(FVector& targetVec, int fidelity);
	FVector TransformToWorld(FVector vector);

	// survivor detection behavior
	FTimerHandle timerDetectionTask;
	void DetectionTask();
	void ReceiveVictimData(AVictimActor* vic);

	// search behavior
	FTimerHandle timerBBSearchRevolve;
	FTimerHandle timerBBSearchExpand;
	FTimerHandle timerRandWalkSearchStep;
	FTimerHandle timerRWSearch;
	void CheckNeighborsSearch();
	float CalcWaitTime();
	void BBSearch_Revolve(float angle);
	void BBSearch_Expand();
	void MoveToVictim(AVictimActor* vic);
	void RandWalkSearchStep();
	void RandWalkSearch_End();
	int expandingSearch;
	bool investigatingVic;

	// height maintenance behavior
	FTimerHandle timerHeightTask;
	void MaintainHeightTask();

	// flocking behavior
	FTimerHandle timerFlockTask;
	void FlockTask();
	FVector GetAlignment();																// Get average velocity of neighbor agents
	FVector GetCohesion();																// Get vector pointing to center of mass of neighbor agents
	FVector GetSeparation();															// Calculate vector pointing away from neighbor agents
	FVector CalcNewVector(FVector alignFactor, FVector cohFactor, FVector sepFactor);	// Calculate new vector for agent based on alignment, cohesion, and separation factors

	// move-to-waypoint behavior
	FTimerHandle timerMoveTask;
	FTimerHandle timerCheckMoveReady;
	void MoveToWPTask();
	void FollowBestNeighbor();
	void CheckAtWP();
	void FlockReadyToMove();
	
	// update map behavior
	FTimerHandle timerMapUpdate;
	FTimerHandle timerMapShare;
	void UpdateMap();
	void ShareMap();
	FGridStruct* AddGrid(FVector loc, bool occupied);
    
    // statusStuck behavior
    TArray<int> alreadyShared = TArray<int>();
	/***BEHAVIOR MODULES***/

private:
	int numSearchRadii;
};