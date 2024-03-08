#include "Folder_Widget/Folder_InGame/DungeonWidget.h"
//#include "Blueprint/WidgetTree.h"
#include "Components/Button.h"
#include "Folder_Widget/ExitBTN.h"
#include "GI_LostArk.h"
#include "ResourceMgr.h"


void UDungeonWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UE_LOG(LogTemp, Log, TEXT("// UDungeonWidget"));

	EnterBTN->OnClicked.AddDynamic(this, &UDungeonWidget::Enter);
	ExitDungeonBTN->BindWidget(this);
}

void UDungeonWidget::Enter()
{
	UE_LOG(LogTemp, Log, TEXT("// Dungeon Enter"));

	UGI_LostArk* GI = Cast<UGI_LostArk>(GetGameInstance());
	if (GI)
	{
		GI->ChangeLevel(3.f, "Dungeon");
	}
	SetVisibility(ESlateVisibility::Collapsed);
	UUserWidget* CurHUD = GetMainHUD(this);
	if (CurHUD)
	{
		CurHUD->SetVisibility(ESlateVisibility::Collapsed);
	}
}
