#include "Folder_Widget/Folder_InGame/InGameBarWidget.h"
#include "Folder_Widget/Folder_InGame/DungeonWidget.h"
#include "Components/Button.h"
void UInGameBarWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	DungeonBTN->OnClicked.AddDynamic(this, &UInGameBarWidget::ToggleDungeon);
	InventoryBTN->OnClicked.AddDynamic(this, &UInGameBarWidget::ToggleInventory);
	CharacterBTN->OnClicked.AddDynamic(this, &UInGameBarWidget::ToggleCharacter);
}

void UInGameBarWidget::ToggleInventory()
{
	UE_LOG(LogTemp, Log, TEXT("// Toggle Inventory"));
}

void UInGameBarWidget::ToggleCharacter()
{
	UE_LOG(LogTemp, Log, TEXT("// Toggle Character"));
}

void UInGameBarWidget::ToggleDungeon()
{
	if (DungeonWidget)
	{
		UUserWidget* ShowWidget = CreateWidget<UUserWidget>(GetWorld(), DungeonWidget);
		if (ShowWidget)
		{
			ShowWidget->AddToViewport();
		}
	}
}
