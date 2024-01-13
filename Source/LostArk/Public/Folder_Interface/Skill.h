// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Skill.generated.h"

UENUM(BlueprintType)
enum class ESkill : uint8
{
	BaseAttack,
	DoubleAttack,

	END,
};

// This class does not need to be modified.
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

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Skill(ESkill _type);

	virtual void BaseAttack() = 0;
	virtual void DoubleAttack() = 0;

};
