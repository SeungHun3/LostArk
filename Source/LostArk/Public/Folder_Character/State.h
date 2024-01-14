// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "State.generated.h"


USTRUCT(BlueprintType)
struct FBaseProperty
{
	GENERATED_BODY()
public:
	FString PlayerName;
	int str;
	int dex;
	int intelligence;
	int totalAP;

public:
	FBaseProperty()
		: PlayerName(FString("")), str(0), dex(0), intelligence(0), totalAP(0)
	{

	}

};

UCLASS()
class LOSTARK_API AState : public APlayerState
{
	GENERATED_BODY()

private:
	AState();

	FBaseProperty	BaseProperty;
	

public:

	FBaseProperty GetBaseProperty()	{ return BaseProperty;	}
	void SetBaseProperty(FBaseProperty _BaseProperty)  { _BaseProperty = BaseProperty; }

	void Init(int _Level, FBaseProperty _BaseProperty = FBaseProperty{});


	void Attacked(int _HP);
	void UsedSkill(int _MP, int _SP = 0);

protected:
	virtual void BeginPlay() override;

	// friend class widget* a;
};
