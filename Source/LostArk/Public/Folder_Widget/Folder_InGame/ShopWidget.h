#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Blueprint/UserWidget.h"
#include "ShopWidget.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	NONE,
	Weapon,
	HP,
	MP,
};

USTRUCT(BlueprintType)
struct FITemInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UImage* ItemImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Price;
};


UCLASS()
class LOSTARK_API UShopWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UShopWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UUniformGridPanel* SlotUniform;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UButton* BuyBTN;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UButton* SellBTN;

	int ItemCount;
	UUserWidget* SelectedSlot;
	UDataTable* CurTable;

	void InitTable(UDataTable* _ItemInfo);
	void BuyItem();
	void SellItem();

};
