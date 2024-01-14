// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GI_LostArk.generated.h"

UENUM(BlueprintType)
enum class EScene : uint8
{
	NONE,
	Scecne01,
	Scecne02,
	Scecne03,
	Scecne04,

	END,
};


UCLASS()
class LOSTARK_API UGI_LostArk : public UGameInstance
{
	GENERATED_BODY()

public:
	UGI_LostArk();
	virtual void Init() override;

	EScene CurScene = EScene::NONE;
};
