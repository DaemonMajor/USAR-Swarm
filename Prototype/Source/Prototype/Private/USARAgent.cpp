// Fill out your copyright notice in the Description page of Project Settings.


#include "USARAgent.h"
#include "USARAgentController.h"
#include "../PrototypeGameState.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"

// Sets default values
AUSARAgent::AUSARAgent()
{
 	PrimaryActorTick.bCanEverTick = true;

	showDebug = false;

	// all lengths in cm (UE units)
	maxSpeed			= 250;	// 2.5 m/s
	searchSpeed			= 100;
	//yawRate			= 45;
	bodySize			= 25;		// agent body radius
	neighborRadius		= 1500;
	visionRadius		= 500;
	obstacleAvoidDist	= 100;
	
	targetHeight = visionRadius * 0.85;
	heightVariance = targetHeight * 0.05;

	maxSearchHeight			= 500;
	searchRadiusPerAgent	= 350;
	searchRadius			= 0;
	numSearchRadii			= 0;

	alignmentWeight		= 0.1;
	cohesionWeight		= 1.5;
	separationWeight	= 3.5f;

	statusStuck			= false;
	statusAvoiding		= false;
	statusDirectMove	= false;
	statusReadyToSearch	= false;
	statusActiveSearch	= false;
	statusClimbing		= false;
	statusTraveling		= false;

	agentVelocity	= FVector::ZeroVector;
	avoidanceVector = FVector::ZeroVector;
	heightVector	= FVector::ZeroVector;
	flockVector		= FVector::ZeroVector;
	flockWPVector	= FVector::ZeroVector;
	directMoveLoc	= FVector::ZeroVector;

	AIControllerClass = AUSARAgentController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

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
		agentBody->SetRelativeScale3D(FVector(bodySize/50.f, bodySize/50.f, .1));
	}
	
	moveComp = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");

	neighborSphere = CreateDefaultSubobject<USphereComponent>("NeighborSensor");
	neighborSphere->SetupAttachment(RootComponent);
	neighborSphere->SetSphereRadius(neighborRadius);
	neighborSphere->SetSimulatePhysics(false);
	neighborSphere->SetGenerateOverlapEvents(true);
	neighborSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	neighborSphere->SetCollisionObjectType(ECollisionChannel::ECC_Visibility);
	neighborSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	visionSphere = CreateDefaultSubobject<USphereComponent>("VisionSensor");
	visionSphere->SetupAttachment(RootComponent);
	visionSphere->SetSphereRadius(visionRadius);
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

	GetWorld()->GetTimerManager().SetTimer(bootUpDelayTimer, this, &AUSARAgent::BootUpSequence, bootUpDelay, false);
}

void AUSARAgent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearTimer(bootUpDelayTimer);

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
				StartSearchPattern();
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

		if (statusActiveSearch) {
			wpLoc = searchWPs[0];
		}
		else {
			if (flockWPs.Num()) {
				wpLoc = flockWPs[0];
				statusTraveling = true;
			}
			else {
				wpLoc = FVector(NULL, NULL, NULL);
				statusTraveling = false;
			}
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

	// set up neighbor list to update when agents enter/leave neighborRadius
	neighborSphere->OnComponentBeginOverlap.AddDynamic(this, &AUSARAgent::OnNeighborEnter);
	neighborSphere->OnComponentEndOverlap.AddDynamic(this, &AUSARAgent::OnNeighborLeave);

	// trigger event on reaching a flockWP
	agentBody->OnComponentBeginOverlap.AddDynamic(this, &AUSARAgent::OnReachWP);

	// trigger event on "seeing" a human
	visionSphere->OnComponentBeginOverlap.AddDynamic(this, &AUSARAgent::OnDetectHuman);
	visionSphere->OnComponentEndOverlap.AddDynamic(this, &AUSARAgent::OnUnDetectHuman);

	isInitialized = true;

	/*DEBUGGING*/
	FString bootUpCompleteText = FString::Printf(TEXT("Agent %d boot sequence complete."), agentID);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, bootUpCompleteText, true);
	/*DEBUGGING*/
}

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

	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(), neighborRadius, traceObjectTypes, seekClass, ignoreActors, foundNeighbors);

	// filter by distance and cast to AUSARAgent
	for (AActor* agent : foundNeighbors) {
		float dist = FVector::Distance(GetActorLocation(), agent->GetActorLocation());
		if (dist <= neighborRadius) {
			if (!neighborAgents.Contains(agent)) {
				neighborAgents.Add(Cast<AUSARAgent>(agent));
			}
		}
	}
}

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

void AUSARAgent::OnReachWP(UPrimitiveComponent* body, AActor* swarmWP, UPrimitiveComponent* wpArea, int32 neighborIndex,
			   bool bFromSweep, const FHitResult& SweepResult)
{
	bool eventFromBody = !(body->GetName().Compare("AgentBody"));
	bool senseWP = !(wpArea->GetName().Compare("WPArea"));

	if (eventFromBody && senseWP) {
		AUSARAgent* agent = Cast<AUSARAgent>(body->GetOwner());

		if (statusTraveling) {
			agent->statusReadyToSearch	= true;
			agent->statusTraveling		= false;
		}

		/*DEBUGGING*/
		//FString reachedWPText = FString::Printf(TEXT("Agent %d reached waypoint."), agentID);
		//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, reachedWPText, true);
		/*DEBUGGING*/
	}
}

void AUSARAgent::OnDetectHuman(UPrimitiveComponent* agentSensor, AActor* victim, UPrimitiveComponent* humanBody, int32 neighborIndex,
							   bool bFromSweep, const FHitResult& SweepResult)
{
	bool eventFromSensor = !(agentSensor->GetName().Compare("VisionSensor"));
	bool senseVictim = victim->IsA(AVictimActor::StaticClass());

	if (eventFromSensor && senseVictim) {
		victimsInRange.AddUnique(Cast<AVictimActor>(victim));
	}
}

void AUSARAgent::OnUnDetectHuman(UPrimitiveComponent* agentSensor, AActor* victim, UPrimitiveComponent* humanBody, int32 neighborIndex)
{
	bool eventFromSensor = !(agentSensor->GetName().Compare("VisionSensor"));
	bool senseVictim = victim->IsA(AVictimActor::StaticClass());

	if (eventFromSensor && senseVictim) {
		victimsInRange.Remove(Cast<AVictimActor>(victim));
	}
}

int AUSARAgent::GetID()
{
	return agentID;
}

void AUSARAgent::SetID(int id)
{
	agentID = id;
}

TArray<AUSARAgent*> AUSARAgent::GetNeighbors()
{
	return neighborAgents;
}

bool AUSARAgent::GetCurrFlockWP(FVector& wp)
{
	if (flockWPs.Num()) {
		wp = flockWPs[0];

		return true;
	}

	return false;
}

FVector AUSARAgent::GetVelocity() const
{
	return agentVelocity;
}

void AUSARAgent::SetVelocity()
{
	if (statusActiveSearch) {
		rawVelocity = searchVector.GetClampedToSize(0, searchSpeed);
	}
	else {
		rawVelocity = (flockVector + flockWPVector).GetClampedToSize(0, maxSpeed);
	}

	FVector newVel = FVector::ZeroVector;
	if (statusAvoiding) {
		newVel = avoidanceVector;
	}
	else if (statusDirectMove) {
		newVel = (directMoveLoc - GetActorLocation()).GetSafeNormal();
		
		if (statusActiveSearch) {
			newVel *= searchSpeed;
		}
		else {
			newVel *= maxSpeed;
		}
	}
	else if (statusActiveSearch) {
		newVel = searchVector;
		heightVector = FVector::ZeroVector;
	}
	else if (statusClimbing) {
		newVel = FVector(0, 0, heightVector.Z);
	}
	else {
		newVel = flockVector + flockWPVector;
		heightVector = FVector::ZeroVector;
	}
	
	agentVelocity = newVel.GetClampedToSize(0, maxSpeed);
}

void AUSARAgent::SetAvoidanceVector(FVector rawVector)
{
	avoidanceVector = rawVector;
}

FVector AUSARAgent::GetDirectMoveLoc()
{
	return directMoveLoc;
}

bool AUSARAgent::GetSearchWP(FVector& vec)
{
	if (searchWPs.Num()) {
		vec = searchWPs[0];

		return true;
	}

	return false;
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

/* Pops top search waypoint off the stack.
*
*/
void AUSARAgent::RemoveSearchWP()
{
	searchWPs.RemoveAt(0);
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
}

/* Determines if the flock is ready to enter search behavior by checking if all neighbors' statusReadyToSearch.
*
*/
bool AUSARAgent::FlockReadyToSearch()
{
	bool ready = true;

	for (AUSARAgent* n : neighborAgents) {
		if (!(n->statusReadyToSearch || n->statusActiveSearch)) {
			ready = false;
		}
	}

	return ready;
}

/* Sets waypoints for search pattern based on current waypoint.
*
*/
void AUSARAgent::StartSearchPattern()
{
	// safety in case function triggers with no waypoints
	if (!flockWPs.Num()) {
		return;
	}

	FVector searchCenter = flockWPs[0];
	float maxDist = neighborAgents.Num() * searchRadiusPerAgent;
	float dist;

	bool goodStart = false;
	while (!goodStart) {
		dist = maxDist * FMath::SRand();
		dist = FMath::Clamp(dist, searchRadiusPerAgent, maxDist);

		bool notTooFar = false;
		if (dist < maxDist/2) {
			notTooFar = true;
		}

		if (!statusActiveSearch || (statusActiveSearch && notTooFar)) {
			goodStart = true;
			for (AUSARAgent* n : neighborAgents) {
				if (n->searchRadius > 0) {
					if (abs(n->searchRadius - dist) < searchRadiusPerAgent/2) {
						goodStart = false;
					}
				}
			}
		}
	}

	FVector startVec = FMath::VRand();
	startVec.Z = 0;
	startVec = dist * startVec.GetSafeNormal();
	float searchHeight = FMath::Clamp(FMath::SRand() * maxSearchHeight, targetHeight/2, maxSearchHeight);
	startVec.Z = searchHeight;

	for (int deg = 0; deg < 180; deg += 10) {
		FRotator rot = FRotator(0, deg, 0);
		FVector searchLoc = rot.RotateVector(startVec) + searchCenter;

		searchWPs.Add(searchLoc);
	}

	searchRadius = dist;
	numSearchRadii++;
	statusReadyToSearch = false;
	statusActiveSearch = true;

	if ((numSearchRadii <= 3) && (searchRadius < maxDist * 0.25)) {
		StartSearchPattern();
	}
	else {
		flockWPs.RemoveAt(0);
	}
}

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