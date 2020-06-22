// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PrototypeCharacter.generated.h"

class UInputComponent;

UCLASS(config=Game)
class APrototypeCharacter : public ACharacter
{
	GENERATED_BODY()

	// Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess=true))
	class UCameraComponent* charCameraComp;

public:
	APrototypeCharacter();

	FORCEINLINE class UCameraComponent* getFirstPersonCameraComponent() const { return charCameraComp; };

protected:
	virtual void BeginPlay();
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	float moveSpeed = 1;

	void moveForward(float moveVal);	// move forward/backward
	void moveRight(float moveVal);		// move left/right
};

