#include "Folder_Widget/Folder_InGame/ShopSlotWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
UShopSlotWidget::UShopSlotWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UShopSlotWidget::NativeConstruct()
{
	Super::NativeConstruct();


}

void UShopSlotWidget::SetItem(FItemInfo* _itemInfo)
{
	ItemInfo = _itemInfo;
	UTexture2D* ItemTexture2D = Cast<UTexture2D>(ItemInfo->ItemTexture);
	if (ItemTexture2D)
	{
		Item_Image->SetBrushFromTexture(ItemTexture2D);
	}
	Item_Name->SetText(FText::FromString(ItemInfo->ItemName));
	Price_Text->SetText(FText::FromString(ItemInfo->Price));

}
