#include "Folder_Widget/Folder_InGame/InGameBarWidget.h"
#include "Folder_Widget/Folder_InGame/DungeonWidget.h"
#include "Components/Button.h"
void UInGameBarWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	DungeonBTN->OnClicked.AddDynamic(this, &UInGameBarWidget::ToggleDungeon);
	ShopBTN->OnClicked.AddDynamic(this, &UInGameBarWidget::ToggleShop);
	CharacterBTN->OnClicked.AddDynamic(this, &UInGameBarWidget::ToggleCharacter);
}

void UInGameBarWidget::ToggleShop()
{
	UE_LOG(LogTemp, Log, TEXT("// ToggleShop"));
}

void UInGameBarWidget::ToggleCharacter()
{
	UE_LOG(LogTemp, Log, TEXT("// ToggleCharacter"));
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