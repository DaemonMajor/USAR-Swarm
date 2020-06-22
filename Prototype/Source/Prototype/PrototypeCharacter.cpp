// Copyright Epic Games, Inc. All Rights Reserved.

#include "PrototypeCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/DecalComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Materials/Material.h"
#include "Engine/World.h"

APrototypeCharacter::APrototypeCharacter()
{
	UCapsuleComponent* charCapsule = GetCapsuleComponent();
	
	// Set size for player capsule
	charCapsule->InitCapsuleSize(50.f, 50.f);
	charCapsule->SetSimulatePhysics(false);

	// Create a camera
	charCameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	charCameraComp->SetupAttachment(GetCapsuleComponent());
	charCameraComp->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
	charCameraComp->bUsePawnControlRotation = true;
	
}

void APrototypeCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APrototypeCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &APrototypeCharacter::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APrototypeCharacter::moveRight);

	// Bind rotation events
	PlayerInputComponent->BindAxis("Yaw", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Pitch", this, &APawn::AddControllerPitchInput);
}

void APrototypeCharacter::moveForward(float moveVal)
{
	if (moveVal != 0.f) {
		AddMovementInput(GetActorForwardVector(), moveVal);
	}
}

void APrototypeCharacter::moveRight(float moveVal)
{
	if (moveVal != 0.f) {
		AddMovementInput(GetActorForwardVector(), moveVal);
	}
}