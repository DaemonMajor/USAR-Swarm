// Fill out your copyright notice in the Description page of Project Settings.


#include "SwarmWP.h"
#include "USARAgent.h"
#include "../PrototypeGameState.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ShapeComponent.h"

// Sets default values
ASwarmWP::ASwarmWP()
{
 	PrimaryActorTick.bCanEverTick = false;

	wpRoot = CreateDefaultSubobject<UStaticMeshComponent>("WPRoot");
	SetRootComponent(wpRoot);
	wpRoot->SetSimulatePhysics(false);

	wpArea = CreateDefaultSubobject<UStaticMeshComponent>("WPArea");
	wpArea->SetupAttachment(wpRoot);
	wpArea->SetSimulatePhysics(false);
	wpArea->SetGenerateOverlapEvents(true);
	wpArea->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	wpArea->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	wpArea->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	wpArea->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);	// enable overlap events with pawn collision channel
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> wpCylinder(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder"));
	if (wpCylinder.Succeeded()) {
		wpArea->SetStaticMesh(wpCylinder.Object);
		wpArea->SetRelativeScale3D(FVector(25, 25, 15));	// 25 m diameter, 15 m height
		wpArea->SetVisibility(false);
	}
}

// Called when the game starts or when spawned
void ASwarmWP::BeginPlay()
{
	Super::BeginPlay();
}

void ASwarmWP::Init()
{
	if (flockID > 0) {
		APrototypeGameState* gameState = GetWorld()->GetGameState<APrototypeGameState>();
		wpID = gameState->AddWaypoint(this, flockID);	// assign waypoint ID
	}
}

void ASwarmWP::Deactivate()
{
	APrototypeGameState* gameState = GetWorld()->GetGameState<APrototypeGameState>();
	gameState->RemoveWaypoint(this);

	/*DEBUGGING*/
	FString wpDeactivatedText = FString::Printf(TEXT("Waypoint %d deactivated."), wpID);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Red, wpDeactivatedText, true);
	/*DEBUGGING*/

	Destroy();
}

int ASwarmWP::GetID()
{
	return wpID;
}

void ASwarmWP::SetID(int id)
{
	wpID = id;
}

void ASwarmWP::SetFlock(int flock) {
	flockID = flock;
}