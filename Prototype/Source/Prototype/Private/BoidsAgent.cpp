// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidsAgent.h"
#include "BoidsAgentController.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/ShapeComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ABoidsAgent::ABoidsAgent()
{
 	PrimaryActorTick.bCanEverTick = true;

	maxSpeed = 100;
	maxTurnRate = 120;
	bodySize = 25;
	neighborRadius = 1500;
	visionRadius = 500;
	alignmentWeight = 5;
	cohesionWeight = 10;
	separationWeight = 1;

	flockID = 0;

	AIControllerClass = ABoidsAgentController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	agentMesh = CreateDefaultSubobject<UStaticMeshComponent>("AgentRoot");
	SetRootComponent(agentMesh);
	agentMesh->SetSimulatePhysics(false);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> coneVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));
	if (coneVisualAsset.Succeeded()) {
		agentMesh->SetStaticMesh(coneVisualAsset.Object);
		agentMesh->SetRelativeRotation(FRotator(-90, 0, 0));
		agentMesh->SetRelativeScale3D(FVector (0.5 , 0.5 , 0.5));
		agentMesh->SetCollisionProfileName(TEXT("AgentCollision"));
	}

	agentBody = CreateDefaultSubobject<USphereComponent>("AgentBody");
	agentBody->SetupAttachment(agentMesh);
	agentBody->SetSphereRadius(bodySize);
	agentBody->SetSimulatePhysics(false);
	agentBody->SetGenerateOverlapEvents(true);
	
	moveComp = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");

	neighborSphere = CreateDefaultSubobject<USphereComponent>("NeighborSensor");
	neighborSphere->SetupAttachment(RootComponent);
	neighborSphere->SetSphereRadius(neighborRadius);
	neighborSphere->SetSimulatePhysics(false);
	neighborSphere->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ABoidsAgent::BeginPlay()
{
	Super::BeginPlay();

	// initialize neighbor list
	scanNeighbors();

	// set up neighbor list to update when agents enter/leave neighborRadius
	//neighborSphere->OnComponentBeginOverlap.AddDynamic(this, &ABoidsAgent::onNeighborEnter);
	//neighborSphere->OnComponentEndOverlap.AddDynamic(this, &ABoidsAgent::onNeighborLeave);
}

// Called every frame
void ABoidsAgent::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	moveAgent(DeltaSeconds);

	/*DEBUGGING*/
	speed = agentVelocity.Size();
	numNeighbors = neighborAgents.Num();
	/*DEBUGGING*/
}

void ABoidsAgent::scanNeighbors()
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

	// cast to ABoidsAgent
	for (AActor* agent : foundNeighbors) {
		if (!neighborAgents.Contains(agent)) {
			neighborAgents.Add(Cast<ABoidsAgent>(agent));
		}
	}
}

void ABoidsAgent::onNeighborEnter(UPrimitiveComponent* agentSensor, AActor* neighbor, UPrimitiveComponent* neighborBody, int32 neighborIndex,
								  bool bFromSweep, const FHitResult& SweepResult)
{
	bool eventFromSensor = !(agentSensor->GetName().Compare("NeighborSensor"));
	bool senseNeighborBody = !(neighborBody->GetName().Compare("AgentBody"));
	
	if (eventFromSensor && senseNeighborBody) {
		ABoidsAgent* boid = Cast<ABoidsAgent>(neighbor);

		if (boid && (boid != this)) {
			if (flockID == boid->flockID) {
				neighborAgents.Add(boid);
			}
		}
	}
}

void ABoidsAgent::onNeighborLeave(UPrimitiveComponent* agentSensor, AActor* neighbor, UPrimitiveComponent* neighborBody, int32 neighborIndex)
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

TArray<ABoidsAgent*> ABoidsAgent::getNeighbors()
{
	return neighborAgents;
}

FVector ABoidsAgent::GetVelocity() const
{
	return agentVelocity;
}

void ABoidsAgent::setVelocity(FVector newVel)
{
	agentVelocity = newVel.GetClampedToSize(0, maxSpeed);
}

void ABoidsAgent::moveAgent(float deltaSec)
{
	AddActorLocalOffset(agentVelocity * deltaSec, true);
}