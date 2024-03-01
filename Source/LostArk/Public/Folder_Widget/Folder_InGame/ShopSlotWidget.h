// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Folder_Widget/Folder_InGame/ShopWidget.h"
#include "Blueprint/UserWidget.h"
#include "ShopSlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class LOSTARK_API UShopSlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UShopSlotWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	FItemInfo* ItemInfo;
	class UShopWidget* Parent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UImage* Item_Image;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* Item_Name;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* Price_Text;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UButton* SlotBTN;


	void SetItem(UShopWidget* parent, FItemInfo* itemInfo);
	UFUNCTION()
	void ClickedItem();

};
