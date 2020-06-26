// Fill out your copyright notice in the Description page of Project Settings.


#include "SwarmWP.h"
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
	wpArea->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> wpCylinder(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder"));
	if (wpCylinder.Succeeded()) {
		wpArea->SetStaticMesh(wpCylinder.Object);
		wpArea->SetRelativeScale3D(FVector(1, 1, 5.5));	// 1 m diameter, 5.5 m height
		wpArea->SetVisibility(false);
	}
}

// Called when the game starts or when spawned
void ASwarmWP::BeginPlay()
{
	Super::BeginPlay();

	APrototypeGameState* gameState = GetWorld()->GetGameState<APrototypeGameState>();
	wpID = gameState->AddWaypoint(this);	// assign waypoint ID
}

void ASwarmWP::Deactivate()
{
	wpID = -1;
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

void ASwarmWP::OnAgentEnter(UPrimitiveComponent* wpAreaComp, AActor* agent, UPrimitiveComponent* agentBody, int32 agentIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{

}

void ASwarmWP::OnAgentLeave(UPrimitiveComponent* wpAreaComp, AActor* agent, UPrimitiveComponent* agentBody, int32 agentIndex)
{

}