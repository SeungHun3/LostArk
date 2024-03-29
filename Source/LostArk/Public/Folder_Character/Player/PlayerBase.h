#pragma once

#include "CoreMinimal.h"
#include "ResourceMgr.h"
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

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	class UNiagaraSystem* CursorFX;

	class APC_Base* OwingController;

	// Rotate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	class IClick* ClickedTarget; // object, npc, ...

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Info)
	EJob Job;

protected:

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;
	// End of APawn interface

public:
	virtual void LeftClicked();
	virtual void RightClicked();
	virtual void Move();
protected:
	virtual void BeginPlay() override;

	virtual void LevelUp();

	// skill interface
	virtual void Skill(ESkill eSkill) override;

	// skill
	virtual void Skill_Base();
	
	// Item
	void UseItem();
	void ChangeWeapon();

public:

	FDelegate_Skill Delegate_Skill_Base;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }


	FORCEINLINE EJob  GetJob() { return Job; }

private:
	void SetCameraMode(bool _IsTop);

	friend UInputSystem;

};
