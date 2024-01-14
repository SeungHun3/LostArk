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
	class APlayerBase* OwnedPlayer;
	class AController* PC;

public:
	UInputSystem();

	
	// Action Event
	void Jump();
	void StopJumping();

};
