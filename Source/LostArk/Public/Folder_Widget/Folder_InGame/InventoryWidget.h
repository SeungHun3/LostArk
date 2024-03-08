#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

UCLASS()
class LOSTARK_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UInventorySlotWidet> SlotClass;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UUniformGridPanel* SlotUniform;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
	class UImage* Uniform_Bg;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UCanvasPanel* InvenCanvas;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UButton* DragBTN;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
	class UExitBTN* ExitInventoryBTN;

	FVector2D Mouse_Relative;

	FTimerHandle TimerHandle;

	UFUNCTION()
	void DragPressed();
	UFUNCTION()
	void DragReleased();
	void UpdateMousePosition();
};
