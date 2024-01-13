// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_Base.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API APC_Base : public APlayerController
{
	GENERATED_BODY()
public:

	virtual void OnPossess(APawn* aPawn) override;
	virtual void SetupInputComponent() override;

	class ACharacterBase* OwnedPlayer;

};
