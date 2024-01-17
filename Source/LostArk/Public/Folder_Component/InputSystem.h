#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "InputSystem.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API UInputSystem : public UInputComponent
{
	GENERATED_BODY()
protected:
	class APlayerBase* OwnedPlayer;
	class AController* PC;

public:
	UInputSystem();

	
	// Action Event
	void Jump();
	void StopJumping();

	// Skill Event;
	UFUNCTION()
	void OnSkillPressed(FKey InKey);
	UFUNCTION()
	void OnSkillReleased(FKey InKey);



};
