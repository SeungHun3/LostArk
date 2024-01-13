// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Folder_Interface/Skill.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

USTRUCT(BlueprintType)
struct FBaseProperty
{
	GENERATED_BODY()
public:
	FBaseProperty()
		: Level(1),HP(100.f), MP(100.f), SP(10)
	{}
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int Level;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float HP;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float MP;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int SP;
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
	// Component

	//Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	//Input
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = InputSystem)
	class UInputSystem* InputSystem;

	

	//////////////////////////////////////////////////
	// Property
	
	// Rotate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	// character base property
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = BaseProperty)
	FBaseProperty Info;

protected:

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;
	// End of APawn interface



	// Move, Rotate
	virtual void MoveForward(float Value);
	virtual void MoveRight(float Value);
	virtual void TurnAtRate(float Rate);
	virtual void LookUpAtRate(float Rate);


	virtual void LevelUp();

	// skill interface
	virtual void BaseAttack() override;
	virtual void DoubleAttack() override;

public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	friend UInputSystem;
};
