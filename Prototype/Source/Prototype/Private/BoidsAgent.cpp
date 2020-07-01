// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidsAgent.h"
#include "BoidsAgentController.h"
#include "../PrototypeGameState.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/ShapeComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ABoidsAgent::ABoidsAgent()
{
 	PrimaryActorTick.bCanEverTick = true;

	// all lengths in cm (UE units)
	maxSpeed = 250;		// 2.5 m/s
	yawRate = 45;
	bodySize = 25;		// agent body radius
	neighborRadius = 1500;
	visionRadius = 500;
	obstacleAvoidDist = 125;

	targetHeight = visionRadius * 0.85;
	heightVariance = targetHeight * 0.05;

	alignmentWeight = 0.5;
	cohesionWeight = 0.5;
	separationWeight = 0.25;

	statusAvoiding = false;
	statusClimbing = false;
	statusTraveling = false;

	agentVelocity = FVector::ZeroVector;
	avoidanceVector = FVector::ZeroVector;
	heightVector = FVector::ZeroVector;
	flockVector = FVector::ZeroVector;
	waypointVector = FVector::ZeroVector;

	AIControllerClass = ABoidsAgentController::StaticClass();
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
void ABoidsAgent::BeginPlay()
{
	Super::BeginPlay();

	/*FOR PREPLACED AGENTS*/
	AssignToFlock(1);

	GetWorld()->GetTimerManager().SetTimer(bootUpDelayTimer, this, &ABoidsAgent::BootUpSequence, bootUpDelay, false);
}

void ABoidsAgent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearTimer(bootUpDelayTimer);

	Super::EndPlay(EndPlayReason);
}

// Called every frame
void ABoidsAgent::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	SetVelocity();
	MoveAgent(DeltaSeconds);

	/*DEBUGGING*/
	speed = agentVelocity.Size();
	numNeighbors = neighborAgents.Num();
	/*DEBUGGING*/
	
	if (waypoints.Num()) {
		wpLoc = waypoints[0]->GetActorLocation();
		statusTraveling = true;
	}
	else {
		wpLoc = FVector(NULL, NULL, NULL);
		statusTraveling = false;
	}
}

void ABoidsAgent::AssignToFlock(int flock)
{
	APrototypeGameState* gameState = GetWorld()->GetGameState<APrototypeGameState>();

	Flock assignedFlock = gameState->AddAgent(this, flock);

	flockID = assignedFlock.flockID;
	waypoints = assignedFlock.waypoints;
}

void ABoidsAgent::BootUpSequence()
{
	// initialize neighbor list
	ScanNeighbors();

	// set up neighbor list to update when agents enter/leave neighborRadius
	neighborSphere->OnComponentBeginOverlap.AddDynamic(this, &ABoidsAgent::OnNeighborEnter);
	neighborSphere->OnComponentEndOverlap.AddDynamic(this, &ABoidsAgent::OnNeighborLeave);

	isInitialized = true;

	/*DEBUGGING*/
	FString bootUpCompleteText = FString::Printf(TEXT("Agent %d boot sequence complete."), agentID);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, bootUpCompleteText, true);
	/*DEBUGGING*/
}

void ABoidsAgent::ScanNeighbors()
{
	// filter by collision channel
	TArray<TEnumAsByte<EObjectTypeQuery>> traceObjectTypes;
	traceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	// ignore specific actors
	TArray<AActor*> ignoreActors;
	ignoreActors.Init(this, 1);		// ignore self

	// filter by class
	UClass* seekClass = ABoidsAgent::StaticClass();

	// list of neighbors found
	TArray<AActor*> foundNeighbors;

	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(), neighborRadius, traceObjectTypes, seekClass, ignoreActors, foundNeighbors);

	// filter by distance and cast to ABoidsAgent
	for (AActor* agent : foundNeighbors) {
		float dist = FVector::Distance(GetActorLocation(), agent->GetActorLocation());
		if (dist <= neighborRadius) {
			if (!neighborAgents.Contains(agent)) {
				neighborAgents.Add(Cast<ABoidsAgent>(agent));
			}
		}
	}
}

void ABoidsAgent::OnNeighborEnter(UPrimitiveComponent* agentSensor, AActor* neighbor, UPrimitiveComponent* neighborBody, int32 neighborIndex,
								  bool bFromSweep, const FHitResult& SweepResult)
{
	bool eventFromSensor = !(agentSensor->GetName().Compare("NeighborSensor"));
	bool senseNeighborBody = !(neighborBody->GetName().Compare("AgentBody"));

	if (eventFromSensor && senseNeighborBody) {
		ABoidsAgent* boid = Cast<ABoidsAgent>(neighbor);

		if (boid && (boid != this)) {
			if (flockID == boid->flockID) {
				if (!neighborAgents.Contains(boid)) {
					neighborAgents.Add(boid);
				}
			}
		}
	}
}

void ABoidsAgent::OnNeighborLeave(UPrimitiveComponent* agentSensor, AActor* neighbor, UPrimitiveComponent* neighborBody, int32 neighborIndex)
{
	bool eventFromSensor = !(agentSensor->GetName().Compare("NeighborSensor"));
	bool senseNeighborBody = !(neighborBody->GetName().Compare("AgentBody"));

	if (eventFromSensor && senseNeighborBody) {
		if (ABoidsAgent* boid = Cast<ABoidsAgent>(neighbor)) {
			if (flockID == boid->flockID) {
				neighborAgents.Remove(boid);
			}
		}
	}
}

int ABoidsAgent::GetID()
{
	return agentID;
}

void ABoidsAgent::SetID(int id)
{
	agentID = id;
}

TArray<ABoidsAgent*> ABoidsAgent::GetNeighbors()
{
	return neighborAgents;
}

ASwarmWP* ABoidsAgent::GetCurrWaypoint()
{
	if (waypoints.Num()) {
		return waypoints[0];
	}

	return nullptr;
}

FVector ABoidsAgent::GetVelocity() const
{
	return agentVelocity;
}

void ABoidsAgent::SetVelocity()
{
	FVector newVel = FVector::ZeroVector;

	if (statusAvoiding) {
		newVel = avoidanceVector;
	}
	else if (statusClimbing) {
		newVel = FVector(0, 0, heightVector.Z);
	}
	else {
		newVel = flockVector + waypointVector;
		heightVector = FVector::ZeroVector;
	}
	
	agentVelocity = newVel.GetClampedToSize(0, maxSpeed);
}

void ABoidsAgent::SetAvoidanceVector(FVector rawVector)
{
	avoidanceVector = rawVector;
}

void ABoidsAgent::SetHeightVector(FVector rawVector)
{
	heightVector = rawVector;
}

void ABoidsAgent::SetFlockVector(FVector rawVector)
{
	flockVector = rawVector;
}

void ABoidsAgent::SetWaypointVector(FVector rawVector)
{
	waypointVector = rawVector;
}

void ABoidsAgent::SetTargetHeight(float height)
{
	targetHeight = height;
}

void ABoidsAgent::SetHeightVariance(float var)
{
	heightVariance = var;
}

void ABoidsAgent::MoveAgent(float deltaSec)
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
FRotator ABoidsAgent::FaceDirection(FVector dir, float deltaSec)
{
	float maxTurn = yawRate * deltaSec;
	float degToTurn = dir.Rotation().Yaw;
	FRotator deltaTurn = FRotator::ZeroRotator;

	if (abs(degToTurn) > maxTurn) {
		if (degToTurn > 0) {
			deltaTurn.Yaw = maxTurn;
		}
		else {
			deltaTurn.Yaw = -maxTurn;
		}
	}
	else {
		deltaTurn.Yaw = degToTurn;
	}

	AddActorLocalRotation(deltaTurn, true);

	return deltaTurn;
}

/* Add a waypoint to the agent's list of target waypoints.
*
*	@param wp Waypoint to add.
*/
void ABoidsAgent::AddWaypoint(ASwarmWP* wp)
{
	waypoints.Add(wp);
}

/* Remove a waypoint from the agent's list of target waypoints.
*
*	@param wp Waypoint to remove.
*/
void ABoidsAgent::RemoveWaypoint(ASwarmWP* wp)
{
	waypoints.Remove(wp);
}