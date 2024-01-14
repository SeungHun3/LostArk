// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Folder_Interface/Skill.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UENUM(BlueprintType)
enum class EJop : uint8
{
	None,
	Warrior,
	Hunter,
	Magician,

	Monster,
	END,
};

USTRUCT(BlueprintType)
struct FTotalInfo
{
	GENERATED_BODY()
private:

	int level;
	int maxHP;
	int HP;
	int maxMP;
	int MP;
	int SP;
	int restAP;

	int Power;
	int Defence;



public:

	int	  GetmaxHP() { return maxHP; }
	int	  GetHP() { return HP; }
	int	  GetmaxMP() { return maxMP; }
	int	  GetMP() { return MP; }
	int	  GetSP() { return SP; }
	int	  GetPower() { return Power; }
	int	  GetDefence() { return Defence; }


	void SetmaxHP(int _maxHP) { maxHP = _maxHP; }
	void SetHP(int _HP) { HP = _HP; }
	void SetmaxMP(int _maxMP) { maxMP = _maxMP; }
	void SetMP(int _MP) { MP = _MP; }
	void SetSP(int _SP) { SP = _SP; }
	void SetPower(int _Power) { Power = _Power; }
	void SetDefence(int _Defence) { Defence = _Defence; }

	FTotalInfo()
		: level(1)
		, maxHP(100), HP(100), maxMP(100), MP(100), SP(10), restAP(0)
		, Power(10), Defence(3)
	{}

};

UENUM(BlueprintType)
enum class EAnimState : uint8
{
	Idle,
	Run,
	Attack,

	END,
};



UCLASS()
class LOSTARK_API ACharacterBase : public ACharacter, public ISkill
{
	GENERATED_BODY()
public:
	ACharacterBase();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;


	//////////////////////////////////////////////////
	// property
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Info)
	EAnimState animState;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Info)
	FTotalInfo TotalInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Info)
	EJop Jop;


	// skill interface
	virtual void Skill_01() override;
	virtual void Skill_02() override;

};
