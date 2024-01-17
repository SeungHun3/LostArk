// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Folder_Character/CharacterBase.h"
#include "PlayerBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegate_Skill_Q);

UCLASS()
class LOSTARK_API APlayerBase : public ACharacterBase
{
	GENERATED_BODY()
public:
	APlayerBase();
	virtual void ConvertProperty(int _str, int _dex, int _intelligent);
	void Init_Complete(int _str, int _dex, int _intelligent);

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
	//Widget
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = InputSystem)
	class UWidgetSystem* WidgetSystem;



	// Rotate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;


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



	virtual void BeginPlay() override;

	virtual void LevelUp();

	// skill interface
	virtual void Skill_Q() override;
	virtual void Skill_W() override;

public:

	FDelegate_Skill_Q Delegate_Skill_Q;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }


	FORCEINLINE EJob  GetJob() { return Job; }

	friend UInputSystem;

};
