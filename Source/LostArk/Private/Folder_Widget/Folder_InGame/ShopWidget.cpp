#include "Folder_Widget/Folder_InGame/ShopWidget.h"
#include "Folder_Widget/Folder_InGame/ShopSlotWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Folder_Widget/ExitBTN.h"
#include "GI_LostArk.h"

UShopWidget::UShopWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer), ItemCount(1)
{
	static ConstructorHelpers::FObjectFinder<UDataTable> FindItemTable(TEXT("/Game/DataTable/ItemTable"));
	if (FindItemTable.Succeeded())
	{
		CurTable = FindItemTable.Object;
	}
	SetVisibility(ESlateVisibility::Hidden);
}

void UShopWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ExitShopBTN->Parent.Add(this);
	ExitShopBTN->OnClicked.AddDynamic(ExitShopBTN, &UExitBTN::ExitWidget);
	BuyBTN->OnClicked.AddDynamic(this, &UShopWidget::BuyItem);
	SellBTN->OnClicked.AddDynamic(this, &UShopWidget::SellItem);
	InitShopWidget();

}

void UShopWidget::InitShopWidget()
{
	SetVisibility(ESlateVisibility::Hidden);
	for (auto it : SlotUniform->GetAllChildren())
	{
		it->SetVisibility(ESlateVisibility::Hidden);
	}

	int CurrentPage = 0;

	TArray<FItemInfo*> ItemTableRows;
	if (CurTable)
	{
		CurTable->GetAllRows("",ItemTableRows);
	}
	


	
	for(int i = 0; i < SlotUniform->GetChildrenCount(); i++)
	{
		if (ItemTableRows.IsValidIndex(CurrentPage + i))
		{
			UShopSlotWidget* pSlot = Cast<UShopSlotWidget>(SlotUniform->GetAllChildren()[i]);
			if (pSlot)
			{
				pSlot->SetItem(ItemTableRows[CurrentPage + i]);
				pSlot->SetVisibility(ESlateVisibility::Visible);
			}
		}
	}


	SetVisibility(ESlateVisibility::Visible);
}



void UShopWidget::BuyItem()
{
	UGI_LostArk* pGI = Cast<UGI_LostArk>(GetGameInstance());
	UShopSlotWidget* ShopSlot = Cast<UShopSlotWidget>(SelectedSlot);
	if (!pGI && !ShopSlot)
		return;

	int price = FCString::Atoi(*ShopSlot->Price_Text->GetText().ToString());
	
	switch (ShopSlot->ItemInfo->ItemType)
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


	UE_LOG(LogTemp, Log, TEXT("//SellItem"));
}
