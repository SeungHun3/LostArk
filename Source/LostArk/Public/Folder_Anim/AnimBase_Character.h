// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Folder_Character/CharacterBase.h"
#include "AnimBase_Character.generated.h"

UCLASS()
class LOSTARK_API UAnimBase_Character : public UAnimInstance
{
	GENERATED_BODY()

public:
	UAnimBase_Character();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsInAir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	class ACharacterBase* Player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESkill Skill;

	// Skill state
	UFUNCTION()
	void StateBaseAttack();

	UFUNCTION()
	void StateNone();

	UFUNCTION()
	void AnimNotify_BaseAttackEnd();

	void ChangeState(ESkill eSkill);
	ESkill GetAnimState() {		return Skill;	}

	// Executed when begin play is called on the owning component
	virtual void NativeBeginPlay();

	// the below functions are the native overrides for each phase
	// Native initialization override point
	//virtual void NativeInitializeAnimation();

	//// Native update override point. It is usually a good idea to simply gather data in this step and 
	//// for the bulk of the work to be done in NativeThreadSafeUpdateAnimation.
	virtual void NativeUpdateAnimation(float DeltaSeconds);

	//// Native thread safe update override point. Executed on a worker thread just prior to graph update 
	//// for linked anim instances, only called when the hosting node(s) are relevant
	//virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

	//// Native Post Evaluate override point
	//virtual void NativePostEvaluateAnimation();

	//// Native Uninitialize override point
	//virtual void NativeUninitializeAnimation();


};
