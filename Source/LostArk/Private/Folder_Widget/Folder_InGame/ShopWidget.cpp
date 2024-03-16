#include "Folder_Widget/Folder_InGame/ShopWidget.h"
#include "Folder_Widget/Folder_InGame/ShopSlotWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Folder_Widget/ExitBTN.h"


UShopWidget::UShopWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer), ItemCount(1), SelectedItem(nullptr)
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
	ExitShopBTN->Parent = this;
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
				pSlot->SetItem(this, ItemTableRows[CurrentPage + i]);
				pSlot->SetVisibility(ESlateVisibility::Visible);
			}
		}
	}
	UGI_LostArk* pGI = Cast<UGI_LostArk>(GetGameInstance());
	if (pGI)
	{
		OwnGoldText->SetText(FText::FromString(FString::FromInt(pGI->GetPlayerInfo()->Gold)));
	}


	SetVisibility(ESlateVisibility::Visible);
}



void UShopWidget::BuyItem()
{
	UGI_LostArk* pGI = Cast<UGI_LostArk>(GetGameInstance());
	if (!pGI || !SelectedItem)
		return;

	int price = SelectedItem->Price;
	int ownGold = pGI->GetPlayerInfo()->Gold;

	if (price > ownGold)
		return;

	pGI->AddItem(SelectedItem->SerialNum, 1);
}

void UShopWidget::SellItem()
{


	UE_LOG(LogTemp, Log, TEXT("//SellItem"));
}

void UShopWidget::ClickedItem(FItemInfo* iteminfo)
{
	SelectedItem = iteminfo;
}
