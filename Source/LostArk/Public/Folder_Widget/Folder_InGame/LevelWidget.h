#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LevelWidget.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API ULevelWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	// Level
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* LevelText;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UProgressBar* ExperienceBar;
	
};
