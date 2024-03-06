#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventorySlotWidet.generated.h"

UCLASS()
class LOSTARK_API UInventorySlotWidet : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
	class USizeBox* SizeBox;
};
