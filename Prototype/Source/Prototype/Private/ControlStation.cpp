// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlStation.h"
#include "SwarmWP.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AControlStation::AControlStation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AControlStation::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(bootUpDelayTimer, this, &AControlStation::InitWaypoints, 1, false);
}

// Called every frame
void AControlStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/* Activate preplaced waypoints.
*/
void AControlStation::InitWaypoints()
{
	TArray<AActor*> preplacedWPs;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASwarmWP::StaticClass(), preplacedWPs);

	// assign all preplaced waypoints to flock 1
	for (AActor* wp : preplacedWPs) {
		Cast<ASwarmWP>(wp)->SetFlock(1);
		Cast<ASwarmWP>(wp)->Init();
	}

	GetWorld()->GetTimerManager().ClearTimer(bootUpDelayTimer);

	/*DEBUGGING*/
	FString initWPText = FString::Printf(TEXT("%d waypoints assigned."), preplacedWPs.Num());
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Green, initWPText, true);
	/*DEBUGGING*/
}