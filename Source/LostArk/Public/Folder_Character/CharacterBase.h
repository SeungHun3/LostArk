#pragma once

#include "CoreMinimal.h"
#include "../Folder_Interface/Skill.h"
#include "ResourceMgr.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"



USTRUCT(BlueprintType)
struct FTotalInfo
{
	GENERATED_BODY()
private:

	int Level;
	int MaxHP;
	int HP;
	int MaxMP; 
	int MP;
	int SP;
	int restAP;

	int Power;
	int Defence;



public:
	int   GetLevel() { return Level; }
	int	  GetMaxHP() { return MaxHP; }
	int	  GetHP() { return HP; }
	int	  GetMaxMP() { return MaxMP; }
	int	  GetMP() { return MP; }
	int	  GetSP() { return SP; }
	int	  GetPower() { return Power; }
	int	  GetDefence() { return Defence; }

	void SetLevel(int _Level) { Level = _Level; }
	void SetmaxHP(int _maxHP) { MaxHP = _maxHP; }
	void SetHP(int _HP) { HP = _HP; }
	void SetmaxMP(int _maxMP) { MaxMP = _maxMP; }
	void SetMP(int _MP) { MP = _MP; }
	void SetSP(int _SP) { SP = _SP; }
	void SetPower(int _Power) { Power = _Power; }
	void SetDefence(int _Defence) { Defence = _Defence; }

	FTotalInfo()
		: Level(1)
		, MaxHP(100), HP(100), MaxMP(100), MP(100), SP(10), restAP(0)
		, Power(10), Defence(3)
	{}

};

UENUM(BlueprintType)
enum class ECharState : uint8
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
	ECharState CharState;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Info)
	FTotalInfo TotalInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Info)
	EJob Job;


	// skill interface
	virtual void Skill_01() override;
	virtual void Skill_02() override;

};
