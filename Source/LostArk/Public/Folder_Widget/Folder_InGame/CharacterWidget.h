#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterWidget.generated.h"

UCLASS()
class LOSTARK_API UCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UCanvasPanel* MainCanvas;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UButton* DragBTN;

	FVector2D Mouse_Relative;
	FTimerHandle TimerHandle;

	UFUNCTION()
	void DragPressed();
	UFUNCTION()
	void DragReleased();
	void UpdateMousePosition();
};
