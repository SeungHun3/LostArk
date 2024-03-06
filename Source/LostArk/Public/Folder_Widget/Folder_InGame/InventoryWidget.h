#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

UCLASS()
class LOSTARK_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UInventoryWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UInventorySlotWidet> SlotClass;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UUniformGridPanel* SlotUniform;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
	class UImage* Uniform_Bg;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UButton* DragBTN;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
	class UExitBTN* ExitBTN;

};
