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
	APC_Base(const FObjectInitializer& ObjectInitializer);
	virtual void OnPossess(APawn* aPawn) override;
	virtual void SetupInputComponent() override;

	class APlayerBase* OwnedPlayer;

	virtual void FadeOut(float time);
	virtual void FadeIn(float time);

};
