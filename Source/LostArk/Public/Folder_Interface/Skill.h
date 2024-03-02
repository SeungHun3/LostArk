// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Skill.generated.h"

UENUM(BlueprintType)
enum class ESkill : uint8
{
	NONE,
	Base,
	Skill_Q,
	Skill_W,

	END,
};

UINTERFACE(MinimalAPI)
class USkill : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LOSTARK_API ISkill
{
	GENERATED_BODY()

public:

	virtual void Skill(ESkill _type) = 0;

};
