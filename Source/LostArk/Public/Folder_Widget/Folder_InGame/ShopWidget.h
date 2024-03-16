#pragma once

#include "CoreMinimal.h"
#include "GI_LostArk.h"
#include "Blueprint/UserWidget.h"
#include "ShopWidget.generated.h"





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
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
	class UExitBTN* ExitShopBTN;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* OwnGoldText;

	int ItemCount;
	FItemInfo* SelectedItem;
	UDataTable* CurTable;

	void InitShopWidget();

	UFUNCTION()
	void BuyItem();
	UFUNCTION()
	void SellItem();

	void ClickedItem(FItemInfo* iteminfo);
};
