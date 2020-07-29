// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"
#include "../PrototypeGameState.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AUSARAgent::AUSARAgent()
{
 	PrimaryActorTick.bCanEverTick = true;

	showDebug = false;

	// all lengths in cm (UE units)
	targetHeight	= MOVE_HEIGHT;
	heightVariance	= targetHeight * 0.05;

	alignWeight		= ALIGNMENT_WEIGHT;
	cohWeight		= COHESION_WEIGHT;
	sepWeight		= SEPARATION_WEIGHT;
	agentSpacing	= AGENT_SPACING;

	statusStuck			= false;
	statusAvoiding		= false;
	statusDirectMove	= false;
	statusReadyToSearch	= false;
	statusActiveSearch	= false;
	statusClimbing		= false;
	statusTraveling		= false;
	statusLoitering		= false;

	expandingSearch = 0;
	gridsExplored	= 0;

	agentVelocity	= FVector::ZeroVector;
	avoidanceVector = FVector::ZeroVector;
	heightVector	= FVector::ZeroVector;
	flockVector		= FVector::ZeroVector;
	flockWPVector	= FVector::ZeroVector;
	directMoveLoc	= FVector::ZeroVector;

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	/*Set up physical body, sensors*/
	agentRoot = CreateDefaultSubobject<UStaticMeshComponent>("AgentRoot");
	SetRootComponent(agentRoot);
	agentRoot->SetSimulatePhysics(false);

	agentBody = CreateDefaultSubobject<UStaticMeshComponent>("AgentBody");
	agentBody->SetupAttachment(RootComponent);
	agentBody->SetSimulatePhysics(false);
	agentBody->SetGenerateOverlapEvents(true);
	agentBody->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	agentBody->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	agentBody->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	agentBody->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> droneVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder"));
	if (droneVisualAsset.Succeeded()) {
		agentBody->SetStaticMesh(droneVisualAsset.Object);
		agentBody->SetRelativeScale3D(FVector(BODY_SIZE/50.f, BODY_SIZE/50.f, .1));
	}
	
	moveComp = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");

	neighborSphere = CreateDefaultSubobject<USphereComponent>("NeighborSensor");
	neighborSphere->SetupAttachment(RootComponent);
	neighborSphere->SetSphereRadius(NEIGHBOR_RADIUS);
	neighborSphere->SetSimulatePhysics(false);
	neighborSphere->SetGenerateOverlapEvents(true);
	neighborSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	neighborSphere->SetCollisionObjectType(ECollisionChannel::ECC_Visibility);
	neighborSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	visionSphere = CreateDefaultSubobject<USphereComponent>("VisionSensor");
	visionSphere->SetupAttachment(RootComponent);
	visionSphere->SetSphereRadius(VISION_RADIUS);
	visionSphere->SetSimulatePhysics(false);
	visionSphere->SetGenerateOverlapEvents(true);
	visionSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	visionSphere->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	visionSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}

// Called when the game starts or when spawned
void AUSARAgent::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(bootUpDelayTimer, this, &AUSARAgent::BootUpSequence, bootUpDelay, false);
}

void AUSARAgent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorldTimerManager().ClearAllTimersForObject(this);

	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AUSARAgent::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (statusStuck) {
		// emit low-power signal, etc
		
		DrawDebugPoint(GetWorld(), GetActorLocation(), 15.f, FColor::Red, false, 0.1f);
	}
	else {
		//CheckDetections();

		SetVelocity();
		MoveAgent(DeltaSeconds);

		numNeighbors = neighborAgents.Num();

		// show direction of movement
		DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + agentVelocity, 10.f, FColor::Blue, false, 0.01, 0, 2.5);
		DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + rawVelocity, 5.f, FColor::Purple, false, 0.01, 0, 2.5);
	}
}

void AUSARAgent::BootUpSequence()
{
	// initialize neighbor list
	ScanNeighbors();

	// set up neighbor list to update when agents enter/leave NEIGHBOR_RADIUS
	neighborSphere->OnComponentBeginOverlap.AddDynamic(this, &AUSARAgent::OnNeighborEnter);
	neighborSphere->OnComponentEndOverlap.AddDynamic(this, &AUSARAgent::OnNeighborLeave);

	// trigger event on "seeing" a human
	visionSphere->OnComponentBeginOverlap.AddDynamic(this, &AUSARAgent::OnDetectHuman);
	visionSphere->OnComponentEndOverlap.AddDynamic(this, &AUSARAgent::OnUnDetectHuman);

	// activate behavior modules
	GetWorldTimerManager().SetTimer(timerAvoidTask, this, &AUSARAgent::ObstAvoidHandle, RATE_AVOID_TASK, true);
	GetWorldTimerManager().SetTimer(timerHeightTask, this, &AUSARAgent::MaintainHeightHandle, RATE_HEIGHT_TASK, true);
	GetWorldTimerManager().SetTimer(timerFlockTask, this, &AUSARAgent::FlockHandle, RATE_FLOCK_TASK, true);
	GetWorldTimerManager().SetTimer(timerCheckMoveReady, this, &AUSARAgent::FlockReadyToMove, 1.f, true);
	GetWorldTimerManager().SetTimer(timerDetectionTask, this, &AUSARAgent::DetectionTask, RATE_IMAGE_SCAN, true);
	GetWorldTimerManager().SetTimer(timerMapUpdate, this, &AUSARAgent::UpdateMap, RATE_MAP_UPDATE, true);
	GetWorldTimerManager().SetTimer(timerMapShare, this, &AUSARAgent::ShareMap, RATE_MAP_SHARE, true);

	isInitialized	= true;
	statusLoitering = true;

	/*DEBUGGING*/
	if (showDebug) {
		FString bootUpCompleteText = FString::Printf(TEXT("Agent %d boot sequence complete."), agentID);
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, bootUpCompleteText, true);
	}
	/*DEBUGGING*/
}

/* Called by control station on simulation end to deactivate the agent.
*/
void AUSARAgent::PowerDown()
{
	GetWorldTimerManager().ClearAllTimersForObject(this);

	flockWPs.Empty();

	statusStuck			= false;
	statusAvoiding		= false;
	statusDirectMove	= false;
	statusReadyToSearch = false;
	statusActiveSearch	= false;
	statusClimbing		= false;
	statusTraveling		= false;
	statusLoitering		= false;
}

/* Add all nearby neighbors to neighbor list. Should be called on agent bootup.
*
*/
void AUSARAgent::ScanNeighbors()
{
	// filter by collision channel
	TArray<TEnumAsByte<EObjectTypeQuery>> traceObjectTypes;
	traceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	// ignore specific actors
	TArray<AActor*> ignoreActors;
	ignoreActors.Init(this, 1);		// ignore self

	// filter by class
	UClass* seekClass = AUSARAgent::StaticClass();

	// list of neighbors found
	TArray<AActor*> foundNeighbors;

	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(), NEIGHBOR_RADIUS, traceObjectTypes, seekClass, ignoreActors, foundNeighbors);

	// filter by distance and cast to AUSARAgent
	for (AActor* agent : foundNeighbors) {
		float dist = FVector::Distance(GetActorLocation(), agent->GetActorLocation());
		if (dist <= NEIGHBOR_RADIUS) {
			if (!neighborAgents.Contains(agent)) {
				neighborAgents.Add(Cast<AUSARAgent>(agent));
			}
		}
	}
}

/* Adds an agent to neighbor list on detection.
*
*/
void AUSARAgent::OnNeighborEnter(UPrimitiveComponent* agentSensor, AActor* neighbor, UPrimitiveComponent* neighborBody, int32 neighborIndex,
								 bool bFromSweep, const FHitResult& SweepResult)
{
	bool eventFromSensor = !(agentSensor->GetName().Compare("NeighborSensor"));
	bool senseNeighborBody = !(neighborBody->GetName().Compare("AgentBody"));

	if (eventFromSensor && senseNeighborBody) {
		AUSARAgent* boid = Cast<AUSARAgent>(neighbor);

		if (boid && (boid != this)) {
			if (flockID == boid->flockID) {
				if (!neighborAgents.Contains(boid)) {
					neighborAgents.Add(boid);
				}
			}
		}
	}
}

/* Removes an agent from neighbor list on detection.
*
*/
void AUSARAgent::OnNeighborLeave(UPrimitiveComponent* agentSensor, AActor* neighbor, UPrimitiveComponent* neighborBody, int32 neighborIndex)
{
	bool eventFromSensor = !(agentSensor->GetName().Compare("NeighborSensor"));
	bool senseNeighborBody = !(neighborBody->GetName().Compare("AgentBody"));

	if (eventFromSensor && senseNeighborBody) {
		if (AUSARAgent* boid = Cast<AUSARAgent>(neighbor)) {
			if (flockID == boid->flockID) {
				neighborAgents.Remove(boid);
			}
		}
	}
}

/* Agent behavior when a victim is detected.
*
*/
void AUSARAgent::OnDetectHuman(UPrimitiveComponent* agentSensor, AActor* victim, UPrimitiveComponent* humanBody, int32 neighborIndex,
							   bool bFromSweep, const FHitResult& SweepResult)
{
	bool eventFromSensor = !(agentSensor->GetName().Compare("VisionSensor"));
	bool senseVictim = victim->IsA(AVictimActor::StaticClass());

	if (eventFromSensor && senseVictim) {
		victimsInRange.AddUnique(Cast<AVictimActor>(victim));
	}
}

/* Agent behavior when a victim leaves the range of agent's sensors.
*
*/
void AUSARAgent::OnUnDetectHuman(UPrimitiveComponent* agentSensor, AActor* victim, UPrimitiveComponent* humanBody, int32 neighborIndex)
{
	bool eventFromSensor = !(agentSensor->GetName().Compare("VisionSensor"));
	bool senseVictim = victim->IsA(AVictimActor::StaticClass());

	if (eventFromSensor && senseVictim) {
		victimsInRange.Remove(Cast<AVictimActor>(victim));
	}
}

/* Retrieves the agent's unique ID.
*
*	@return Unique integer ID.
*/
int AUSARAgent::GetID()
{
	return agentID;
}

/* Sets the agent's unique ID.
*
*	@param id Integer to set the agent's ID to.
*/
void AUSARAgent::SetID(int id)
{
	agentID = id;
}

/* Retrieves the current list of the agent's neighbors.
*
*	@return Array of neighbor agents.
*/
TArray<AUSARAgent*> AUSARAgent::GetNeighbors()
{
	return neighborAgents;
}

/* Retrieves the current waypoint being traveled to.
*
*	@param wp Vector reference to write the waypoint location to.
*	@return True if a waypoint is set, false otherwise.
*/
bool AUSARAgent::GetCurrFlockWP(FVector& wp)
{
	if (flockWPs.Num()) {
		wp = flockWPs[0];

		return true;
	}

	return false;
}

/* Retrieves the agent's current velocity.
*
*	@return Vector denoting the velocity.
*/
FVector AUSARAgent::GetVelocity() const
{
	return agentVelocity;
}

/* Updates the agent's velocity based on current agent status.
*
*/
void AUSARAgent::SetVelocity()
{
	if (statusActiveSearch) {
		rawVelocity = (flockVector.GetClampedToSize(0, SEARCH_SPEED) + searchVector).GetClampedToSize(0, SEARCH_SPEED);
	}
	else {
		rawVelocity = (flockVector + flockWPVector).GetClampedToSize(0, MAX_SPEED);
	}

	if (statusClimbing) {
		rawVelocity.Z = heightVector.Z;
	}

	FVector newVel = rawVelocity;
	if (statusAvoiding) {
		newVel = avoidanceVector;
	}
	else if (statusDirectMove) {
		newVel = (directMoveLoc - GetActorLocation()).GetSafeNormal();
		
		if (statusActiveSearch) {
			newVel *= SEARCH_SPEED;
		}
		else {
			newVel *= MAX_SPEED;
		}
	}
	
	agentVelocity = newVel.GetClampedToSize(0, MAX_SPEED);
}

FVector AUSARAgent::GetDirectMoveLoc()
{
	return directMoveLoc;
}

/* Handles agent movement. Should be called every tick.
*
*	@param deltaSec Time in seconds since last call.
*/
void AUSARAgent::MoveAgent(float deltaSec)
{
	//FRotator turn = FaceDirection(agentVelocity, deltaSec).GetInverse();
	//turn.Yaw = -turn.Yaw;
	//turn.RotateVector(agentVelocity);
	//turn.RotateVector(avoidanceVector);
	//turn.RotateVector(heightVector);
	//turn.RotateVector(flockVector);

	AddActorLocalOffset(agentVelocity * deltaSec, true);
}

/* Rotate agent on z-axis to face specified direction. Rotation limited by agent yawRate.
* 
*	@param dir Local vector to target direction.
*	@param deltaSec Time since last call.
*	@return FRotator agent rotated
*/
//FRotator AUSARAgent::FaceDirection(FVector dir, float deltaSec)
//{
//	float maxTurn = yawRate * deltaSec;
//	float degToTurn = dir.Rotation().Yaw;
//	FRotator deltaTurn = FRotator::ZeroRotator;
//
//	if (abs(degToTurn) > maxTurn) {
//		if (degToTurn > 0) {
//			deltaTurn.Yaw = maxTurn;
//		}
//		else {
//			deltaTurn.Yaw = -maxTurn;
//		}
//	}
//	else {
//		deltaTurn.Yaw = degToTurn;
//	}
//
//	AddActorLocalRotation(deltaTurn, true);
//
//	return deltaTurn;
//}

/* Add a waypoint to the agent's list of target flockWPs.
*
*	@param wp WP to add.
*/
void AUSARAgent::AddFlockWP(FVector wp, bool atEnd)
{
	if (atEnd) {
		flockWPs.Add(wp);
	}
	else {
		flockWPs.Insert(wp, 0);
	}
}

/* Remove a waypoint from the agent's list of target flockWPs.
*
*	@param wp WP to remove.
*/
void AUSARAgent::RemoveFlockWP(FVector wp)
{
	flockWPs.Remove(wp);
}

/* Clear all waypoints from the agent's list of target flockWPs.
*
*/
void AUSARAgent::ClearFlockWPs()
{
	flockWPs.Empty();
}

/* Set agent status to stuck and power down non-vital systems.
*
*/
void AUSARAgent::SetStatusStuck()
{
	statusStuck = true;
	statusAvoiding = false;
	statusDirectMove = false;
	statusActiveSearch = false;
	statusClimbing = false;
	statusTraveling = false;

	// clear timer handles for behavior modules
	GetWorldTimerManager().ClearAllTimersForObject(this);

	/*DEBUGGING*/
	const float gRatio = (sqrt(5.f) + 1.f) / 2.f;   // golden ratio
	const float gAngle = 180 * (3.f - sqrt(5.f));   // golden angle in degrees

	for (int i = 1; i <= FIB_SPHERE_FIDELITY; i++) {
		float azimuth = FMath::Asin(-1.f + 2.f * float(i) / (FIB_SPHERE_FIDELITY + 1));
		float inclination = gAngle * i;

		float z = FMath::Cos(inclination)* FMath::Cos(-azimuth);
		float y = FMath::Sin(inclination) * FMath::Cos(-azimuth);
		float x = FMath::Sin(-azimuth);

		FVector tmpVec = agentVelocity.Rotation().RotateVector(FVector(x, y, z));   // remove this once agent turning is in place
		FVector checkVec = OBSTACLE_AVOID_DIST * tmpVec + GetActorLocation();       // check vectors closest to agent velocity first

		FHitResult hitResult;
		FCollisionQueryParams queryParams;
		queryParams.AddIgnoredActor(this);
		FCollisionResponseParams responseParams;

		if (!GetWorld()->LineTraceSingleByChannel(hitResult, GetActorLocation(), checkVec, ECC_WorldStatic, queryParams, responseParams)) {
			DrawDebugPoint(GetWorld(), checkVec, 1, FColor::Green, true, 300.f);
		}
		else {
			DrawDebugPoint(GetWorld(), hitResult.ImpactPoint, 1, FColor::Red, false, 300.f);
		}
	}

	DrawDebugPoint(GetWorld(), GetActorLocation(), 1, FColor::Yellow, false, 300.f);
	/*DEBUGGING*/
}