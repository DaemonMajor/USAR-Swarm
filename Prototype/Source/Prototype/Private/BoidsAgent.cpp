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

	maxSpeed = 250;
	maxTurnRate = 120;
	bodySize = 25;
	neighborRadius = 500;
	visionRadius = 500;
	alignmentWeight = 1;
	cohesionWeight = 5;
	separationWeight = 2.5;

	agentVelocity = FVector::ZeroVector;

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
	}

	agentBody = CreateDefaultSubobject<USphereComponent>("AgentBody");
	agentBody->SetupAttachment(agentMesh);
	agentBody->SetSphereRadius(bodySize);
	agentBody->SetSimulatePhysics(false);
	agentBody->SetGenerateOverlapEvents(true);
	agentBody->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	agentBody->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	agentBody->SetCollisionProfileName(TEXT("AgentCollision"));
	
	moveComp = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");

	neighborSphere = CreateDefaultSubobject<USphereComponent>("NeighborSensor");
	neighborSphere->SetupAttachment(RootComponent);
	neighborSphere->SetSphereRadius(neighborRadius);
	neighborSphere->SetSimulatePhysics(false);
	neighborSphere->SetGenerateOverlapEvents(true);
	neighborSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	neighborSphere->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
}

// Called when the game starts or when spawned
void ABoidsAgent::BeginPlay()
{
	Super::BeginPlay();

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

	MoveAgent(DeltaSeconds);

	/*DEBUGGING*/
	speed = agentVelocity.Size();
	numNeighbors = neighborAgents.Num();
	/*DEBUGGING*/
}

void ABoidsAgent::BootUpSequence()
{
	// initialize neighbor list
	ScanNeighbors();

	// set up neighbor list to update when agents enter/leave neighborRadius
	//neighborSphere->OnComponentBeginOverlap.AddDynamic(this, &ABoidsAgent::OnNeighborEnter);
	//neighborSphere->OnComponentEndOverlap.AddDynamic(this, &ABoidsAgent::OnNeighborLeave);

	/*DEBUGGING*/
	FString bootUpCompleteText = FString::Printf(TEXT("Agent %d boot sequence complete."), agentID);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, bootUpCompleteText, true);
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

FVector ABoidsAgent::GetVelocity() const
{
	return agentVelocity;
}

void ABoidsAgent::SetVelocity(FVector newVel)
{
	agentVelocity = newVel.GetClampedToSize(0, maxSpeed);
}

void ABoidsAgent::MoveAgent(float deltaSec)
{
	AddActorLocalOffset(agentVelocity * deltaSec, true);
}