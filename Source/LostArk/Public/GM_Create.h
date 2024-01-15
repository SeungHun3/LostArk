// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GM_Create.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API AGM_Create : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	AGM_Create();

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual void BeginPlay() override;

};
