#include "Folder_Widget/Folder_InGame/InGameBarWidget.h"
#include "Folder_Widget/Folder_InGame/DungeonWidget.h"
#include "Folder_Widget/Folder_InGame/InventoryWidget.h"
#include "Components/Button.h"
void UInGameBarWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	DungeonBTN->OnClicked.AddDynamic(this, &UInGameBarWidget::OpenDungeon);
	InventoryBTN->OnClicked.AddDynamic(this, &UInGameBarWidget::OpenInventory);
	CharacterBTN->OnClicked.AddDynamic(this, &UInGameBarWidget::OpenCharacter);
}

void UInGameBarWidget::OpenInventory()
{
	ShowWidget(InventoryClass);
}

void UInGameBarWidget::OpenCharacter()
{
	UE_LOG(LogTemp, Log, TEXT("// Toggle Character"));
}

void UInGameBarWidget::OpenDungeon()
{
	ShowWidget(DungeonClass);
}

void UInGameBarWidget::ShowWidget(UClass* widget)
{
	if (widget)
	{
		UUserWidget* ShowWidget = CreateWidget<UUserWidget>(GetWorld(), widget);
		if (ShowWidget)
		{
			ShowWidget->AddToViewport();
		}
	}
}
