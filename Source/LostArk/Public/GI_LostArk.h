// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GI_LostArk.generated.h"

UENUM(BlueprintType)
enum class EScene : uint8
{
	NONE,
	Scene01,
	Scene02,
	Scene03,
	Scene04,

	END,
};


UCLASS()
class LOSTARK_API UGI_LostArk : public UGameInstance
{
	GENERATED_BODY()
private:
	EScene currScene;

public:
	UGI_LostArk();

	EScene GetCurrScene() { return currScene; }
	void SetCurrScene(EScene _CurrScene) { currScene = _CurrScene; }

};
