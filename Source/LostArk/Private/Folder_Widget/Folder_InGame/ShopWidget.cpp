#include "Folder_Widget/Folder_InGame/ShopWidget.h"
#include "Folder_Widget/Folder_InGame/ShopSlotWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

#include "GI_LostArk.h"

UShopWidget::UShopWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer), ItemCount(1)
{

}

void UShopWidget::NativeConstruct()
{
	Super::NativeConstruct();
	BuyBTN->OnClicked.AddDynamic(this, &UShopWidget::BuyItem);
	SellBTN->OnClicked.AddDynamic(this, &UShopWidget:: SellItem);

}

void UShopWidget::InitTable(UDataTable* _ItemInfo)
{
	_ItemInfo = CurTable;


	SlotUniform->GetChildrenCount();

	SlotUniform->GetAllChildren();
}

void UShopWidget::BuyItem()
{
	UGI_LostArk* pGI = Cast<UGI_LostArk>(GetGameInstance());
	UShopSlotWidget* ShopSlot = Cast<UShopSlotWidget>(SelectedSlot);
	if (!pGI && !ShopSlot)
		return;

	int price = FCString::Atoi(*ShopSlot->Price_Text->GetText().ToString());
	
	switch (ShopSlot->ItemType)
	{
	case EItemType::Weapon:
		break;

	case EItemType::HP:
		if (pGI)
		{
			pGI->AddHPPortion(ItemCount);
			int ConsumeGold = ItemCount * price * -1;
			pGI->AddGold(ConsumeGold);
		}
		// 플레이어 인벤토리 위젯 변경 => ( 인스턴스 프로퍼티 바인딩으로 예정)

		break;
	case EItemType::MP:
		break;
	default:
		break;
	}
}

void UShopWidget::SellItem()
{


}
