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
	//yawRate		= 45;
	
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

	expandingSearch = 0;

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
	agentBody->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);		// channel used for waypoints

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

	/*FOR PREPLACED AGENTS*/
	//AssignToFlock(1);

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
		// emit low-power signal
	}
	else {
		CheckDetections();

		if (statusReadyToSearch) {
			if (FlockReadyToSearch()) {
				BeginSearch();
			}
		}
		else if (statusActiveSearch) {
			statusTraveling = FlockReadyToMove();
		}

		SetVelocity();
		MoveAgent(DeltaSeconds);

		speed = agentVelocity.Size();
		numNeighbors = neighborAgents.Num();

		/*DEBUGGING*/
		DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + agentVelocity, 10.f, FColor::Blue, false, 0.01, 0, 2.5);
		DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + rawVelocity, 5.f, FColor::Purple, false, 0.01, 0, 2.5);
		/*DEBUGGING*/

		if (flockWPs.Num()) {

			if (!statusActiveSearch) {
				statusTraveling = true;
			}
		}
		else {
			statusTraveling = false;
		}
	}

	if (showDebug) {
		for (FVector point : searchWPs) {
			DrawDebugPoint(GetWorld(), point, 15, FColor::Blue, false, 0.01);
		}
	}
}

void AUSARAgent::AssignToFlock(int flock)
{
	APrototypeGameState* gameState = GetWorld()->GetGameState<APrototypeGameState>();

	Flock assignedFlock = gameState->AddAgent(this, flock);

	flockID = assignedFlock.flockID;
	for (ASwarmWP* wp : assignedFlock.waypoints) {
		flockWPs.Add(wp->GetActorLocation());
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
	GetWorldTimerManager().SetTimer(timerSearchTask, this, &AUSARAgent::ActiveSearchHandle, RATE_SEARCH_TASK, true);
	GetWorldTimerManager().SetTimer(timerHeightTask, this, &AUSARAgent::MaintainHeightHandle, RATE_HEIGHT_TASK, true);
	GetWorldTimerManager().SetTimer(timerFlockTask, this, &AUSARAgent::FlockHandle, RATE_FLOCK_TASK, true);
	GetWorldTimerManager().SetTimer(timerMoveTask, this, &AUSARAgent::MoveToWPHandle, RATE_WP_TASK, true);

	isInitialized = true;

	/*DEBUGGING*/
	FString bootUpCompleteText = FString::Printf(TEXT("Agent %d boot sequence complete."), agentID);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, bootUpCompleteText, true);
	/*DEBUGGING*/
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

void AUSARAgent::SetAvoidanceVector(FVector rawVector)
{
	avoidanceVector = rawVector;
}

FVector AUSARAgent::GetDirectMoveLoc()
{
	return directMoveLoc;
}

void AUSARAgent::SetDirectMoveLoc(FVector loc)
{
	directMoveLoc = loc;
}

void AUSARAgent::SetSearchVector(FVector rawVector)
{
	searchVector = rawVector;
}

void AUSARAgent::SetHeightVector(FVector rawVector)
{
	heightVector = rawVector;
}

void AUSARAgent::SetFlockVector(FVector rawVector)
{
	flockVector = rawVector;
}

void AUSARAgent::SetFlockWPVector(FVector rawVector)
{
	flockWPVector = rawVector;
}

void AUSARAgent::SetTargetHeight(float height)
{
	targetHeight = height;
}

void AUSARAgent::SetHeightVariance(float var)
{
	heightVariance = var;
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

/* Set agent status to stuck and power down non-vital systems.
*
*/
void AUSARAgent::SetStatusStuck()
{
	statusStuck = true;
	statusAvoiding = false;
	statusDirectMove = false;
	statusClimbing = false;
	statusTraveling = false;

	// clear timer handles for behavior modules
	GetWorldTimerManager().ClearAllTimersForObject(this);
}

/* Determines if the flock is ready to move to the next waypoint as a group.
*
*	@return True if the flock is ready, false if not.
*/
bool AUSARAgent::FlockReadyToMove()
{
	bool ready = true;
	for (AUSARAgent* n : neighborAgents) {
		if (n->statusActiveSearch) {
			ready = false;
		}
	}

	return ready;
}

/* Checks detected actors for victims
*
*	@return The number of victims detected.
*/
int AUSARAgent::CheckDetections()
{
	int numPosIDs = 0;

	FHitResult hitResult;
	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(this);
	FCollisionResponseParams responseParams;

	for (AVictimActor* vic : victimsInRange) {
		if (GetWorld()->LineTraceSingleByChannel(hitResult, GetActorLocation(), vic->GetActorLocation(), ECC_Pawn, queryParams, responseParams)) {
			if (hitResult.GetActor()->IsA(AVictimActor::StaticClass())) {
				numPosIDs++;

				/*DEBUGGING*/
				DrawDebugPoint(GetWorld(), vic->GetActorLocation(), 25, FColor::Emerald, true, 1.f);
				/*DEBUGGING*/
			}
		}
	}

	return numPosIDs;
}