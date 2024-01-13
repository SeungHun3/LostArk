// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "InputSystem.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API UInputSystem : public UInputComponent
{
	GENERATED_BODY()
protected:
	class ACharacterBase* OwnedPlayer;
	class AController* PC;

public:
	UInputSystem();

	
	// Action Event
	void Jump();
	void StopJumping();

	// Axis Event
	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
};
