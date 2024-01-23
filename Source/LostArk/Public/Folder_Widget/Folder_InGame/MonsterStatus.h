#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MonsterStatus.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API UMonsterStatus : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;

	// Level
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* Name;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UProgressBar* HP_Bar;
	
	void InitWidget(const FString& _Name);
	void SetHP(float _HPPercent);
};
