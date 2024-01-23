#pragma once

#include "CoreMinimal.h"
#include "Folder_Character/CharacterBase.h"
#include "PlayerBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegate_Skill);

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

	class APC_Base* OwingController;

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

public:
	virtual void Move();
protected:
	virtual void BeginPlay() override;

	virtual void LevelUp();

	// skill interface
	virtual bool Skill_Base() override;
	virtual bool Skill_Q() override;
	virtual bool Skill_W() override;

public:

	FDelegate_Skill Delegate_Skill_Base, Delegate_Skill_Q, Delegate_Skill_W, Delegate_Skill_E, Delegate_Skill_R;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }


	FORCEINLINE EJob  GetJob() { return Job; }

	//friend UInputSystem;

};
