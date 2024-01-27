#include "Folder_Widget/Folder_InGame/ShopSlotWidget.h"
#include "Components/Image.h"

UShopSlotWidget::UShopSlotWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer), ItemType(EItemType::NONE)
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UShopSlotWidget::NativeConstruct()
{
	Super::NativeConstruct();


}

void UShopSlotWidget::SetItem()
{
}
