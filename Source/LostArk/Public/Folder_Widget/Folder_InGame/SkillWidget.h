#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillWidget.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API USkillWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UImage* Skill_Image;
	float CoolTime = 0.f;
	UMaterialInstanceDynamic* TargetMaterial;

	void SetImage(const FString& _MaterialPath, float _CoolTime);
	void SetSkillPercent(float _Percent);

	UFUNCTION()
	void StartAnim();
	float time = 0.f;
	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate;
};
